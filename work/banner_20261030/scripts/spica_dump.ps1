param(
    [string]$InputCgfx,
    [string]$OutputJson
)
# Independent read of a decompressed banner CGFX with SPICA (tools/SwitchToolbox/SPICA.dll):
# models, bones, meshes (vertices: position + uv0), materials (texture names, coordinators),
# textures, and animation element names. Run from the project root (Windows PowerShell 5.1).
$ErrorActionPreference = 'Stop'
[System.Reflection.Assembly]::LoadFrom((Resolve-Path 'tools/SwitchToolbox/SPICA.dll').Path) | Out-Null
$fs = [System.IO.File]::OpenRead((Resolve-Path $InputCgfx).Path)
try { $scene = [SPICA.Formats.CtrGfx.Gfx]::Open($fs) } finally { $fs.Close() }   # returns an H3D scene
if ($scene -isnot [SPICA.Formats.CtrH3D.H3D]) { $scene = $scene.ToH3D() }
function V3($v) { return @([math]::Round([double]$v.X, 5), [math]::Round([double]$v.Y, 5), [math]::Round([double]$v.Z, 5)) }
function V4($v) { return @([math]::Round([double]$v.X, 5), [math]::Round([double]$v.Y, 5), [math]::Round([double]$v.Z, 5), [math]::Round([double]$v.W, 5)) }
$models = @()
foreach ($m in $scene.Models) {
    $bones = @()
    foreach ($b in $m.Skeleton) { $bones += @{name = $b.Name; parent = [int]$b.ParentIndex; scale = (V3 $b.Scale); rotation = (V3 $b.Rotation); translation = (V3 $b.Translation) } }
    $mats = @()
    foreach ($mt in $m.Materials) {
        $tcs = @()
        foreach ($tc in $mt.MaterialParams.TextureCoords) { $tcs += @{scale = @([double]$tc.Scale.X, [double]$tc.Scale.Y); rotation = [double]$tc.Rotation; translation = @([double]$tc.Translation.X, [double]$tc.Translation.Y); mapping = $tc.MappingType.ToString(); transform = $tc.TransformType.ToString(); refcam = [int]$tc.ReferenceCameraIndex } }
        $mats += @{name = $mt.Name; tex0 = $mt.Texture0Name; tex1 = $mt.Texture1Name; tex2 = $mt.Texture2Name; texcoords = $tcs; blend = "$($mt.MaterialParams.BlendMode)"; layer = "$($mt.MaterialParams.RenderLayer)" }
    }
    $meshes = @()
    $mi = 0
    foreach ($ms in $m.Meshes) {
        $verts = @()
        foreach ($v in $ms.GetVertices()) { $verts += @{p = (V4 $v.Position); uv0 = (V4 $v.TexCoord0); col = (V4 $v.Color) } }
        $subs = @()
        foreach ($s in $ms.SubMeshes) { $subs += @{indices = @($s.Indices); bones = @($s.BoneIndices); skinning = $s.Skinning.ToString() } }
        $meshes += @{index = $mi; material = $m.Materials[$ms.MaterialIndex].Name; tex0 = $m.Materials[$ms.MaterialIndex].Texture0Name; node = [int]$ms.NodeIndex; layer = [int]$ms.Layer; priority = [int]$ms.Priority; position_offset = (V4 $ms.PositionOffset); vertices = $verts; submeshes = $subs }
        $mi++
    }
    $models += @{name = $m.Name; bones = $bones; materials = $mats; meshes = $meshes }
}
$texs = @()
$sha = [System.Security.Cryptography.SHA256]::Create()
foreach ($t in $scene.Textures) {
    $raw = $t.RawBuffer
    $rh = if ($raw) { ([BitConverter]::ToString($sha.ComputeHash($raw)) -replace '-', '').ToLower() } else { '' }
    $texs += @{name = $t.Name; w = [int]$t.Width; h = [int]$t.Height; fmt = $t.Format.ToString(); raw_len = $(if ($raw) { $raw.Length } else { 0 }); raw_sha256 = $rh }
}
$anims = @()
foreach ($a in $scene.MaterialAnimations) {
    $els = @(); foreach ($e in $a.Elements) { $els += @{name = $e.Name; target = $e.TargetType.ToString(); type = $e.PrimitiveType.ToString() } }
    $anims += @{kind = 'material'; name = $a.Name; frames = [double]$a.FramesCount; loop = $a.AnimationFlags.ToString(); elements = $els }
}
foreach ($a in $scene.SkeletalAnimations) {
    $els = @(); foreach ($e in $a.Elements) { $els += @{name = $e.Name; target = $e.TargetType.ToString(); type = $e.PrimitiveType.ToString() } }
    $anims += @{kind = 'skeletal'; name = $a.Name; frames = [double]$a.FramesCount; loop = $a.AnimationFlags.ToString(); elements = $els }
}
$out = @{models = $models; textures = $texs; animations = $anims }
$out | ConvertTo-Json -Depth 32 | Set-Content -LiteralPath $OutputJson -Encoding utf8
foreach ($m in $models) {
    Write-Output "MODEL $($m.name) bones=$($m.bones.Count) materials=$($m.materials.Count) meshes=$($m.meshes.Count)"
    foreach ($mt in $m.materials) { Write-Output "  MAT $($mt.name) tex0=$($mt.tex0) tex1=$($mt.tex1) blend=$($mt.blend) tc0=$(($mt.texcoords[0] | ConvertTo-Json -Compress))" }
    foreach ($ms in $m.meshes) {
        $xs = $ms.vertices | ForEach-Object { $_.p[0] }; $ys = $ms.vertices | ForEach-Object { $_.p[1] }
        $us = $ms.vertices | ForEach-Object { $_.uv0[0] }; $vs = $ms.vertices | ForEach-Object { $_.uv0[1] }
        Write-Output ("  MESH {0} mat={1} tex0={2} node={3} nv={4} x[{5:N2},{6:N2}] y[{7:N2},{8:N2}] u[{9:N3},{10:N3}] v[{11:N3},{12:N3}] off={13}" -f $ms.index, $ms.material, $ms.tex0, $ms.node, $ms.vertices.Count, ($xs | Measure-Object -Minimum).Minimum, ($xs | Measure-Object -Maximum).Maximum, ($ys | Measure-Object -Minimum).Minimum, ($ys | Measure-Object -Maximum).Maximum, ($us | Measure-Object -Minimum).Minimum, ($us | Measure-Object -Maximum).Maximum, ($vs | Measure-Object -Minimum).Minimum, ($vs | Measure-Object -Maximum).Maximum, ($ms.position_offset -join ','))
    }
}
foreach ($a in $anims) { Write-Output "ANIM $($a.kind) $($a.name) frames=$($a.frames) loop=$($a.loop) elements=$(($a.elements | ForEach-Object { $_.name + ':' + $_.target }) -join ' ')" }
foreach ($t in $texs) { Write-Output "TEX $($t.name) $($t.w)x$($t.h) $($t.fmt) raw=$($t.raw_len) sha256=$($t.raw_sha256)" }
