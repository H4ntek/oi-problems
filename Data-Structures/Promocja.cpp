#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int maxc = 1e6 + 3, INF = 1e9 + 3;

int freq[maxc];

void solve(){
    int n, k, c, mn = 0, mx = 0, mn2 = INF, mx2 = 0;
    lli ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> k;
        for (int j = 0; j < k; j++){
            cin >> c;
            freq[c]++;
            if (c < mn){
                mn2 = min(mn2, mn);
                mn = c;
            }
            else if (c < mn2){
                mn2 = c;
            }
            if (c > mx){
                mx2 = max(mx2, mx);
                mx = c;
            }
            else if (c > mx2){
                mx2 = c;
            }
        }
        cout << "mn: " << mn << " mn2: " << mn2 << " mx: " << mx << " mx2: " << mx2 << "\n";
    }
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
