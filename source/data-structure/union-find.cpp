
// 생성 : UnionFind* uf = new UnionFind(Siz);
// uf->Find(x) : x의 부모를 반환
// uf->Union(x, y, dir) : x, y 그룹을 하나로 합침
// uf->isSameSet(x, y) : x, y가 한 그룹에 있는지 반환

struct UnionFind {
    vector<int> parent;
    int group_count = 0; int size = 0;

    UnionFind(int siz) {
        parent.resize(siz); 
        group_count = siz; size = siz;

        for (int i = 0; i < siz; i++) parent[i] = i;
    }

    ~UnionFind() {
        parent.clear();
        group_count = 0;
    }

    int Find(int x) {
        if (x == parent[x]) return x;
        else return parent[x] = Find(parent[x]);
    }

    // dir == false : x -> y
    // dir == true : x <- y
    void Union(int x, int y, bool dir) {
        x = Find(x); y = Find(y);
        if (x > y) swap(x, y);

        if (x != y) {
            dir ? (parent[x] = y) : (parent[y] = x);
            group_count--;
        }
    }

    bool isSameSet(int x, int y) {
        return Find(x) == Find(y);
    }
};