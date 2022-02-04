#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

#define ff first
#define ss second

void solve(){
    int n, m, last_in_gr, nxt, gr_size, nimsum = 0, next_gr_size, to_next;
    cin >> n >> m;
    vector <int> pos(m);
    vector <pair <int, int>> groups;
    int left = m;
    cin >> nxt;
    do {
        last_in_gr = nxt;
        gr_size = 0;
        while (true){
            gr_size++;
            left--;
            if (left == 0){
                break;
            }
            cin >> nxt;
            if (nxt > last_in_gr + 1){
                break;
            }
            last_in_gr = nxt;
        }
        groups.emplace_back(n - last_in_gr - left, gr_size);
        if (groups.back().ff % 2 != 0){
            nimsum ^= gr_size;
        }
    } while (left);

    if (nxt == m - 1){
        cout << gr_size << "\n";
        return;
    }
    if (nimsum == 0){
        cout << "0\n";
        return;
    }

    int moves = 0;
    for (int i = 0; i < (int) groups.size(); i++){
        if (groups[i].ff % 2 != 0){
            if ((groups[i].ss ^ nimsum) < groups[i].ss){
                moves++;
            }
        }
        else if (groups[i].ff > 2){
            if (i == (int) groups.size() - 1 || groups[i + 1].ff < groups[i].ff - 1){
                next_gr_size = 0;
            }
            else{
                next_gr_size = groups[i + 1].ss;
            }
            to_next = (next_gr_size ^ nimsum) - next_gr_size;
            if (to_next > 0 && to_next <= groups[i].ss){
                moves++;
            }
        }
    }
    cout << moves << "\n";
}

int main(){
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
