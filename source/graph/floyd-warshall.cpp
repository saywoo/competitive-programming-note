
// dist[i][j] = INF로 초기화
// 1. 인접 행렬 dist[s][e]에 가중치를 저장 
// 2. FloydWarshall(n)으로 실행
// 3. dist[i][j]에 i -> j의 최단경로 가중치 저장

typedef long long int ll;
ll dist[1010][1010];

void FloydWarshall(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}