
// 생성 : MergeSortTree* seg = new MergeSortTree(v);
// seg->Query(l, r, c) : l ~ r 범위의 구간 쿼리 결과를 반환
// 예제 쿼리 : l ~ r 범위 구간에서 c보다 큰 원소의 개수

typedef long long int ll;

struct MergeSortTree {
    vector<vector<ll>> st;
    int tmp, siz;

    MergeSortTree(vector<ll> v) {
        siz = v.size();
        for (tmp = 1; tmp < siz; tmp *= 2) {}
        st.resize(tmp * 2);

        for (int i = tmp; i < tmp + siz; i++) st[i].push_back(v[i-tmp]);
        for (int i = tmp - 1; i >= 1; i--) {
            st[i].resize(st[i*2].size()*2);
            merge(st[i*2].begin(), st[i*2].end(), st[i*2+1].begin(), st[i*2+1].end(), st[i].begin());
        }
    }

    // 용도 별로 쿼리를 처리하는 Search함수 고쳐쓰기
    ll Search(int l, int r, int s, int e, int p, int c) {
        if (e < l || r < s) return 0;
        if (s <= l && r <= e) return st[p].size() - (lower_bound(st[p].begin(), st[p].end(), c + 1) - st[p].begin());
        return Search(l, (l + r) / 2, s, e, p * 2, c) + Search((l + r) / 2 + 1, r, s, e, p * 2 + 1, c);
    }

    ll Query(int l, int r, int c) {
        return Search(1, tmp, l, r, 1, c);
    }
};