
// MillerRabin(n) : n의 소수 여부를 반환
bool MillerRabin(ll n) {
    ll intCheck[] = {2, 7, 61};
    ll llCheck[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

    bool res = true;
    for (ll a: intCheck) {
        if (a % n == 0) break;
        ll k = n - 1;
        while (1) {
            ll tmp = Pow(a, k, n);
            if (tmp == n - 1) break;
            if (k & 1) {
                res &= (tmp == 1 || tmp == n - 1); break;
            }
            k >>= 1;
        }
        if (!res) break;
    }

    return res;
}