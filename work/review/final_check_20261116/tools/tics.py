import re, collections
from corpus import *
jp = jp_msgs(); ko = ko_final()
exec(open('kjnames.py').read().split("gl = ")[0])
def chk(jpat, kpat, label, show=8):
    hit = [m for m in ko if re.search(jpat, vis(jp[m]['jp']))]
    bad = [m for m in hit if not re.search(kpat, vis(ko[m]))]
    kjh = sum(1 for m in hit if is_kj(m)); kjb = sum(1 for m in bad if is_kj(m))
    print(f'== {label}: {len(hit)} msgs (KJ {kjh}); without expected KO: {len(bad)} (KJ {kjb})')
    for m in bad[:show]:
        print('   ', 'KJ' if is_kj(m) else '  ', m, '| JP:', vis(jp[m]['jp']).replace('\n','')[:90], '| KO:', vis(ko[m]).replace('\n',' ')[:110])
chk('ぼっちゃん', '도련님', 'ぼっちゃん→도련님')
chk('クッパ様|クッパさま', '쿠파님', 'クッパ様→쿠파님')
chk('Jr\\.様|ジュニア様|Jr\\.さま', '주니어님', 'Jr.様→쿠파주니어님')
chk('ワガハイ', '이 몸|내가|나는|나를|나의|이몸|날', 'ワガハイ→이 몸', 12)
chk('るる[！？～…。]|るるる', '롱', 'るる→롱롱', 12)
chk('びん[！？～…。ね]|だび～ん', '빈', 'びん→로빈', 6)
chk('お父さん', '아빠|아버', 'お父さん', 12)
chk('ゲラコビッツ', '까르코비츠', 'ゲラコビッツ')
chk('メタボス', '메타보스', 'メタボス')
chk('ブリローズ', '블로즈', 'ブリローズ')
chk('カメック', '마귀', 'カメック', 12)
# Jr residue in KO
jr = [m for m in ko if re.search(r'Jr|JR|쥬니어|주니어 RPG', vis(ko[m]))]
print('KO with Jr/쥬니어/"주니어 RPG":', len(jr), jr[:10])
