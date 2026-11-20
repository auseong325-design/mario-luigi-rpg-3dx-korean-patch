// Affinity (3.3, MCP execute_script) - builds OA_kupajunior_logo.af, the editable copy of the OA안 texture.
// Assets come from `python export_layers.py <DIR>` (Affinity can only read / write under the Desktop).
// Layers, bottom to top: original JP (hidden) / plate (old word erased, left puff moved 9 px down) /
// maroon ring (mitre offset, moved down, vertical gradient dark -> red) / yellow ring / white ring /
// letters group (쿠 파 주 니 어, official glyph vectors, orange gradient) / baked face texture (hatching,
// red rim) / R + right puff in front (original pixels) / final 1x render (hidden).
// 400 x 208 px = LOAD_GAME_IMG_KJ_L_00_JP_ja + _R_ side by side. build_oa.py makes the real texture.
const { Document, NewDocumentOptions } = require('/document.js');
const { UnitType } = require('/units.js');
const { Bitmap, RasterFormat } = require('/rasterobject.js');
const { ImageNodeDefinition, ContainerNodeDefinition, PolyCurveNodeDefinition } = require('/nodes.js');
const { CurveBuilder, PolyCurve, Transform } = require('/geometry.js');
const { FillDescriptor, GradientFill, GradientFillType, BlendMode, SolidFill } = require('/fills.js');
const { Colour, Gradient } = require('/colours.js');
const { LineStyleDescriptor } = require('/linestyle.js');
const { File } = require('/fs.js');

const DIR = 'C:\\Users\\woose\\Desktop\\ml3dx_kj_affinity\\';
const V = JSON.parse(File.readAll(DIR + 'vectors.json').toString());
const opts = NewDocumentOptions.createDefault();
opts.units = UnitType.Pixel; opts.width = 400; opts.height = 208; opts.dpi = 72;
opts.isTransparentBackground = true;
const doc = Document.create(opts);
const spread = doc.currentSpread;

// every node goes to an explicit parent (without one, addNode inserts next to the current selection)
function addTo(parent, def, name, visible = true) {
  doc.addNode(def, parent);
  const kids = [...parent.children];
  const n = kids[kids.length - 1];
  doc.setLayerDescription(name, n);
  if (!visible) doc.setVisible(false, n);
  return n;
}
const img = file => { const d = ImageNodeDefinition.create(RasterFormat.RGBA8); d.bitmap = Bitmap.loadFromFile(DIR + file); return d; };
const rgb = (c, a = 255) => Colour.createRGBA8({ r: Math.round(c[0]), g: Math.round(c[1]), b: Math.round(c[2]), alpha: a });
function polyCurve(polys) {            // all rings of all polygons in one curve set (even-odd fill)
  const pc = PolyCurve.create();
  for (const rings of polys) for (const ring of rings) {
    const b = CurveBuilder.create();
    b.beginXY(ring[0][0], ring[0][1]);
    for (let i = 1; i < ring.length; i++) b.lineToXY(ring[i][0], ring[i][1]);
    b.close();
    pc.addCurve(b.createCurve());
  }
  return pc;
}
function vgrad(stops, y0, y1) {        // linear gradient running down from y0 to y1
  const g = Gradient.create(stops.map(([c, p]) => ({ colour: rgb(c), position: p, midpoint: 0.5 })));
  const tr = Transform.createTranslate(200, y0).multiply(Transform.createRotate(Math.PI / 2)).multiply(Transform.createScale(y1 - y0, y1 - y0));
  return FillDescriptor.create(GradientFill.create(g, GradientFillType.Linear), false, tr, BlendMode.Normal, false);
}
const solid = c => FillDescriptor.createSolid(SolidFill.create(rgb(c)), BlendMode.Normal);
const curve = (polys, fill) => PolyCurveNodeDefinition.create(polyCurve(polys), fill, FillDescriptor.createNone(), LineStyleDescriptor.createDefault(0), FillDescriptor.createNone());
const C = V.colours, M = V.material;
addTo(spread, img('original.png'), '원본 일본어 (참고, 숨김)', false);
addTo(spread, img('plate.png'), '판: 옛 글자 지움 + 왼쪽 연기 9px 아래로');
addTo(spread, curve(V.rings.maroon, vgrad([[C.maroon_up, 0], [C.maroon_side, 0.5], [C.maroon_down, 1]], V.maroon_grad[0], V.maroon_grad[1])),
      `적갈 테 (각진 오프셋 ${M.r_maroon}px, 아래로 ${M.maroon_dy}px)`);
addTo(spread, curve(V.rings.yellow, solid(C.yellow)), `노란 테 (${M.r_yellow}px)`);
addTo(spread, curve(V.rings.white, solid(C.white)), `흰 테 (${M.r_white}px)`);
const letters = addTo(spread, ContainerNodeDefinition.create('글자'), '글자 (공식 쿠파주니어 자형, 벡터)');
const names = { ku: '쿠', pa: '파', ju: '주', ni: '니', eo: '어' };
for (const L of V.letters) addTo(letters, curve(L.polys, vgrad([[C.face_top, 0], [C.face_bottom, 1]], V.face_grad[0], V.face_grad[1])), names[L.id]);
addTo(spread, img('face_texture.png'), '글자 면 질감 (결·붉은 테, build_oa.py 렌더)');
addTo(spread, img('front.png'), 'R과 오른쪽 연기 (앞, 원본 픽셀)');
addTo(spread, img('final.png'), '최종 1배 렌더 (build_oa.py, 숨김)', false);
doc.saveAs(DIR + 'OA_kupajunior_logo.af');
console.log('saved', doc.title, doc.sessionUuid);
