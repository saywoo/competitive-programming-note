
// 1. 인접 리스트 e에 간선 {가중치, 도착점} 형태로 저장
// 2. SPFA(n, s)으로 실행
// 3. dist[i]에 s -> i의 최단경로 가중치 저장
// 4. 음수 사이클이 생기면 cycle = true임

typedef long long int ll;
typedef pair<ll, ll> pr;
#define D first
#define P second

vector<vector<pr>> e(200001);
vector<ll> dist(200001), cnt(200001);
bitset<200001> inq; // 큐 안에 들어가 있는지 저장
bool cycle = false;

void SPFA(int n, int s) {
    fill(dist.begin(), dist.end(), 1e18);
    fill(cnt.begin(), cnt.end(), 0); inq.reset();
    
    queue<int> q;
    q.push(s); inq[s] = true; dist[s] = 0;

    while (!q.empty()) {
        int t = q.front();
        q.pop(); inq[t] = false;

        if (++cnt[t] >= n || dist[t] < -1e18) {
            cycle = true; return;
        }

        for (auto i: e[t]) {
            if (dist[i.P] > i.D + dist[t]) {
                dist[i.P] = i.D + dist[t];
                if (!inq[i.P]) {
                    q.push(i.P);
                    inq[i.P] = true;
                }
            }
        }
    }
}