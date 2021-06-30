//IV OI
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

void solve(){
    int n, m, a, b;
    cin >> n;
    cin >> m;
    vector <int> neigh(n + 1);
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        neigh[a]++;
        neigh[b]++;
    }
    lli diff = 0; 
    for (int i = 1; i <= n; i++){
        diff += neigh[i] * (n - neigh[i] - 1);
    }
    diff /= 2;
    lli all = (n * (n - 1) * (n - 2)) / 6;
    cout << all - diff << "\n";
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
