//XVII OI
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int maxn = 4e4 + 3, INF = 1e9 + 3;

vector <int> adj[maxn];
int dist1[maxn], dist2[maxn];

void BFS1(int v){
    queue <int> q;
    q.push(v);
    dist1[v] = 0;
    while (!q.empty()){
        v = q.front();
        q.pop();
        for (int child : adj[v]){
            if (dist1[child] == INF){
                dist1[child] = dist1[v] + 1;
                if (dist1[child] < 2){
                    q.push(child);
                }
            }
        }
    }
}

void BFS2(int v){
    queue <int> q;
    q.push(v);
    dist2[v] = 0;
    while (!q.empty()){
        v = q.front();
        q.pop();
        for (int child : adj[v]){
            if (dist2[child] == INF){
                dist2[child] = dist2[v] + 1;
                if (dist2[child] < 2){
                    q.push(child);
                }
            }
        }
    }
}

void solve(){
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++){
        dist1[i] = INF;
        dist2[i] = INF;
    }
    BFS1(1);
    BFS2(2);
    int l1 = 0, l2 = 0, l3 = 0, l4 = 0;
    for (int i = 1; i <= n; i++){
        if (dist1[i] == 1){
            l1++;
        }
        else if (dist1[i] == 2){
            l2++;
        }
        if (dist2[i] == 1){
            l3++;
        }
        if (dist2[i] == 2){
            l4++;
        }
    }
    int rest = n - l1 - l2 - l3 - l4 - 2;
    lli ans = n * (n - 1) / 2 - m - (n - 1 - l1) - l1 * (1 + l3 + l4) - l2 * (1 + l3) - (n - 1 - l3 - 1 - l1 - l2) - min(l1, l3) * rest;
    cout << ans << "\n";
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
