//XVII OI
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int maxn = 1e6 + 3;

int a[maxn];
vector <int> b[maxn], nr[maxn], temp;

void solve(){
    int n, m, k;
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> a[i];
    }
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> k;
        b[i] = vector <int> (k);
        for (int j = k - 1; j >= 0; j--){
            cin >> b[i][j];
        }
        nr[b[i].back() - 1].push_back(i);
    }
    for (int i = 0; i < m; i++){
        temp.clear();
        swap(temp, nr[a[i] - 1]);
        for (int j = 0; j < temp.size(); j++){
            b[temp[j]].pop_back();
            if (!b[temp[j]].empty()){
                nr[b[temp[j]].back() - 1].push_back(temp[j]);
            }
        }
    }
    for (int i = 0; i < n; i++){
        if (b[i].empty()){
            cout << "TAK\n";
        }
        else{
            cout << "NIE\n";
        }
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
