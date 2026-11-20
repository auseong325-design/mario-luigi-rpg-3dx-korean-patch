param([string]$InputBch,[string]$OutputJson)
$ErrorActionPreference='Stop'
[System.Reflection.Assembly]::LoadFrom((Resolve-Path 'tools/SwitchToolbox/SPICA.dll').Path)|Out-Null
$logoScene=[SPICA.Formats.CtrH3D.H3D]::Open([System.IO.File]::ReadAllBytes((Resolve-Path $InputBch).Path))
$logoFrames=@()
foreach($logoAnim in $logoScene.SkeletalAnimations){
  foreach($logoFrame in 0..370){
    $logoBones=@{}
    foreach($logoEl in $logoAnim.Elements){
      $logoValues=@{}
      foreach($logoChannel in @('ScaleX','ScaleY','ScaleZ','RotationX','RotationY','RotationZ','TranslationX','TranslationY','TranslationZ')){
        $logoValues[$logoChannel]=[double]$logoEl.Content.$logoChannel.GetFrameValue([single]$logoFrame)
      }
      $logoBones[$logoEl.Name]=$logoValues
    }
    $logoFrames+=@{frame=$logoFrame;bones=$logoBones}
  }
}
$logoFrames|ConvertTo-Json -Depth 10|Set-Content -LiteralPath $OutputJson -Encoding utf8
