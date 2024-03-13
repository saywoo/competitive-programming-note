
// dk10211 작성
void add(int k, int x) {
	while (k <= n) {
		ft[k] = (ft[k] + x) % MOD;
		k += k & -k;
	}
}
int sum(int k) {
	int s = 0;
	while (k >= 1) {
		s = (s + ft[k]) % MOD;
		k -= k & -k;
	}
	return s;
}