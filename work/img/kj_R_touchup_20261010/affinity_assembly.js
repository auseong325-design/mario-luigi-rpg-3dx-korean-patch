// Directly executable Affinity MCP script. Independent raster parts and accepted
// official vector glyphs remain editable. Visible word render includes the exact
// original material model, with no resampling of the small texture.
const { Document, NewDocumentOptions, FileExportOptions, FileExportArea } = require('/document.js');
const { UnitType } = require('/units.js');
const { Bitmap, RasterFormat } = require('/rasterobject.js');
const { ImageNodeDefinition, ContainerNodeDefinition, PolyCurveNodeDefinition } = require('/nodes.js');
const { CurveBuilder, PolyCurve } = require('/geometry.js');
const { FillDescriptor, BlendMode, SolidFill } = require('/fills.js');
const { Colour } = require('/colours.js');
const { LineStyleDescriptor } = require('/linestyle.js');
const { File } = require('/fs.js');
const DIR = 'C:\\Users\\woose\\Desktop\\ml3dx_kj_affinity\\R_touchup_20261010\\assembly\\';
const V = JSON.parse(File.readAll(DIR + 'vectors.json').toString());
const opts = NewDocumentOptions.createDefault();
opts.units = UnitType.Pixel; opts.width = 400; opts.height = 208; opts.dpi = 72;
opts.isTransparentBackground = true;
const doc = Document.create(opts);
const spread = doc.currentSpread;
function addTo(parent, def, name, visible = true) {
  doc.addNode(def, parent);
  const n = [...parent.children].at(-1);
  doc.setLayerDescription(name, n);
  if (!visible) doc.setVisible(false, n);
  return n;
}
function image(file) {
  const d = ImageNodeDefinition.create(RasterFormat.RGBA8);
  d.bitmap = Bitmap.loadFromFile(DIR + file);
  return d;
}
function curve(polys, colour) {
  const pc = PolyCurve.create();
  for (const rings of polys) for (const ring of rings) {
    const b = CurveBuilder.create();
    b.beginXY(ring[0][0], ring[0][1]);
    for (let i = 1; i < ring.length; i++) b.lineToXY(ring[i][0], ring[i][1]);
    b.close(); pc.addCurve(b.createCurve());
  }
  const rgba = Colour.createRGBA8({r:colour[0],g:colour[1],b:colour[2],alpha:255});
  const fill = FillDescriptor.createSolid(SolidFill.create(rgba), BlendMode.Normal);
  return PolyCurveNodeDefinition.create(pc, fill, FillDescriptor.createNone(), LineStyleDescriptor.createDefault(0), FillDescriptor.createNone());
}
addTo(spread, image('original.png'), '일본판 원본 (참고)', false);
addTo(spread, image('before.png'), '클로드 작업본 (참고)', false);
addTo(spread, image('plate.png'), '배경 / P·G / 쿠파주니어 일러스트');
addTo(spread, image('R.png'), '재수정 R / 빈 부분 및 이음선 정리');
addTo(spread, image('wind_top.png'), '위 바람 / 꼬리가 문구 뒤에');
const word = addTo(spread, ContainerNodeDefinition.create('word'), '쿠파주니어 / 18% 균등 확대');
const vectors = addTo(word, ContainerNodeDefinition.create('vectors'), '공식 자형 벡터 / 수정할 때 재질 레이어 숨기기', false);
addTo(vectors, curve(V.rings.maroon,[70,4,0]), '적갈 외곽');
addTo(vectors, curve(V.rings.yellow,[242,236,28]), '노란 외곽');
addTo(vectors, curve(V.rings.white,[255,255,255]), '흰 외곽');
for (const l of V.letters) addTo(vectors, curve(l.polys,[239,82,0]), l.ch);
addTo(word, image('word_render.png'), '기존 재질 / 그라데이션·사선 결·붉은 테');
addTo(spread, image('wind_bottom.png'), '아래 바람 / R 밑');
addTo(spread, image('final.png'), '게임용 RGB565 최종본 (참고)', false);
doc.selection = [];
doc.saveAs(DIR + 'KJ_assembled_R_touchup_20261010.af');
doc.export(DIR + 'affinity_preview.png', FileExportOptions.createWithPresetName('PNG'), FileExportArea.createForWholeDocument(), null);
console.log(JSON.stringify({title:doc.title,uuid:doc.sessionUuid,path:doc.path,dirty:doc.isDirty}));

