//IX OI
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int maxn = 103, maxx = 1003;

struct Node{
    int no;
    int mn;
};

vector <int> adj[maxn];
bool vis2[maxn][maxx];
int cost[maxn], n, m, a, b, start, last, x;
Node prv[maxn][maxx];

void BFS(Node v){
    queue <Node> q;
    q.push(v);
    while (!q.empty()){
        v = q.front();
        q.pop();
        vis2[v.no][v.mn] = true;
        if (v.no == last && v.mn == 0){
            return;
        }
        Node n;
        for (int child : adj[v.no]){
            n.no = child;
            n.mn = v.mn - cost[child];
            if (n.mn < 0){
                continue;
            }
            if (!vis2[child][n.mn]){
                q.push(n);
                prv[child][n.mn] = {v.no, v.mn};
            }
        }
    }
}

void solve(){
    cin >> n >> m >> start >> last >> x;
    for (int i = 1; i <= n; i++){
        cin >> cost[i];
    }
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    Node src = {start, x - cost[start]};
    prv[start][x - cost[start]] = {-1, -1};
    BFS(src);

    vector <int> path;
    Node temp = {last, 0};
    path.push_back(temp.no);
    temp = prv[last][0];
    while (temp.no != -1){
        path.push_back(temp.no);
        temp = prv[temp.no][temp.mn];
        if (temp.no == 0){
            break;
        }
    }
    reverse(path.begin(), path.end());
    for (int v : path){
        cout << v << " ";
    }
    cout << "\n";
}

int main (){
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
