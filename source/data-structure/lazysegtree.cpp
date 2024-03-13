
// 생성 : LazySegtree* seg = new LazySegtree(n);
// seg->Update(l, r, val) : l ~ r 범위의 구간에 v 값으로 업데이트
// seg->Query(l, r) : l ~ r 범위의 구간 쿼리 결과를 반환 

typedef long long int ll;

struct LazySegtree {
    vector<ll> st, lazy;
    int tmp;

    LazySegtree(int n) {
        for (tmp = 1; tmp < n; tmp *= 2) {}
        st.resize(tmp * 2); lazy.resize(tmp * 2);
    }

    void prop(int l, int r, int p) { 
        st[p] += lazy[p] * (r - l + 1);
        if (l != r) {
            lazy[p*2] += lazy[p]; lazy[p*2+1] += lazy[p];
        }
        lazy[p] = 0;
    }

    // 용도 별로 업데이트를 처리하는 RangeUpdate함수 고쳐쓰기
    void RangeUpdate(int l, int r, int s, int e, int p, ll val) {
        if (lazy[p]) prop(l, r, p);

        if (e < l || r < s) return;
        else if (s <= l && r <= e) {
            lazy[p] += val;
            prop(l, r, p);
            return;
        }
        else {
            RangeUpdate(l, (l + r) / 2, s, e, p * 2, val);
            RangeUpdate((l + r) / 2 + 1, r, s, e, p * 2 + 1, val);
            st[p] = st[p*2] + st[p*2+1];
        }
    }

    
    void Update(int l, int r, ll val) {
        RangeUpdate(1, tmp, l, r, 1, val);
    }

    // 용도 별로 쿼리를 처리하는 Search함수 고쳐쓰기
    ll Search(int l, int r, int s, int e, int p) {
        if (lazy[p]) prop(l, r, p);

        if (e < l || r < s) return 0;
        else if (s <= l && r <= e) return st[p];
        else return Search(l, (l + r) / 2, s, e, p * 2) + Search((l + r) / 2 + 1, r, s, e, p * 2 + 1);
    }

    ll Query(int l, int r) {
        return Search(1, tmp, l, r, 1);
    }
};