vector<ll> get_divisors(ll n){
	vector<ll> ret;
	for (ll i = 1; i*i < n; i++){
		if (n % i == 0){
			ret.push_back(i);
			ret.push_back(n/i);
		}
	}
	ll sq = sqrt(n);
	if (sq*sq == n) ret.push_back(sq);
	sort(ret.begin(), ret.end());
	return ret;
}