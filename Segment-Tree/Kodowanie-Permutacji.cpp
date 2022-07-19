#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> oset;

void solve(){
	int n;
    cin >> n;
    vector <int> a(n);
    oset st;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        st.insert(-(i + 1));
    }
    vector <int> ans(n);
    for (int i = n - 1; i >= 0; i--){
        if (a[i] >= (int) st.size()){
            cout << "NIE\n";
            return;
        }
        auto it = st.find_by_order(a[i]);
        ans[i] = -(*it);
        st.erase(it);
    }
    for (int x : ans){
        cout << x << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0;
}   
