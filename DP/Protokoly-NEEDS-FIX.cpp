//IX OI
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

struct OmegaInt{
	
};

void solve(){
	int k, n, m, l;
	cin >> k >> n >> m >> l;
	vector <OmegaInt> dp(m + 1), pref(m + 2);
	//smth equivalent to dp[0] = 1 and pref[0] = 1 but in BigNum
	for (int i = 1; i <= m; i++){
		if (i < l){
			dp[i] = mul(dp[i - 1], k);
		}
		else{
			dp[i] = mul(sub(pref[i - 1], pref[i - l]), k - 1);
		}
		pref[i] = add(pref[i - 1], dp[i]);
	} 
	//ans = floor((n/m) * log2(dp[m])) = floor(log2(pow(dp[m], n/m))) = max. power of 2 not larger than pow(dp[m], n/m)
	//45 pts for now, needs BigNum with add, sub, mul and pow
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	t = 1;
	//cin >> t;
	while (t--){
		solve();
	}
	return 0;
}
