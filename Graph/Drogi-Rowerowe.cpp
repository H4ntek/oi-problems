#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int MAXN = 5e4 + 3;

vector <int> adj[MAXN], adj_t[MAXN], adj_cc[MAXN];
int comp[MAXN], comp_sz[MAXN], dp[MAXN];
bool vis_cc[MAXN];

struct SCC{
    int n, comp_no = 0;
    vector <int> preorder, component;
    vector <bool> vis;

    void init(int n_){
        n = n_;
        preorder.clear();
        component.clear();
    }

    void DFS1(int v){
        vis[v] = true;
        for (int child : adj[v]){
            if (!vis[child]){
                DFS1(child);
            }
        }
        preorder.push_back(v);
    }

    void DFS2(int v){
        vis[v] = true;
        comp[v] = comp_no;
        comp_sz[comp_no]++;
        component.push_back(v);
        for (int child : adj_t[v]){
            if (!vis[child]){
                DFS2(child);
            }
            else{
                if (adj_cc[comp[child]].empty() || adj_cc[comp[child]].back() != comp_no){
                    if (comp[child] != comp_no){
                        adj_cc[comp[child]].push_back(comp_no);
                    }
                }
            }
        }
    }

    vector <vector <int>> run(){
        vector <vector <int>> components;
        vis.assign(n + 1, false);
        for (int i = 1; i <= n; i++){
            if (!vis[i]){
                DFS1(i);
            }
        }
        vis.assign(n + 1, false);
        for (int i = n - 1; i >= 0; i--){
            if (!vis[preorder[i]]){
                comp_no++;
                DFS2(preorder[i]);
                components.push_back(component);
                component.clear();
            }
        }
        return components;
    }
};

void DFS_dp(int v, int par){
    vis_cc[v] = true;
    dp[v] = comp_sz[v];
    for (int child : adj_cc[v]){
        if (child != par){
            DFS_dp(child, v);
            dp[v] += dp[child];
        }
    }
}

void solve(){
	int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj_t[b].push_back(a);
    }
    SCC scc;
    scc.init(n);
    vector <vector <int>> sccs = scc.run();
    for (int i = 1; i <= n; i++){
        if (!vis_cc[i]){
            DFS_dp(i, -1);
        }
    }
    for (int i = 1; i <= n; i++){
        cout << dp[comp[i]] - 1 << "\n";
    }
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
