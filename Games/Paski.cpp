#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int MAXN = 1003;

int a, b, c, dp[MAXN];

int mex(vector <int> a){
	if (a.empty()){
		return 0;
	}
	sort(a.begin(), a.end());
	if (a[0] != 0){
		return 0;
	}
	int nxt = 1;
	for (int x : a){
		if (x == nxt){
			nxt++;
		}
		else if (x > nxt){
			return nxt;
		}
	}
	return nxt;
}

int f(int n){
	if (n == 0){
		return 0;
	}
	if (dp[n] != -1){
		return dp[n];
	}
	vector <int> zbior;
	for (int i = 0; i <= n - a; i++){
		zbior.push_back(f(i) ^ f(n - i - a));
	}
	for (int i = 0; i <= n - b; i++){
		zbior.push_back(f(i) ^ f(n - i - b));
	}
	for (int i = 0; i <= n - c; i++){
		zbior.push_back(f(i) ^ f(n - i - c));
	}
	return dp[n] = mex(zbior);
}

void solve(){
	memset(dp, -1, sizeof(dp));
	int q, n;
	cin >> a >> b >> c;
	cin >> q;
	while (q--){
		cin >> n;
		cout << (f(n) == 0 ? "2\n" : "1\n");
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
