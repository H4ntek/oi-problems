#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

void solve(){
    int n, dump;
    cin >> n;
    vector <int> h(n);
    for (int i = 0; i < n; i++){
        cin >> dump >> h[i];
    }
    stack <int> st;
    int ans = 0;
    for (int i = 0; i < n; i++){
        while (!st.empty() && st.top() > h[i]){
            st.pop();
        }
        if (st.empty() || st.top() != h[i]){
            st.push(h[i]);
            ans++;
        }
    }
    cout << ans << "\n";
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