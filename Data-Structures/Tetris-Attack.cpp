//XIV OI
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

void solve(){
    int n, x, y;
    cin >> n;
    vector <int> a(2 * n);
    for (int i = 0; i < 2 * n; i++){
        cin >> a[i];
    }
    stack <int> st, distinct;
    vector <bool> seen(n + 1);
    vector <int> ans;
    for (int i = 2 * n - 1; i >= 0; i--){
        st.push(a[i]);
    }
    while (!st.empty()){
        x = st.top();
        st.pop();
        if (!seen[x]){
            seen[x] = true;
            distinct.push(x);
        }
        else{
            y = distinct.top();
            seen[y] = (seen[y] ? false : true);
            distinct.pop();
            if (x != y){
                ans.push_back(distinct.size() + 1);
                st.push(y);
                st.push(x);
            }
        }
    }
    cout << ans.size() << "\n";
    for (int a : ans){
        cout << a << "\n";
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
