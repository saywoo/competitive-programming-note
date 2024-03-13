
typedef long long int ll;

// Gcd(x, y) : x, y의 최대공약수를 반환
ll Gcd(ll x, ll y) {
    if (y == 0) return x;
    else return Gcd(y, x % y);
}

// Lcm(x, y) : x, y의 최대공약수를 반환
ll Lcm(ll x, ll y) {
    return x * y / Gcd(x, y);
}