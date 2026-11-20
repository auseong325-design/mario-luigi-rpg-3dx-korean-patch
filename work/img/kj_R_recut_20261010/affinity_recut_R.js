// Fresh ROM extraction. Two visible layers: restoration below exact source.
const {Document,NewDocumentOptions,FileExportOptions,FileExportArea}=require('/document.js');
const {UnitType}=require('/units.js');
const {Bitmap,RasterFormat}=require('/rasterobject.js');
const {PixelReaderRGBA8,PixelReaderWriterRGBA8}=require('/pixelaccessor.js');
const {ImageNodeDefinition}=require('/nodes.js');
const {File}=require('/fs.js');
const DIR='C:/Users/woose/Desktop/ml3dx_kj_affinity/R_recut_20261010/';
const geometry=JSON.parse(File.readAll(DIR+'cutout_geometry.json').toString());
const source=Bitmap.loadFromFile(DIR+'source_R_region.png');
const reader=PixelReaderRGBA8.create(source),pixels=[];
for(let y=0;y<63;y++)for(let x=0;x<60;x++)pixels.push(reader.readPixel(x,y));reader.dispose();
const clamp=v=>Math.max(0,Math.min(255,v));
const rgba=(r,g,b,alpha=255)=>({r:Math.round(clamp(r)),g:Math.round(clamp(g)),b:Math.round(clamp(b)),alpha:Math.round(clamp(alpha))});
function createBitmap(w,h){const bm=Bitmap.create(w,h,RasterFormat.RGBA8);return {bm,w:PixelReaderWriterRGBA8.create(bm)};}
const extracted=createBitmap(60,63),restored=createBitmap(60,63),joined=createBitmap(60,63);
const originalFull=createBitmap(400,208),restoredFull=createBitmap(400,208),final=[];
let originalCount=0,restorationCount=0;
for(let y=0;y<63;y++)for(let x=0;x<60;x++){
  const c=pixels[y*60+x],a=geometry.original_alpha[y][x],b=geometry.restoration_alpha[y][x];
  // Recover dark edge colours from the source's white matte. Opaque original
  // face/rim/counter pixels are copied exactly and sit over the reconstruction.
  const col=a===0?[0,0,0]:a===1?[c.r,c.g,c.b]:[c.r,c.g,c.b].map(v=>clamp((v-255*(1-a))/a));
  const src=rgba(...col,255*a),donor=rgba(...geometry.restoration_rgb[y][x],255*b);
  extracted.w.writePixel(x,y,src);restored.w.writePixel(x,y,donor);
  originalFull.w.writePixel(x+201,y+140,src);restoredFull.w.writePixel(x+201,y+140,donor);
  const sa=src.alpha/255,da=donor.alpha/255,alpha=sa+da*(1-sa);
  const colour=alpha?['r','g','b'].map(k=>(src[k]*sa+donor[k]*da*(1-sa))/alpha):[0,0,0];
  const out=rgba(...colour,alpha*255);joined.w.writePixel(x,y,out);final.push(out);
  if(src.alpha)originalCount++;if(donor.alpha)restorationCount++;
}
for(const v of [extracted,restored,joined,originalFull,restoredFull])v.w.dispose();
function doc(w,h){const o=NewDocumentOptions.createDefault();o.units=UnitType.Pixel;o.width=w;o.height=h;o.dpi=72;o.isTransparentBackground=true;return Document.create(o);}
function add(d,bm,name,visible=true){const n=ImageNodeDefinition.create(RasterFormat.RGBA8);n.bitmap=bm;d.addNode(n,d.currentSpread);const node=[...d.currentSpread.children].at(-1);d.setLayerDescription(name,node);if(!visible)d.setVisible(false,node);return node;}
const png=FileExportOptions.createWithPresetName('PNG'),area=FileExportArea.createForWholeDocument();
function exportBitmap(bm,w,h,name){const d=doc(w,h);add(d,bm,name);d.export(DIR+name+'.png',png,area,null);return d;}
exportBitmap(extracted.bm,60,63,'R_original_cutout');exportBitmap(restored.bm,60,63,'R_restore_underlay');
const layered=doc(60,63);add(layered,source,'일본판 ROM 원본 영역 (참고)',false);
add(layered,restored.bm,'가려진 외곽 복원 / 쿠파군단 R 획 참고 / 아래');
add(layered,extracted.bm,'일본판 ROM 원본 R 누끼 / 면·테·두 다리 그대로 / 위');
layered.export(DIR+'R_clean.png',png,area,null);layered.saveAs(DIR+'R_recut_20261010.af');
const aligned=doc(400,208);add(aligned,restoredFull.bm,'외곽 복원 아래');add(aligned,originalFull.bm,'원본 누끼 위');
aligned.export(DIR+'R_clean_aligned.png',png,area,null);aligned.saveAs(DIR+'R_recut_aligned_20261010.af');
// Actual ROM crop / complete fresh R on white / complete fresh R on blue.
const proof=createBitmap(1140,418);
for(let y=0;y<418;y++)for(let x=0;x<1140;x++){
  const col=Math.floor(x/380),bg=col===2?[42,112,162]:[255,255,255];let out=rgba(...bg);
  const sx=Math.floor((x%380-10)/6),sy=Math.floor((y-20)/6);
  if(sx>=0&&sx<60&&sy>=0&&sy<63){const c=(col===0?pixels:final)[sy*60+sx],a=c.alpha/255;out=rgba(c.r*a+bg[0]*(1-a),c.g*a+bg[1]*(1-a),c.b*a+bg[2]*(1-a));}
  proof.w.writePixel(x,y,out);
}
proof.w.dispose();const review=exportBitmap(proof.bm,1140,418,'R_source_and_recut');
// Transparent reference crop is retained as a separate inspection document.
const reference=Bitmap.loadFromFile(DIR+'reference_1dx.png'),refReader=PixelReaderRGBA8.create(reference),refCrop=createBitmap(98,100);
for(let y=0;y<100;y++)for(let x=0;x<98;x++)refCrop.w.writePixel(x,y,refReader.readPixel(x+85,y+90));
refReader.dispose();refCrop.w.dispose();exportBitmap(refCrop.bm,98,100,'reference_R_crop');
console.log(JSON.stringify({R_document:layered.sessionUuid,aligned_document:aligned.sessionUuid,review_document:review.sessionUuid,
  original_cutout_pixels:originalCount,restoration_underlay_pixels:restorationCount,
  original_visible_face_rim_counter_pixels:geometry.original_visible_face_rim_counter_pixels,
  reference_fit:geometry.reference_fit,source_ROM:geometry.source_ROM},null,2));
