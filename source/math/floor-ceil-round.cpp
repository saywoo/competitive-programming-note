
typedef long long int ll;

// Floor(x, y) : x / y의 소수값을 버림 후 리턴
ll Floor(ll x, ll y) {
    return x / y;
}

// Round(x, y) : x / y의 소수값을 반올림 후 리턴
ll Round(ll x, ll y) {
    ll tmp = x * 10 / y;
    if (tmp % 10 >= 5) return tmp / 10 + 1;
    else return tmp / 10;
}

// Ceil(x, y) : x / y의 소수값을 올림 후 리턴
ll Ceil(ll x, ll y) {
    return (x + y - 1) / y;
}