//XII OI
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int maxn = 1003, maxl = 1e4 + 3;

typedef short int tab[10];
tab *occs[maxn];
int seq[maxl];

tab *genTab(int len){
    tab *a = new tab[len];
    int i = len - 1;
    for (int j = 0; j <= 9; j++){
        a[i][j] = -1;
    }
    a[i][seq[i]] = i;
    for (int i = len - 2; i >= 0; i--){
        for (int j = 0; j <= 9; j++){
            a[i][j] = a[i + 1][j];
        }
        a[i][seq[i]] = i;
    }
    return a;
}

bool check(int pin, tab *a){
    int pos = 0, dig;
    for (int i = 0; i <= 3; i++){
        dig = pin % 10;
        pin /= 10;
        pos = a[pos][dig];
        if (pos == -1){
            return false;
        }
    }
    return true;
}

void solve(){
    int n, sz;
    char c;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> sz;
        for (int i = 0; i < sz; i++){
            cin >> c;
            seq[i] = c - '0';
        }
        occs[i] = genTab(sz);
    }
    lli ans = 0;
    for (int pin = 0; pin <= 9999; pin++){
        int ok = 1;
        for (int i = 0; i < n; i++){
            ok &= check(pin, occs[i]);
        }
        ans += ok;
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
