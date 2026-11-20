from corpus import *
jp = jp_msgs(); ko = ko_final()
pairs = [('タッチ', '터치'), ('ペン', '펜'), ('下画面', '아래 화面'), ('上画面', '위 화면'), ('マイク', '마이크'), ('スライドパッド', '슬라이드'), ('十字ボタン', '십자'), ('Ｌ', 'L'), ('Ｒ', 'R'), ('ＳＴＡＲＴ', 'START'), ('ＳＥＬＥＣＴ', 'SELECT'), ('ＨＯＭＥ', 'HOME'), ('amiibo', 'amiibo'), ('セーブ', '저장'), ('ニンテンドー', '닌텐도')]
pairs[2] = ('下画面', '아래 화면')
for j, k in pairs:
    a = [m for m in ko if j in vis(jp[m]['jp']) and k not in vis(ko[m])]
    b = [m for m in ko if j not in vis(jp[m]['jp']) and k in vis(ko[m])]
    print(f'== {j}/{k}: JP-only {len(a)}, KO-only {len(b)}')
    for m in (a + b)[:8]:
        print('  ', m, '| KO:', vis(ko[m]).replace('\n', ' ')[:150], '| JP:', vis(jp[m]['jp']).replace('\n', '')[:150])
