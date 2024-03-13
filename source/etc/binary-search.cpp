
// 0 0 0 0 1 1 1 형태에서 첫번째 1의 위치
int l = 0, r = n;

while (l + 1 < r) {
    int m = (l + r) >> 1;

    bool ok;
    // 여기에 조건 작성

    if (ok) l = m;
    else r = m;
} // l에 결과값 저장됨


// 1 1 1 1 0 0 0 형태에서 마지막 1의 위치
int l = -1, r = n - 1;

while (l + 1 < r) {
    int m = (l + r) >> 1;

    bool ok;
    // 여기에 조건 작성

    if (ok) l = m;
    else r = m;
} // r에 결과값 저장됨