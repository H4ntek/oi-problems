//XX OI
//DP on tree
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int maxn = 3e5 + 3;

vector <int> adj[maxn];
int dp[maxn];

int DFS(int node, int par, int &k){
	int amount = 0;
	for (int child : adj[node]){
		if (child != par){
			amount += DFS(child, node, k) + 1;
		}
	}
	amount -= k;
	return dp[node] = max(0, amount);
}

void solve(){
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int l = 0, r = n, mid;
	while (l < r){
		mid = (l + r)/2;
		dp[1] = DFS(1, -1, mid);
		if (dp[1] == 0){
			r = mid;
		}
		else{
			l = mid + 1;
		}
		memset(dp, 0, sizeof(dp));
	}
	cout << l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    //cin >> t;
    t = 1;
    while (t--){
        solve();
    }
    return 0;
}
