// Affinity native repair of R's inner face/border. Straight stem and flat bottom
// follow the supplied 1DX R reference; original 3DX gradient and hatch remain.
const { Document, NewDocumentOptions, FileExportOptions, FileExportArea } = require('/document.js');
const { UnitType } = require('/units.js');
const { Bitmap, RasterFormat } = require('/rasterobject.js');
const { PixelReaderRGBA8, PixelReaderWriterRGBA8 } = require('/pixelaccessor.js');
const { ImageNodeDefinition } = require('/nodes.js');
const { File } = require('/fs.js');
const DIR='C:/Users/woose/Desktop/ml3dx_kj_affinity/R_polish_20261010/';
const model=JSON.parse(File.readAll(DIR+'material_fit.json').toString());
const oldBitmap=Bitmap.loadFromFile(DIR+'before_R.png');
const oldReader=PixelReaderRGBA8.create(oldBitmap);
const pixels=[];for(let y=0;y<63;y++)for(let x=0;x<60;x++)pixels.push(oldReader.readPixel(x,y));
oldReader.dispose();
const oldAt=(x,y)=>pixels[(y-140)*60+x-201];
const clamp=v=>Math.max(0,Math.min(255,v));
const rgba=(r,g,b,a=255)=>({r:Math.round(clamp(r)),g:Math.round(clamp(g)),b:Math.round(clamp(b)),alpha:Math.round(clamp(a))});
const face=[[209.0,150.5],[235.4,147.0],[250.6,156.1],[247.5,171.3],
            [238.2,177.7],[253.3,189.1],[236.3,197.4],[223.7,181.0],
            [223.6,193.7],[214.5,193.3]];
function inside(x,y,p){let ok=false;for(let i=0,j=p.length-1;i<p.length;j=i++){const a=p[i],b=p[j];if((a[1]>y)!==(b[1]>y)&&x<(b[0]-a[0])*(y-a[1])/(b[1]-a[1])+a[0])ok=!ok;}return ok;}
function depth(x,y,p){let d=1e9;for(let i=0;i<p.length;i++){const a=p[i],b=p[(i+1)%p.length],dx=b[0]-a[0],dy=b[1]-a[1],t=Math.max(0,Math.min(1,((x-a[0])*dx+(y-a[1])*dy)/(dx*dx+dy*dy)));d=Math.min(d,Math.hypot(x-a[0]-t*dx,y-a[1]-t*dy));}return d;}
function green(c){return c.g>145&&c.g>c.b+65&&c.g>=c.r-35;}
function dark(c){return Math.max(c.r,c.g,c.b)<150;}
function material(x,y){
  const row=model.row_fit[Math.max(0,Math.min(63,Math.round(y)-140))];
  const th=model.hatch_angle*Math.PI/180,ph=2*Math.PI*(x*Math.cos(th)+y*Math.sin(th))/model.hatch_period;
  return row.base.map((c,i)=>clamp(c+row.sin[i]*Math.sin(ph)+row.cos[i]*Math.cos(ph)));
}
function borderColour(x,y,c){
  if(dark(c))return [c.r,c.g,c.b];
  // Keep the original maroon shading from the outer half of this same stem row.
  for(let dx=1;dx<10;dx++){const sx=Math.max(201,x-dx),s=oldAt(sx,y);if(s.alpha>250&&dark(s))return [s.r,s.g,s.b];}
  return [72,5,0];
}
const output=Bitmap.create(60,63,RasterFormat.RGBA8);
const writer=PixelReaderWriterRGBA8.create(output);
const full=Bitmap.create(400,208,RasterFormat.RGBA8),fullWriter=PixelReaderWriterRGBA8.create(full);
let changed=0,restoredFace=0,oldGreenKept=0,alphaEqual=true;
const data=[];
for(let ly=0;ly<63;ly++)for(let lx=0;lx<60;lx++){
  const x=lx+201,y=ly+140,c=oldAt(x,y);let out=c;
  // Only the indicated stem and its bottom corner. Counter, bowl, right leg,
  // outer silhouette and transparent pixels stay byte-identical.
  if(c.alpha===255&&x>=206&&x<=224&&y>=164&&y<=196){
    const bc=borderColour(x,y,c),fc=green(c)?[c.r,c.g,c.b]:material(x+.5,y+.5);
    let sum=[0,0,0],faceCount=0;const N=8;
    for(let sy=0;sy<N;sy++)for(let sx=0;sx<N;sx++){
      const px=x+(sx+.5)/N,py=y+(sy+.5)/N;
      let rgb=bc;
      if(inside(px,py,face)){
        faceCount++;
        // The original slim pale rim is parallel to the corrected face edge.
        const edge=Math.max(0,1-depth(px,py,face)/.65)*.58;
        rgb=fc.map((v,i)=>v*(1-edge)+[244,255,213][i]*edge);
      }
      for(let i=0;i<3;i++)sum[i]+=rgb[i]/(N*N);
    }
    if(faceCount===N*N&&green(c)&&depth(x+.5,y+.5,face)>1.1){out=c;oldGreenKept++;}
    else if(faceCount>0||!dark(c)){
      out=rgba(...sum,255);
      if(faceCount>32&&!green(c))restoredFace++;
    }
  }
  if(out.r!==c.r||out.g!==c.g||out.b!==c.b||out.alpha!==c.alpha)changed++;
  alphaEqual&&=out.alpha===c.alpha;
  writer.writePixel(lx,ly,out);fullWriter.writePixel(x,y,out);data.push(out);
}
writer.dispose();fullWriter.dispose();
function document(w,h){const o=NewDocumentOptions.createDefault();o.units=UnitType.Pixel;o.width=w;o.height=h;o.dpi=72;o.isTransparentBackground=true;return Document.create(o);}
function add(doc,bm,name,visible=true){const d=ImageNodeDefinition.create(RasterFormat.RGBA8);d.bitmap=bm;doc.addNode(d,doc.currentSpread);const n=[...doc.currentSpread.children].at(-1);doc.setLayerDescription(name,n);if(!visible)doc.setVisible(false,n);return n;}
const png=FileExportOptions.createWithPresetName('PNG'),area=FileExportArea.createForWholeDocument();
const tight=document(60,63);add(tight,oldBitmap,'이전 R (참고)',false);add(tight,output,'R 녹색 면과 적갈 테두리 경계 정리');
tight.export(DIR+'R_clean.png',png,area,null);tight.saveAs(DIR+'R_refined_20261010.af');
const aligned=document(400,208);add(aligned,full,'정리한 R / 원래 좌표');aligned.export(DIR+'R_clean_aligned.png',png,area,null);
const proof=Bitmap.create(900,300,RasterFormat.RGBA8),pw=PixelReaderWriterRGBA8.create(proof);
for(let y=0;y<300;y++)for(let x=0;x<900;x++){
  const col=Math.floor(x/300),bx=x%300;
  const bg=col===2?[42,112,162]:[255,255,255];let c=rgba(...bg);
  const sx=Math.floor((bx-30)/4),sy=Math.floor((y-24)/4);
  if(sx>=0&&sx<60&&sy>=0&&sy<63){const src=(col===0?pixels:data)[sy*60+sx],a=src.alpha/255;c=rgba(src.r*a+bg[0]*(1-a),src.g*a+bg[1]*(1-a),src.b*a+bg[2]*(1-a));}
  pw.writePixel(x,y,c);
}
pw.dispose();const review=document(900,300);add(review,proof,'이전 / 수정 / 파란 배경 확인');review.export(DIR+'R_before_after.png',png,area,null);
console.log(JSON.stringify({tight_document:tight.sessionUuid,review_document:review.sessionUuid,aligned_document:aligned.sessionUuid,
  changed_pixels:changed,restored_green_face_pixels:restoredFace,unchanged_good_face_pixels_in_edit_window:oldGreenKept,
  alpha_equal:alphaEqual,edit_bounds:[206,164,224,196],face_contour:face,material_model:'measured original R, row gradient and hatch fit'},null,2));
