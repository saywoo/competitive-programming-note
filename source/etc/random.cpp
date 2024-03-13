
// Rand.randInt(l, r) : l~r 범위 안의 랜덤숫자 반환
struct Random {
	mt19937 rd;
	Random() : rd(chrono::steady_clock::now().time_since_epoch().count()) {}
	ll randInt(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }
	double randDouble(double l, double r) { return uniform_real_distribution<double>(l, r)(rd); }
} Rand;