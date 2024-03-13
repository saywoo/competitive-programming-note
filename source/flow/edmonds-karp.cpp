
#define MAX 501
#define INF 1e9
struct FlowEdge { int p, c, r; }; // pos, cost, rev
vector<vector<FlowEdge>> graph(MAX);
vector<int> dist(MAX), prv(MAX), idx(MAX);

// addEdge(s, e, c) : s -> e, cost = c인 단방향 간선 추가
// addEdge(s, e, c, c) : s - e, cost = c인 무방향 간선 추가
void addEdge(int s, int e, int c1, int c2 = 0) {
    graph[s].push_back({e, c1, (int)graph[e].size()});
    graph[e].push_back({s, c2, (int)graph[s].size() - 1});
}

int augment(int s, int t) {
    fill(dist.begin(), dist.end(), INF);
    queue<int> q; q.push(s); dist[s] = 0;

    while (q.size()) {
        int pos = q.front(); q.pop();

        for (int i = 0; i < graph[pos].size(); i++) {
            auto &nxt = graph[pos][i];

            if (nxt.c > 0 && dist[nxt.p] == INF) {
                q.push(nxt.p); dist[nxt.p] = dist[pos] + 1;
                prv[nxt.p] = pos; idx[nxt.p] = i;
            }
        }
    }

    if (dist[t] == INF) return 0;

    int flow = INF;
    for (int pos = t; pos != s; pos = prv[pos]) {
        auto &nxt = graph[prv[pos]][idx[pos]];
        flow = min(flow, nxt.c);
    }

    for (int pos = t; pos != s; pos = prv[pos]) {
        auto &nxt = graph[prv[pos]][idx[pos]];
        nxt.c -= flow; graph[nxt.p][nxt.r].c += flow;
    }

    return flow;
}

// s -> t로 흘릴 수 있는 최대 유량 반환
int EdmondKarp(int s, int t) {
    int flow = 0, tmp = 0;

    while (true) {
        tmp = augment(s, t);
        if (tmp) flow += tmp;
        else break;
    }

    return flow;
}