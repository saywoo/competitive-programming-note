
// 트리의 인접 리스트 e가 주어졌을 때, ETT(rootNode)로 실행하면
// l[x] ~ r[x]가 정점 x의 서브트리의 정점 범위를 나타냄

int cnt = 0;
int l[200200], r[200200];
vector<vector<int>> e;
bitset<200200> visited;

void ETT(int x) {
    l[x] = ++cnt;
    visited[x] = true;

    for (auto i : e[x]) {
        if (!visited[i]) ETT(i);
    }

    r[x] = cnt;
}