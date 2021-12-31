#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int maxn = 5e4 + 3;

vector <int> adj[maxn], adj_t[maxn], adj_cc[maxn];
vector <int> postorder;

int which_cc[maxn], cc_size[maxn], dp[maxn];
bool vis_1[maxn], vis_cc[maxn];

void DFS_1(int v){
    vis_1[v] = true;
    for (int child : adj[v]){
        if (!vis_1[child]){
            DFS_1(child);
        }
    }
    postorder.push_back(v);
}

void DFS_2(int v, int num){
    which_cc[v] = num;
    cc_size[num]++;
    for (int child : adj_t[v]){
        if (which_cc[child] == 0){
            DFS_2(child, num);
        }
        else{
            if (adj_cc[which_cc[child]].empty() || adj_cc[which_cc[child]].back() != num){
                if (which_cc[child] != num){
                    adj_cc[which_cc[child]].push_back(num);
                }
            }
        }
    }
}

void DFS_cc(int v, int par){
    vis_cc[v] = true;
    dp[v] = cc_size[v];
    for (int child : adj_cc[v]){
        if (child != par){
            DFS_cc(child, v);
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
    for (int i = 1; i <= n; i++){
        if (!vis_1[i]){
            DFS_1(i);
        }
    }
    reverse(postorder.begin(), postorder.end());
    int cc_num = 0;
    for (int v : postorder){
        if (which_cc[v] == 0){
            cc_num++;
            DFS_2(v, cc_num);
        }
    }
    for (int i = 1; i <= cc_num; i++){
        if (!vis_cc[i]){
            DFS_cc(i, -1);
        }
    }
    for (int i = 1; i <= n; i++){
        cout << dp[which_cc[i]] - 1 << "\n";
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
