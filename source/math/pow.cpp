
typedef long long int ll;
ll mod = 1000000007;

// Mul(x, y, mod) : x*y % mod를 반환
ll Mul(ll x, ll y, ll mod) { return (__int128_t)x * y % mod; }

// Pow(x, y, mod) : x^y % mod를 반환
ll Pow(ll x, ll y, ll mod) {
    ll res = 1; x %= mod;
    while (y) {
        if (y & 1) res = Mul(res, x, mod);
        x = Mul(x, x, mod);
        y >>= 1;
    }
    return res;
}