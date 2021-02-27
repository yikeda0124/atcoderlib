ll gcd(ll x, ll y){
    if (x < y) swap(x, y);
    if (x % y == 0) return y;
    return gcd(y, x%y);
}