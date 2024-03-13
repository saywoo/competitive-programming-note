
typedef long long int ll;
#define MOD 1000000007

ll Pow(ll x, ll y, ll mod) {
    ll res = 1;
    x %= mod;

    while (y) {
        if (y & 1) res = (res * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }

    return res;
}

// Comb(n, k) : nCk를 계산해서 반환
// mod값이 소수일 때만 가능
ll Comb(ll n, ll k) {
    ll A = 1, B = 1;
    
    for (int i = 1; i <= n; i++) A = (A * i) % MOD;
    for (int i = 1; i <= k; i++) B = (B * i) % MOD;
    for (int i = 1; i <= n - k; i++) B = (B * i) % MOD;

    return (A * Pow(B, MOD - 2, MOD)) % MOD;
}