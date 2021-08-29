//XVI OI
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int maxn = 603, maxk = 53, INF = 2e9 + 3;

int n, k;
int a[maxn][maxn], pref[maxn][maxn], dp[maxn][maxk], previous[maxn][maxk];

int getPref(int xa, int ya, int xb, int yb){
    return pref[xb][yb] - pref[xa - 1][yb] - pref[xb][ya - 1] + pref[xa - 1][ya - 1];
}

int help(int a, int b){
    return getPref(a, b + 1, b, n);
}

void solve(){
    cin >> n >> k;
    //a[i][j] - amount of people who boarded at 'i' and got off at 'j'
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    //2D prefix sums
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            pref[i][j] = a[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= k; i++){
        dp[0][i] = -INF;
    }
    dp[0][0] = 0;
    int res;
    for (int i = 1; i < n; i++){ //station
        for (int j = 1; j <= k; j++){ //number of controlls already
            res = 0;
            for (int pr = i - 1; pr >= 0; pr--){ //station where we had a controll previously
                res = dp[pr][j - 1] + help(pr + 1, i);
                if (res > dp[i][j]){
                    dp[i][j] = res;
                    previous[i][j] = pr;
                }
            }
        }
    }

    int mx = 0;
    for (int i = 1; i <= n; i++){
        if (dp[i][k] > dp[mx][k]){
            mx = i;
        }
    }

    vector <int> ans;
    int id = mx;
    for (int i = k; i > 0; i--){
        ans.push_back(id);
        id = previous[id][i];
    }

    reverse(ans.begin(), ans.end());
    for (int x : ans){
        cout << x << " ";
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
