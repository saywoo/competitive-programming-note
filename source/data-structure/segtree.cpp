
// 생성 : Segtree* seg = new Segtree(n);
// seg->Update(pos, val) : p 위치에 v 값으로 업데이트
// seg->Query(l, r) : l ~ r 범위의 구간 쿼리 결과를 반환 

typedef long long int ll;

struct Segtree {
    vector<ll> st;
    int tmp;

    Segtree(int n) {
        for (tmp = 1; tmp < n; tmp *= 2) {}
        st.resize(tmp * 2);
    }

    // 용도 별로 Update함수 고쳐쓰기
    void Update(int pos, ll val) {
        pos = pos + tmp - 1;
        st[pos] = val;

        while (pos != 1) {
            pos /= 2;
            st[pos] = st[pos*2] + st[pos*2+1];
        }
    }

    // 용도 별로 쿼리를 처리하는 Search함수 고쳐쓰기
    ll Search(int l, int r, int s, int e, int p) {
        if (e < l || r < s) return 0;
        else if (s <= l && r <= e) return st[p];
        else return Search(l, (l + r) / 2, s, e, p * 2) + Search((l + r) / 2 + 1, r, s, e, p * 2 + 1);
    }

    ll Query(int l, int r) {
        return Search(1, tmp, l, r, 1);
    }
};