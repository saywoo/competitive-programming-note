
// 생성 : LiChaoTree* l = new LiChaoTree(Min, Max);
// Update({a, b}) : y = ax + b을 업데이트
// Query(x) : 트리에 있는 직선 중 가장 큰 ax + b의 값을 리턴

typedef long long int ll;
const ll INF = 2e18;

struct LiChaoTree {
    struct Line {
        ll a, b;
        ll get(ll x) { return a * x + b; }
    };
    struct Node {
        LiChaoTree* l; LiChaoTree* r;
        ll s, e;
        Line line;
    };

    Node node;

    LiChaoTree(ll s, ll e) {
        node.l = NULL; node.r = NULL;
        node.s = s; node.e = e;
        node.line = {0, -INF};
    }

    void Update(Line v) {
        ll s = node.s; ll e = node.e;
        ll m = (s + e) / 2;

        Line low = node.line; Line high = v;
        if (low.get(s) > high.get(s)) swap(low, high);

        if (low.get(e) <= high.get(e)) {
            node.line = high; return;
        }

        if (low.get(m) < high.get(m)) {
            node.line = high;
            if (!node.r) node.r = new LiChaoTree(m + 1, e);
            node.r->Update(low);
        }
        else {
            node.line = low;
            if (!node.l) node.l = new LiChaoTree(s, m);
            node.l->Update(high);
        }
    }

    ll Query(ll x) {
        ll m = (node.s + node.e) / 2;
        ll ret = node.line.get(x);

        if (x <= m) {
            if (node.l) ret = max(ret, node.l->Query(x));
            else ret = max(ret, -INF);
        }
        else {
            if (node.r) ret = max(ret, node.r->Query(x));
            else ret = max(ret, -INF);
        }

        return ret;
    }
};