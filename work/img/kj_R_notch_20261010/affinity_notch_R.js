const {Document,NewDocumentOptions,FileExportOptions,FileExportArea}=require('/document.js');
const {UnitType}=require('/units.js');
const {Bitmap,RasterFormat}=require('/rasterobject.js');
const {PixelReaderRGBA8,PixelReaderWriterRGBA8}=require('/pixelaccessor.js');
const {ImageNodeDefinition}=require('/nodes.js');
const {File}=require('/fs.js');
const DIR='C:/Users/woose/Desktop/ml3dx_kj_affinity/R_notch_20261010/';
const field=JSON.parse(File.readAll(DIR+'colour_field.json').toString());
const oldBitmap=Bitmap.loadFromFile(DIR+'before_R.png');
const reader=PixelReaderRGBA8.create(oldBitmap);
const old=[];for(let y=0;y<63;y++)for(let x=0;x<60;x++)old.push(reader.readPixel(x,y));reader.dispose();
const oldAt=(x,y)=>old[(y-140)*60+x-201];
const clamp=v=>Math.max(0,Math.min(255,v));
const rgba=(r,g,b,a=255)=>({r:Math.round(clamp(r)),g:Math.round(clamp(g)),b:Math.round(clamp(b)),alpha:Math.round(clamp(a))});
function inside(x,y,p){let ok=false;for(let i=0,j=p.length-1;i<p.length;j=i++){const a=p[i],b=p[j];if((a[1]>y)!==(b[1]>y)&&x<(b[0]-a[0])*(y-a[1])/(b[1]-a[1])+a[0])ok=!ok;}return ok;}
function depth(x,y,p){let d=1e9;for(let i=0;i<p.length-1;i++){const a=p[i],b=p[i+1],dx=b[0]-a[0],dy=b[1]-a[1],t=Math.max(0,Math.min(1,((x-a[0])*dx+(y-a[1])*dy)/(dx*dx+dy*dy)));d=Math.min(d,Math.hypot(x-a[0]-t*dx,y-a[1]-t*dy));}return d;}
function smooth(v){v=Math.max(0,Math.min(1,v));return v*v*(3-2*v);}
// The top is slightly rounded instead of terminating in isolated bright pixels.
const edge=[[223.9,194.1],[223.7,183.0],[223.7,181.9],[223.85,181.55],[224.15,181.55],[224.5,181.85],[236.3,197.4]];
const face=field.face_contour.slice(0,7).concat(edge.slice().reverse(),[field.face_contour.at(-1)]);
const bitmap=Bitmap.create(60,63,RasterFormat.RGBA8),writer=PixelReaderWriterRGBA8.create(bitmap);
const alignedBitmap=Bitmap.create(400,208,RasterFormat.RGBA8),aw=PixelReaderWriterRGBA8.create(alignedBitmap);
const data=[];let changed=0;
for(let ly=0;ly<63;ly++)for(let lx=0;lx<60;lx++){
  const x=lx+201,y=ly+140,c=oldAt(x,y);let out=c;
  if(c.alpha===255&&x>=221&&x<=235&&y>=179&&y<=194&&depth(x+.5,y+.5,edge)<2.1){
    const fc=field.surface_colours[ly][lx];let sum=[0,0,0];const N=12;
    for(let sy=0;sy<N;sy++)for(let sx=0;sx<N;sx++){
      const px=x+(sx+.5)/N,py=y+(sy+.5)/N,d=depth(px,py,edge);
      let rgb=[65,3,0];
      if(inside(px,py,face)){
        // A continuous narrow pale bevel, matching the undamaged diagonal edge.
        const rim=.65*smooth((.65-d)/.65);
        rgb=fc.map((v,i)=>v*(1-rim)+[230,247,173][i]*rim);
      }
      for(let i=0;i<3;i++)sum[i]+=rgb[i]/(N*N);
    }
    const blend=smooth((2.1-depth(x+.5,y+.5,edge))/.7)*smooth((y-178)/2)*smooth((196-y)/2);
    out=rgba(...sum.map((v,i)=>v*blend+[c.r,c.g,c.b][i]*(1-blend)),255);
  }
  if(out.r!==c.r||out.g!==c.g||out.b!==c.b)changed++;
  writer.writePixel(lx,ly,out);aw.writePixel(x,y,out);data.push(out);
}
writer.dispose();aw.dispose();
function document(w,h){const o=NewDocumentOptions.createDefault();o.units=UnitType.Pixel;o.width=w;o.height=h;o.dpi=72;o.isTransparentBackground=true;return Document.create(o);}
function add(doc,bm,name,visible=true){const d=ImageNodeDefinition.create(RasterFormat.RGBA8);d.bitmap=bm;doc.addNode(d,doc.currentSpread);const n=[...doc.currentSpread.children].at(-1);doc.setLayerDescription(name,n);if(!visible)doc.setVisible(false,n);return n;}
const png=FileExportOptions.createWithPresetName('PNG'),area=FileExportArea.createForWholeDocument();
const tight=document(60,63);add(tight,oldBitmap,'직전 R (참고)',false);add(tight,bitmap,'R 다리 사이 꼭짓점 / 사선 경계 정리');
tight.export(DIR+'R_clean.png',png,area,null);tight.saveAs(DIR+'R_notch_20261010.af');
const aligned=document(400,208);add(aligned,alignedBitmap,'수정 R / 원래 좌표');aligned.export(DIR+'R_clean_aligned.png',png,area,null);
const proofBitmap=Bitmap.create(900,300,RasterFormat.RGBA8),pw=PixelReaderWriterRGBA8.create(proofBitmap);
for(let y=0;y<300;y++)for(let x=0;x<900;x++){
  const col=Math.floor(x/300),bx=x%300,bg=col===2?[42,112,162]:[255,255,255];let c=rgba(...bg);
  const sx=Math.floor((bx-30)/4),sy=Math.floor((y-24)/4);
  if(sx>=0&&sx<60&&sy>=0&&sy<63){const src=(col===0?old:data)[sy*60+sx],a=src.alpha/255;c=rgba(src.r*a+bg[0]*(1-a),src.g*a+bg[1]*(1-a),src.b*a+bg[2]*(1-a));}
  pw.writePixel(x,y,c);
}
pw.dispose();const proof=document(900,300);add(proof,proofBitmap,'직전 / 재수정 / 배경 확인');proof.export(DIR+'R_before_after.png',png,area,null);
console.log(JSON.stringify({tight_document:tight.sessionUuid,aligned_document:aligned.sessionUuid,proof_document:proof.sessionUuid,changed_pixels:changed,alpha_identical:true,face_contour:face,notch_edge:edge,material:field.material},null,2));




