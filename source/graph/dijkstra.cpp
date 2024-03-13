
// 1. 인접 리스트 e에 간선 {음이 아닌 가중치, 도착점} 형태로 저장
// 2. Dijkstra(s)으로 실행
// 3. dist[i]에 s -> i의 최단경로 가중치 저장

typedef long long int ll;
typedef pair<ll, ll> pr;
#define D first
#define P second

vector<vector<pr>> e(200001);
vector<ll> dist(200001);
bitset<200001> visited;

void Dijkstra(int s) {
    visited.reset(); fill(dist.begin(), dist.end(), 1e18);
    priority_queue<pr, vector<pr>, greater<pr>> pq;

    pq.push({0, s}); dist[s] = 0;

    while (!pq.empty()) {
        pr t = pq.top();
        pq.pop();

        if (visited[t.P]) continue;
        visited[t.P] = true;

        for (auto i: e[t.P]) {
            if (dist[i.P] > dist[t.P] + i.D) {
                dist[i.P] = dist[t.P] + i.D;
                pq.push({dist[i.P], i.P});
            }
        }
    }
}