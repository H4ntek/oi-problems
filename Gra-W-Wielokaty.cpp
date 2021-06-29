//VI OI
//Game theory / geometry
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

void solve(){
    int n;
    cin >> n;
    int black[3];
    cin >> black[0] >> black[1] >> black[2];
    if (n % 2 == 0){
        cout << "TAK\n";
        return;
    }
    sort(black, black + 3);
    if (black[2] - black[0] == 2){
        cout << "TAK\n";
    }
    else if (black[0] == 0 && black[1] == n - 2 && black[2] == n - 1){
        cout << "TAK\n";
    }
    else if (black[0] == 0 && black[1] == 1 && black[2] == n - 1){
        cout << "TAK\n";
    }
    else{
        cout << "NIE\n";
    }
}

int main (){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
