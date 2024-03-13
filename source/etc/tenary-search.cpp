
// 볼록, 오목 개형에서 극점을 찾을때 사용
int l = 0; int r = n;
int a, b;

while (r - l >= 3) {
    a = (l * 2 + r) / 3;
    b = (l + r * 2) / 3;

    bool ok;
    // 여기에 조건 작성

    if (ok) r = b;
    else l = a;
}