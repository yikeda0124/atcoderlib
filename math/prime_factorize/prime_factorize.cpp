vector<ll> prime_factorize(ll n){
	vector<ll> ret;
	for (ll i = 2; i*i <= n; i++){
		while (n % i == 0){
			ret.push_back(i);
			n /= i;
		}
	}
	if (n != 1) ret.push_back(n);
	return ret;
}