// Exact source-pixel extraction and small occluded-outline restoration in Affinity.
// Leaves the open OA_kupajunior_logo document unchanged. No game patch is installed.
const { Document, NewDocumentOptions, FileExportOptions, FileExportArea } = require('/document.js');
const { UnitType } = require('/units.js');
const { Bitmap, RasterFormat } = require('/rasterobject.js');
const { PixelReaderRGBA8, PixelReaderWriterRGBA8 } = require('/pixelaccessor.js');
const { ImageNodeDefinition } = require('/nodes.js');
const { File } = require('/fs.js');
const DIR = 'C:/Users/woose/Desktop/ml3dx_kj_affinity/';
const source = Bitmap.loadFromFile(DIR + 'original.png');
const reader = PixelReaderRGBA8.create(source);
const pixels = [];
for (let y = 0; y < 208; y++) for (let x = 0; x < 400; x++) pixels.push(reader.readPixel(x, y));
reader.dispose();
const at = (x, y) => pixels[Math.max(0, Math.min(207, Math.round(y))) * 400 + Math.max(0, Math.min(399, Math.round(x)))];
const rgba = (r, g, b, alpha = 255) => ({ r: Math.round(r), g: Math.round(g), b: Math.round(b), alpha: Math.round(alpha) });
const clamp = v => Math.max(0, Math.min(255, v));

// Traced clean full R silhouette: the stem edge continues through the word overlap,
// and the bottom-left corner continues behind the lower puff.
const R = [[203.0,147.0],[236.0,143.0],[254.6,155.3],[251.0,173.0],
           [241.9,177.0],[259.3,189.1],[235.0,201.4],[226.0,187.5],
           [226.0,197.0],[209.3,198.0]];

// Each cloud retains its visible original lobes. Their previously buried tapered
// tails are closed independently so no lettering/green face comes with the cutout.
const LARGE = [
  ['M',61,132], ['C',64,131.1,65,132.4,66.5,133.3],
  ['C',70.0,132.3,73.3,133.3,74.2,136.1],
  ['C',75.2,138.5,74.8,142.0,72.8,144.3],
  ['L',77.1,150.9], ['L',70.9,147.6],
  ['C',70.0,151.2,67.6,154.7,64.0,154.7],
  ['C',61.0,154.9,59.1,153.7,58.1,152.3],
  ['C',54.2,152.1,51.1,149.5,51.4,145.7],
  ['C',51.5,142.8,53.4,141.0,55.0,139.8],
  ['C',54.1,135.9,56.7,132.0,61.0,132.0]
];
const SMALL = [
  ['M',75.5,130.1], ['C',77.1,130.2,78.0,130.5,79.1,130.0],
  ['C',83.1,128.6,86.6,131.4,86.0,135.0],
  ['C',85.8,136.4,84.8,137.4,84.3,138.0],
  ['C',86.5,140.2,85.7,143.8,82.7,145.0],
  ['L',79.6,145.9], ['L',79.1,151.1], ['L',76.5,147.0],
  ['L',73.0,145.5], ['C',73.5,142.4,73.8,139.8,72.4,137.3],
  ['C',70.3,134.4,71.6,130.0,75.5,130.1]
];
const LOWER = [
  ['M',208.1,189.1], ['C',210.5,188.0,212.1,189.5,213.5,191.4],
  ['C',217.1,191.1,220.5,194.0,220.2,197.4],
  ['C',220.2,199.2,218.9,200.7,217.6,201.6],
  ['C',218.4,204.2,216.5,206.7,213.5,206.8],
  ['C',210.8,206.9,209.6,205.1,209.1,204.1],
  ['C',205.7,204.5,204.0,202.0,204.2,199.5],
  ['C',203.5,196.6,205.2,195.2,207.0,193.9],
  ['L',205.2,190.0], ['L',208.1,189.1]
];

function flatten(commands) {
  const out = []; let last;
  for (const c of commands) {
    if (c[0] === 'M' || c[0] === 'L') { last = [c[1],c[2]]; out.push(last); }
    else {
      const a=last, b=[c[1],c[2]], d=[c[3],c[4]], e=[c[5],c[6]];
      for(let i=1;i<=24;i++){const t=i/24,u=1-t;out.push([u*u*u*a[0]+3*u*u*t*b[0]+3*u*t*t*d[0]+t*t*t*e[0],u*u*u*a[1]+3*u*u*t*b[1]+3*u*t*t*d[1]+t*t*t*e[1]]);}
      last=e;
    }
  }
  return out;
}
const topPolys = [flatten(LARGE), flatten(SMALL)];
const lowerPoly = flatten(LOWER);
function inside(x,y,p) {
  let result=false;
  for(let i=0,j=p.length-1;i<p.length;j=i++){
    const a=p[i],b=p[j];if((a[1]>y)!==(b[1]>y)&&x<(b[0]-a[0])*(y-a[1])/(b[1]-a[1])+a[0])result=!result;
  }
  return result;
}
function coverage(x,y,polys) {
  let count=0;const N=8;
  for(let sy=0;sy<N;sy++)for(let sx=0;sx<N;sx++)if(polys.some(p=>inside(x+(sx+.5)/N,y+(sy+.5)/N,p)))count++;
  return count/(N*N);
}
function edgeDistance(x,y,p){let best=1e9;for(let i=0;i<p.length;i++){const a=p[i],b=p[(i+1)%p.length],dx=b[0]-a[0],dy=b[1]-a[1],t=Math.max(0,Math.min(1,((x-a[0])*dx+(y-a[1])*dy)/(dx*dx+dy*dy||1)));best=Math.min(best,Math.hypot(x-a[0]-t*dx,y-a[1]-t*dy));}return best;}
function dark(c){return Math.max(c.r,c.g,c.b)<150;}
function greenFace(c){return c.g>100&&c.g>c.b+65&&c.g>=c.r-35;}
function nearestDark(x,y,r=5){
  let best=null,score=1e9;
  for(let yy=Math.max(0,y-r);yy<=Math.min(207,y+r);yy++)for(let xx=Math.max(0,x-r);xx<=Math.min(399,x+r);xx++){
    const c=at(xx,yy);if(!dark(c))continue;
    const d=(xx-x)*(xx-x)+1.5*(yy-y)*(yy-y);if(d<score){score=d;best=c;}
  }
  return best||rgba(70,3,0);
}
// Unmatte ONLY fractional boundary pixels. Interior white in the puffs stays opaque.
function unmatted(c,a){if(a>.995)return rgba(c.r,c.g,c.b,255);return rgba(clamp((c.r-255*(1-a))/Math.max(a,.02)),clamp((c.g-255*(1-a))/Math.max(a,.02)),clamp((c.b-255*(1-a))/Math.max(a,.02)),a*255);}
function makeDocument(w,h) {
  const o=NewDocumentOptions.createDefault();o.units=UnitType.Pixel;o.width=w;o.height=h;o.dpi=72;o.isTransparentBackground=true;return Document.create(o);
}
function addImage(doc,bm,name,visible=true) {
  const n=ImageNodeDefinition.create(RasterFormat.RGBA8);n.bitmap=bm;doc.addNode(n,doc.currentSpread);
  const node=[...doc.currentSpread.children].slice(-1)[0];doc.setLayerDescription(name,node);if(!visible)doc.setVisible(false,node);return node;
}
const png=FileExportOptions.createWithPresetName('PNG');
const specs=[
  {name:'R_clean',label:'R 복원 · 문구와 아래 바람 제거',bounds:[201,140,261,203],polys:[R],kind:'R'},
  {name:'wind_top',label:'위쪽 바람 · 흰색 내부 보존',bounds:[49,127,89,157],polys:topPolys,kind:'top'},
  {name:'wind_bottom',label:'아래쪽 바람 · R과 분리',bounds:[202,187,223,208],polys:[lowerPoly],kind:'lower'}
];
const doc=makeDocument(400,208);
addImage(doc,source,'원본 일본어 · 숨김 참고',false);
const report=[];
for(const s of specs){
  const [x0,y0,x1,y1]=s.bounds,w=x1-x0,h=y1-y0;
  const bm=Bitmap.create(w,h,RasterFormat.RGBA8),wr=PixelReaderWriterRGBA8.create(bm);
  const aligned=Bitmap.create(400,208,RasterFormat.RGBA8),wa=PixelReaderWriterRGBA8.create(aligned);
  let restored=0,preserved=0,fractional=0,opaqueWhite=0;
  for(let y=y0;y<y1;y++)for(let x=x0;x<x1;x++){
    let a=coverage(x,y,s.polys);if(a===0)continue;
    let c=at(x,y),changed=false;
    if(s.kind==='R'){
      const left=203.0+(y-146.8)*(209.3-203.0)/(198.0-146.8);
      // Continue the maroon stem edge through the old word's white/yellow bands.
      // The original green face and its white highlight are explicitly protected.
      const contaminated=(y>=164&&y<=194&&(x<210 || (x<213&&!greenFace(c)))) || (y>=190&&x<221&&!greenFace(c));
      if(contaminated){
        // Use the intact stem border directly above for its horizontal colour profile.
        const sampleX=204+(x-left);
        const donor=at(sampleX,158);
        c=dark(donor)?donor:nearestDark(x+2,y,6);changed=true;
      }
      // Trim foreign P pixels at the small bowl/leg notch with the actual R contour.
      if(edgeDistance(x+.5,y+.5,R)<1.25&&c.b>75&&c.r>140){c=nearestDark(x,y,4);changed=true;}
    }else{
      // At the tucked-away tail, replace only foreign yellow/orange/green pixels.
      const colourContamination=(c.g>c.b+55)||(c.r>c.g+50&&c.r>145);
      if(colourContamination){c=nearestDark(x,y,5);changed=true;}
      const tailRegion=(s.kind==='top'&&y>=145&&x>=71)||(s.kind==='lower'&&y<=194);
      if(tailRegion){
        let depth=0;for(const p of s.polys)if(inside(x+.5,y+.5,p))depth=Math.max(depth,edgeDistance(x+.5,y+.5,p));
        const blend=Math.max(0,Math.min(1,(depth-1.25)/.6));
        const outline=rgba(82,3,0),ivory=rgba(255,253,250);
        c=rgba(outline.r*(1-blend)+ivory.r*blend,outline.g*(1-blend)+ivory.g*blend,outline.b*(1-blend)+ivory.b*blend);changed=true;
      }
      // Fractional exterior white is the original matte, not the opaque puff interior.
      if(a<1&&Math.min(c.r,c.g,c.b)>220)c=nearestDark(x,y,4);
    }
    // Edge colour comes from the opaque maroon stroke, preventing the original
    // white/pink background from becoming a halo on later coloured composites.
    if(a<1)c=nearestDark(x,y,4);
    const out=rgba(c.r,c.g,c.b,a*255);wr.writePixel(x-x0,y-y0,out);wa.writePixel(x,y,out);
    if(changed)restored++;else preserved++;
    if(a<1)fractional++;else if(Math.min(c.r,c.g,c.b)>230)opaqueWhite++;
  }
  wr.dispose();wa.dispose();
  addImage(doc,aligned,s.label);
  // Tight standalone PNG + same-origin 400x208 PNG for later compositing.
  const tight=makeDocument(w,h);addImage(tight,bm,s.label);
  tight.export(DIR+s.name+'.png',png,FileExportArea.createForWholeDocument(),null);
  tight.export(DIR+s.name+'_preview4x.png',png,FileExportArea.createForWholeDocument(),{width:w*4,height:h*4});
  const full=makeDocument(400,208);addImage(full,aligned,s.label);
  full.export(DIR+s.name+'_aligned.png',png,FileExportArea.createForWholeDocument(),null);
  report.push({name:s.name,bounds:s.bounds,size:[w,h],restored_pixels:restored,preserved_pixels:preserved,fractional_alpha_pixels:fractional,opaque_white_interior_pixels:opaqueWhite});
}
console.log(JSON.stringify({document_session_uuid:doc.sessionUuid,source:'original.png',assets:report,original_OA_document_untouched:true,patch_installed:false},null,2));
