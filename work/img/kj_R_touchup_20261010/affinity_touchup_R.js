// Native Affinity RGBA repair. Extend the face into the remaining left-stem
// gaps and remove the artificial horizontal bright rim from the prior repair.
const { Document, NewDocumentOptions, FileExportOptions, FileExportArea } = require('/document.js');
const { UnitType } = require('/units.js');
const { Bitmap, RasterFormat } = require('/rasterobject.js');
const { PixelReaderRGBA8, PixelReaderWriterRGBA8 } = require('/pixelaccessor.js');
const { ImageNodeDefinition } = require('/nodes.js');
const { File } = require('/fs.js');
const DIR='C:/Users/woose/Desktop/ml3dx_kj_affinity/R_touchup_20261010/';
const field=JSON.parse(File.readAll(DIR+'colour_field.json').toString());
const oldBitmap=Bitmap.loadFromFile(DIR+'before_R.png');
const reader=PixelReaderRGBA8.create(oldBitmap);
const old=[];for(let y=0;y<63;y++)for(let x=0;x<60;x++)old.push(reader.readPixel(x,y));reader.dispose();
const oldAt=(x,y)=>old[(y-140)*60+x-201];
const clamp=v=>Math.max(0,Math.min(255,v));
const rgba=(r,g,b,a=255)=>({r:Math.round(clamp(r)),g:Math.round(clamp(g)),b:Math.round(clamp(b)),alpha:Math.round(clamp(a))});
function inside(x,y,p){let ok=false;for(let i=0,j=p.length-1;i<p.length;j=i++){const a=p[i],b=p[j];if((a[1]>y)!==(b[1]>y)&&x<(b[0]-a[0])*(y-a[1])/(b[1]-a[1])+a[0])ok=!ok;}return ok;}
function smooth(v){v=Math.max(0,Math.min(1,v));return v*v*(3-2*v);}
function dark(c){return Math.max(c.r,c.g,c.b)<140;}
function borderColour(x,y,c){
  if(dark(c))return [c.r,c.g,c.b];
  // Preserve the surrounding original dark rim; never borrow the old pale seam.
  for(let d=1;d<=10;d++){const s=oldAt(Math.max(201,x-d),y);if(s.alpha===255&&dark(s))return [s.r,s.g,s.b];}
  return [72,5,0];
}
const bitmap=Bitmap.create(60,63,RasterFormat.RGBA8),writer=PixelReaderWriterRGBA8.create(bitmap);
const alignedBitmap=Bitmap.create(400,208,RasterFormat.RGBA8),aw=PixelReaderWriterRGBA8.create(alignedBitmap);
const data=[];let changed=0;
for(let ly=0;ly<63;ly++)for(let lx=0;lx<60;lx++){
  const x=lx+201,y=ly+140,c=oldAt(x,y);let out=c;
  // A narrow strip for the upper stem, expanding across the previously patched
  // bottom. The counter and right leg are outside this repair window.
  const right=y<182?219:228;
  if(c.alpha===255&&x>=206&&x<right&&y>=154&&y<=198){
    const bc=borderColour(x,y,c),fc=field.surface_colours[ly][lx];
    let coverage=0;const N=8;
    for(let sy=0;sy<N;sy++)for(let sx=0;sx<N;sx++)if(inside(x+(sx+.5)/N,y+(sy+.5)/N,field.face_contour))coverage++;
    const a=coverage/(N*N),candidate=fc.map((v,i)=>v*a+bc[i]*(1-a));
    const blend=smooth((y-154)/6)*smooth((right-x)/3);
    out=rgba(...candidate.map((v,i)=>[c.r,c.g,c.b][i]*(1-blend)+v*blend),c.alpha);
  }
  if(out.r!==c.r||out.g!==c.g||out.b!==c.b)changed++;
  writer.writePixel(lx,ly,out);aw.writePixel(x,y,out);data.push(out);
}
writer.dispose();aw.dispose();
function document(w,h){const o=NewDocumentOptions.createDefault();o.units=UnitType.Pixel;o.width=w;o.height=h;o.dpi=72;o.isTransparentBackground=true;return Document.create(o);}
function add(doc,bm,name,visible=true){const d=ImageNodeDefinition.create(RasterFormat.RGBA8);d.bitmap=bm;doc.addNode(d,doc.currentSpread);const n=[...doc.currentSpread.children].at(-1);doc.setLayerDescription(name,n);if(!visible)doc.setVisible(false,n);return n;}
const png=FileExportOptions.createWithPresetName('PNG'),area=FileExportArea.createForWholeDocument();
const tight=document(60,63);add(tight,oldBitmap,'직전 R (참고)',false);add(tight,bitmap,'R 빈 부분 채움 / 안쪽 경계 추가 정리 / 면과 결 연결');
tight.export(DIR+'R_clean.png',png,area,null);tight.saveAs(DIR+'R_touchup_20261010.af');
const aligned=document(400,208);add(aligned,alignedBitmap,'수정 R / 원래 좌표');aligned.export(DIR+'R_clean_aligned.png',png,area,null);
const proofBitmap=Bitmap.create(900,300,RasterFormat.RGBA8),pw=PixelReaderWriterRGBA8.create(proofBitmap);
for(let y=0;y<300;y++)for(let x=0;x<900;x++){
  const col=Math.floor(x/300),bx=x%300,bg=col===2?[42,112,162]:[255,255,255];let c=rgba(...bg);
  const sx=Math.floor((bx-30)/4),sy=Math.floor((y-24)/4);
  if(sx>=0&&sx<60&&sy>=0&&sy<63){const src=(col===0?old:data)[sy*60+sx],a=src.alpha/255;c=rgba(src.r*a+bg[0]*(1-a),src.g*a+bg[1]*(1-a),src.b*a+bg[2]*(1-a));}
  pw.writePixel(x,y,c);
}
pw.dispose();const proof=document(900,300);add(proof,proofBitmap,'직전 / 재수정 / 배경 확인');proof.export(DIR+'R_before_after.png',png,area,null);
// Exact native coordinates of the three user examples, enlarged without blur.
const regions=[[209,161,214,186],[210,183,214,190],[214,185,222,195]];
const detailBitmap=Bitmap.create(540,320,RasterFormat.RGBA8),dw=PixelReaderWriterRGBA8.create(detailBitmap);
for(let y=0;y<320;y++)for(let x=0;x<540;x++){
  const col=Math.floor(x/180),part=y<160?old:data,r=regions[col],bx=x%180;
  const sx=Math.floor((bx-30)/10)+r[0],sy=Math.floor((y%160-15)/5)+r[1];let c=rgba(255,255,255);
  if(sx>=r[0]&&sx<r[2]&&sy>=r[1]&&sy<r[3]){const src=part[(sy-140)*60+sx-201],a=src.alpha/255;c=rgba(src.r*a+255*(1-a),src.g*a+255*(1-a),src.b*a+255*(1-a));}
  dw.writePixel(x,y,c);
}
dw.dispose();const details=document(540,320);add(details,detailBitmap,'침범 / 빈 부분 / 이음선 : 위 직전, 아래 수정');details.export(DIR+'R_detail_before_after.png',png,area,null);
console.log(JSON.stringify({tight_document:tight.sessionUuid,aligned_document:aligned.sessionUuid,proof_document:proof.sessionUuid,detail_document:details.sessionUuid,changed_pixels:changed,alpha_identical:true,face_contour:field.face_contour,material:field.material},null,2));
