
// 길이 2n 괄호 문자열의 경우의 수
// n+2각형 → n개 삼각형으로 분할하는 경우의 수
// 일반항 : C_n = 1/(n+1) * (2n)C(n)

#include <bits/stdc++.h>
#define MOD 987654321
using namespace std;
typedef long long ll;

ll dp[12345] = {0};

int main(){
	int N;
	cin >> N;
	
	dp[0] = 1;
	for(int i=1; i<=N; i++){
		for(int j=0; j<i; j++){
			dp[i] += (dp[j]*dp[i-j-1]);
			dp[i] %= MOD;
		}
	}
	
	cout << dp[N/2];
	return 0;
}