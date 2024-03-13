
// pollardRho(n, v) : v 배열에 n의 소인수를 반환
void PollardRho(ll n, vector<ll> &v) {
    if (n == 1) return;
    if (MillerRabin(n)) { v.push_back(n); return; }
    if (~n & 1) { v.push_back(2); PollardRho(n >> 1, v); return; }

    ll a, b, c, g = n;
    auto f = [&](ll x) { return (c + Mul(x, x, n)) % n; };

    a = b = Rand.randInt(0, n - 2) + 2;
    c = Rand.randInt(0, n - 1) + 1;
    do {
        a = f(a); b = f(f(b));
        g = gcd(abs(a - b), n);
    } while (g == 1);

    PollardRho(g, v); PollardRho(n / g, v);
}