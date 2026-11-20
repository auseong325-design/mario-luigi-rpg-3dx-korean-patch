"""Place the unmodified 1DX word, preserving its letter shapes and relative positions."""
from pathlib import Path
import sys
import numpy as np
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'work/img/logo2'))
import l2,layout,seg_1dx

def masks(shape_hr,x_left=18.,right=314.5,baseline=127.5,donor_masks=None):
    donor,_=seg_1dx.syllables(fix_stem=False) if donor_masks is None else (donor_masks,None)
    union=np.maximum.reduce(list(donor.values()))>.5
    yy,xx=np.nonzero(union)
    donor_left=int(xx.min());donor_right=int(xx.max()+1)
    scale=(right-x_left)/(donor_right-donor_left)
    placed={name:layout.resample(cov,donor_left,layout.BASE_1DX,scale,scale,x_left,baseline,shape_hr)>.5
            for name,cov in donor.items()}
    info={'donor_left':donor_left,'donor_right':donor_right,'scale_x':scale,'scale_y':scale,
          'left':x_left,'baseline':baseline,'source_baseline':layout.BASE_1DX,
          'preserve_donor_letter_positions':True,'stroke_growth':0.,'stem_redesign':False,
          'amp_source':'1DX Korean title, same affine transform as all six Hangul glyphs'}
    return placed,info
