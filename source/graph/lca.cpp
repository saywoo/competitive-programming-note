
// 1. 트리의 간선을 인접리스트 e에 저장
// 2. makeSparseTable(root)로 희소 배열을 만든 후, LCA(x, y)

int n, m;
vector<vector<int>> e;
int sp_table[200200][20], dep[200200];
bitset<200200> visited;

void dfs(int p, int d) {
    visited[p] = true;
    dep[p] = d;

    for (int nxt: e[p]) {
        if (!visited[nxt]) {
            sp_table[nxt][0] = p;
            dfs(nxt, d + 1);
        }
    }
}

void makeSparseTable(int root) {
    visited.reset();
    sp_table[root][0] = 1;
    dfs(root, 0);

    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) sp_table[j][i] = sp_table[sp_table[j][i-1]][i-1];
    }
}

int LCA(int x, int y) {
    int dist = 0;
    if (dep[x] < dep[y]) swap(x, y);
    
    for (int i = 19; i >= 0; i--) {
        if (dep[x] - (1 << i) >= dep[y]) {
            dist += 1 << i;
            x = sp_table[x][i];
        }

        if (dep[x] == dep[y]) break;
    }

    for (int i = 19; i >= 0; i--) {
        if (sp_table[x][i] != sp_table[y][i]) {
            dist += 2 << i;
            x = sp_table[x][i];
            y = sp_table[y][i];
        }
    }

    if (x != y) {
        dist += 2;
        x = sp_table[x][0];
        y = sp_table[y][0];
    }

    return x; // return LCA of (x, y)
}