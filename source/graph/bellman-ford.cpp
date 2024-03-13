
// 1. 인접 리스트 e에 간선 {가중치, 도착점} 형태로 저장
// 2. BellmanFord(n, s)으로 실행
// 3. dist[i]에 s -> i의 최단경로 가중치 저장
// 4. 음수 사이클이 생기면 cycle = true임

typedef long long int ll;
typedef pair<ll, ll> pr;
#define D first
#define P second

vector<vector<pr>> e(200001);
vector<ll> dist(200001);
bitset<200001> visited;
bool cycle = false;

void BellmanFord(int n, int s) {
    fill(dist.begin(), dist.end(), 1e18);
    dist[s] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[j] == 2e18) continue;

            for (auto k: e[j]) {
                if (dist[k.P] > dist[j] + k.D) {
                    dist[k.P] = dist[j] + k.D;
                    if (i == n) cycle = true;
                }
            }
        }
    }
}