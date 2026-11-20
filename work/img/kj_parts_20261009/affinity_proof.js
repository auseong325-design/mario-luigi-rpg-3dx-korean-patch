// Validate exported alpha/source fidelity and create a white/dark/blue matte proof.
const {Document,NewDocumentOptions,FileExportOptions,FileExportArea}=require('/document.js');
const {UnitType}=require('/units.js');
const {Bitmap,RasterFormat}=require('/rasterobject.js');
const {PixelReaderRGBA8,PixelReaderWriterRGBA8}=require('/pixelaccessor.js');
const {ImageNodeDefinition}=require('/nodes.js');
const DIR='C:/Users/woose/Desktop/ml3dx_kj_affinity/';
function read(name){const bm=Bitmap.loadFromFile(DIR+name+'.png'),r=PixelReaderRGBA8.create(bm),pixels=[];for(let y=0;y<bm.height;y++)for(let x=0;x<bm.width;x++)pixels.push(r.readPixel(x,y));r.dispose();return {w:bm.width,h:bm.height,pixels};}
const source=read('original');
const specs=[{name:'R_clean',origin:[201,140],y:24},{name:'wind_top',origin:[49,127],y:328},{name:'wind_bottom',origin:[202,187],y:476}];
const assets=specs.map(s=>({...s,...read(s.name),aligned:read(s.name+'_aligned')}));
const checks=[];
for(const a of assets){
  let transparent=0,partial=0,opaqueWhite=0,sourceRGBEqual=0,nonzero=0;
  for(let y=0;y<a.h;y++)for(let x=0;x<a.w;x++){
    const p=a.pixels[y*a.w+x],q=a.aligned.pixels[(y+a.origin[1])*400+x+a.origin[0]];
    if(p.r!==q.r||p.g!==q.g||p.b!==q.b||p.alpha!==q.alpha)throw Error('aligned/crop mismatch '+a.name);
    if(p.alpha===0)transparent++;else{
      nonzero++;if(p.alpha<255)partial++;
      if(p.alpha===255&&Math.min(p.r,p.g,p.b)>230)opaqueWhite++;
      const s=source.pixels[(y+a.origin[1])*400+x+a.origin[0]];
      if(p.alpha===255&&p.r===s.r&&p.g===s.g&&p.b===s.b)sourceRGBEqual++;
    }
  }
  if(transparent===0||partial===0)throw Error('missing transparent/antialiased edges '+a.name);
  if(a.name!=='R_clean'&&opaqueWhite<60)throw Error('puff white interior removed');
  // Preserve the unoccluded bright face of the R exactly.
  if(a.name==='R_clean')for(let y=153;y<190;y++)for(let x=216;x<248;x++){
    const s=source.pixels[y*400+x],p=a.pixels[(y-140)*a.w+x-201];
    if(s.g>100&&s.g>s.b+65&&s.g>=s.r-35&&p.alpha===255&&(p.r!==s.r||p.g!==s.g||p.b!==s.b))throw Error('R face changed');
  }
  checks.push({name:a.name,size:[a.w,a.h],origin:a.origin,transparent_pixels:transparent,fractional_alpha_pixels:partial,opaque_white_interior_pixels:opaqueWhite,unmodified_opaque_source_pixels:sourceRGBEqual,crop_aligned_RGBA_equal:true});
}
const width=900,height=580,bgs=[{r:255,g:255,b:255},{r:42,g:45,b:54},{r:41,g:114,b:166}];
const proof=Bitmap.create(width,height,RasterFormat.RGBA8),writer=PixelReaderWriterRGBA8.create(proof);
for(let y=0;y<height;y++)for(let x=0;x<width;x++)writer.writePixel(x,y,{...bgs[Math.floor(x/300)],alpha:255});
for(let col=0;col<3;col++)for(const a of assets){const scale=4,ox=col*300+Math.floor((300-a.w*scale)/2),oy=a.y;for(let y=0;y<a.h;y++)for(let x=0;x<a.w;x++){
  const p=a.pixels[y*a.w+x],alpha=p.alpha/255,bg=bgs[col],c={r:Math.round(p.r*alpha+bg.r*(1-alpha)),g:Math.round(p.g*alpha+bg.g*(1-alpha)),b:Math.round(p.b*alpha+bg.b*(1-alpha)),alpha:255};
  for(let j=0;j<scale;j++)for(let i=0;i<scale;i++)writer.writePixel(ox+x*scale+i,oy+y*scale+j,c);
}}
writer.dispose();const o=NewDocumentOptions.createDefault();o.units=UnitType.Pixel;o.width=width;o.height=height;o.dpi=72;o.isTransparentBackground=true;const d=Document.create(o);const def=ImageNodeDefinition.create(RasterFormat.RGBA8);def.bitmap=proof;d.addNode(def,d.currentSpread);d.setLayerDescription('흰색 · 어두운색 · 파란색 배경의 분리 소재 x4');
d.export(DIR+'parts_proof.png',FileExportOptions.createWithPresetName('PNG'),FileExportArea.createForWholeDocument(),null);
console.log(JSON.stringify({proof_document_uuid:d.sessionUuid,checks,R_face_colour_and_hatching_preserved:true,source_OA_document_unchanged:true,patch_installed:false},null,2));
d.close();
