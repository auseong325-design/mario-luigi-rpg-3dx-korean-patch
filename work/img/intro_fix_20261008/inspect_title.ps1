param(
    [string]$InputBch = 'work/img/intro_fix_20261008/original_title.bch',
    [string]$OutputJson = 'work/img/intro_fix_20261008/model_geometry.json'
)
$ErrorActionPreference = 'Stop'
[System.Reflection.Assembly]::LoadFrom((Resolve-Path 'tools/SwitchToolbox/SPICA.dll').Path) | Out-Null
$introScene = [SPICA.Formats.CtrH3D.H3D]::Open([System.IO.File]::ReadAllBytes((Resolve-Path $InputBch).Path))
function Vec3($v) { return @([double]$v.X,[double]$v.Y,[double]$v.Z) }
function Vec4($v) { return @([double]$v.X,[double]$v.Y,[double]$v.Z,[double]$v.W) }
$introModels = @()
foreach ($introModel in $introScene.Models) {
    $introBones = @()
    foreach ($introBone in $introModel.Skeleton) {
        $introBones += @{name=$introBone.Name;parent=[int]$introBone.ParentIndex;scale=(Vec3 $introBone.Scale);rotation=(Vec3 $introBone.Rotation);translation=(Vec3 $introBone.Translation);inverse=$introBone.InverseTransform}
    }
    $introMeshes = @()
    foreach ($introMesh in $introModel.Meshes) {
        $introVerts = @()
        foreach ($introVert in $introMesh.GetVertices()) {
            $introVerts += @{position=(Vec4 $introVert.Position);uv0=(Vec4 $introVert.TexCoord0);bones=$introVert.Indices;weights=(Vec4 $introVert.Weights)}
        }
        $introSubMeshes = @()
        foreach ($introSubMesh in $introMesh.SubMeshes) { $introSubMeshes += @{indices=$introSubMesh.Indices;bone_indices=$introSubMesh.BoneIndices;skinning=$introSubMesh.Skinning.ToString()} }
        $introMaterial = $introModel.Materials[$introMesh.MaterialIndex]
        $introMeshes += @{material=$introMaterial.Name;material_index=$introMesh.MaterialIndex;texture0=$introMaterial.Texture0Name;texcoords=$introMaterial.MaterialParams.TextureCoords;node=$introMesh.NodeIndex;stride=$introMesh.VertexStride;raw=[Convert]::ToBase64String($introMesh.RawBuffer);vertices=$introVerts;submeshes=$introSubMeshes;attributes=$introMesh.Attributes;position_offset=(Vec4 $introMesh.PositionOffset)}
    }
    $introModels += @{name=$introModel.Name;bones=$introBones;meshes=$introMeshes;world=$introModel.WorldTransform;visibility=$introModel.MeshNodesVisibility}
}
$introData = @{models=$introModels;skeletal_animations=@($introScene.SkeletalAnimations | ForEach-Object { @{name=$_.Name;frames=$_.FramesCount;elements=$_.Elements} });visibility_animations=@($introScene.VisibilityAnimations | ForEach-Object { @{name=$_.Name;frames=$_.FramesCount;elements=$_.Elements} })}
$introData | ConvertTo-Json -Depth 32 | Set-Content -LiteralPath $OutputJson -Encoding utf8
foreach ($introModel in $introModels) {
    Write-Output "MODEL $($introModel.name)"
    $introModel.bones | ForEach-Object { Write-Output "  BONE $($_.name) parent=$($_.parent) scale=$($_.scale) pos=$($_.translation)" }
    $introModel.meshes | ForEach-Object { Write-Output "  MESH $($_.texture0) vertices=$($_.vertices.Count) bones=$($_.submeshes.bone_indices)" }
}
