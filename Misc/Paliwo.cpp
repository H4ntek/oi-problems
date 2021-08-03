//IV OI
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

void solve(){
    lli cap, n, temp, ans, total_val, total_fuel, delta;
    queue <pair <lli, lli>> tank; 
    cin >> cap;
    cin >> n;
    vector <lli> a(n + 1), dist(n);
    for (lli i = 0; i < n; i++){
        cin >> a[i] >> dist[i];
    }
    a[n] = 0;
    tank.push({cap, a[0]});
    total_val = cap * a[0];
    ans = cap * a[0];
    total_fuel = cap;
    for (lli i = 1; i <= n; i++){
        delta = 0;
        total_fuel -= dist[i - 1];
        temp = dist[i - 1];
        while (!tank.empty() && tank.front().first <= temp){
            total_val -= temp * tank.front().second;
            temp -= tank.front().first;
            tank.pop();
        }
        if (!tank.empty()){
            total_val -= temp * tank.front().second;
            tank.front().first -= temp;
            if (tank.front().first == 0){
                tank.pop();
            }
        }

        while (!tank.empty() && tank.front().second > a[i]){
            delta -= tank.front().first * tank.front().second;
            total_val -= tank.front().first * tank.front().second;
            total_fuel -= tank.front().first;
            tank.pop();
        }
        total_val += (cap - total_fuel) * a[i];
        delta += (cap - total_fuel) * a[i];
        tank.push({cap - total_fuel, a[i]});
        total_fuel = cap;
        ans += delta;
        //cout << "koszt na stacji " << i << ": " << delta << "\n";
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
