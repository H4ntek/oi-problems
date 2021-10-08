#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

//1-5000 przed granica, 5001-10005 - za granica
const int maxn = 5000;
const lli INF = 1e17 +3;

lli price[2 * maxn + 3];
lli dist[2 * maxn + 3];
vector <int> adj[2 * maxn + 3];
map <pair <int, lli>, int> wgt;
priority_queue <int> pq;

void solve(){
    int n, m, a, b, w, cur, new_w;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> price[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> w;
        adj[a].push_back(b);
        adj[a + maxn].push_back(b + maxn);
        wgt[{a, b}] = w;
        wgt[{a + maxn, b + maxn}] = w;
        dist[a] = INF, dist[b] = INF;
        dist[a + maxn] = INF, dist[b + maxn] = INF;
    }
    for (int i = 1; i <= n; i++){
        adj[i].push_back(i + maxn);
        wgt[{i, i + maxn}] = price[i] / 2;
    }

    dist[1] = 0;
    pq.push(1);

    while(!pq.empty()){
        cur = pq.top();
        pq.pop();
        for (int child : adj[cur]){
            new_w = wgt[{cur, child}];
            if (dist[cur] + new_w < dist[child]){
                dist[child] = dist[cur] + new_w;
                pq.push(child);
            }
        }
    }
    cout << (dist[1 + maxn] != 0 ? dist[1 + maxn] : 50000000) << "\n";
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
