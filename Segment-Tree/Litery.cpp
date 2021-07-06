//XIX OI
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int maxn = 1e6 + 5, pow2 = (1 << 20);

int tree[2 * pow2]; 

void update(int i, int val){
    int id = pow2 + i;
    tree[id] = val;
    while (id > 1){
        id /= 2;
        tree[id] = tree[2 * id] + tree[2 * id + 1];
    }
}

int query(int l, int r){
    int id_l = pow2 + l, id_r = pow2 + r;
    int res = tree[id_l];
    if (id_l != id_r){
        res += tree[id_r];
    }
    while (id_l / 2 != id_r / 2){
        if (id_l % 2 == 0){
            res += tree[id_l + 1];
        }
        id_l /= 2;
        if (id_r % 2 == 1){
            res += tree[id_r - 1];
        }
        id_r /= 2;
    }
    return res;
}

void solve(){
    int n, pos;
    lli ans = 0;
    string s, t;
    cin >> n;
    cin >> s >> t;
    vector <stack <int>> next_occ(27);
    for (int i = n - 1; i >= 0; i--){
        next_occ[s[i] - 'A'].push(i);
    }
    int c;
    for (int i = 0; i < n; i++){
        c = t[i] - 'A';
        pos = next_occ[c].top();
        next_occ[c].pop();
        update(pos, 1);
        pos += query(pos + 1, n);
        ans += pos - i; 
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    //cin >> tc;
    tc = 1;
    while (tc--){
        solve();
    }
    return 0;
}
