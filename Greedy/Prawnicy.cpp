#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int INF = 1e9 + 3;

struct P{
    int l, r, id;
};

struct comp{
    bool operator() (const P& a, const P& b){
        if (a.r == b.r){
            return a.l < b.l;
        }
        return a.r > b.r;
    }
};

bool comp1(const P& a, const P& b){
    if (a.l == b.l){
        return a.r < b.r;
    }
    return a.l < b.l;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector <P> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].l >> a[i].r;
        a[i].id = i + 1;
    }
    sort(a.begin(), a.end(), comp1);

    priority_queue <P, vector <P>, comp> pq, save;
    int max_l = -INF, min_r = INF;
    for (int i = 0; i < k; i++){
        pq.push(a[i]);
        save.push(a[i]);
        max_l = max(max_l, a[i].l);
        min_r = min(min_r, a[i].r);
    }
    int best = min_r - max_l;

    for (int i = k; i < n; i++){
        pq.pop();
        pq.push(a[i]);
        max_l = a[i].l;
        min_r = pq.top().r;
        if (min_r - max_l > best){
            best = min_r - max_l;
            save = pq;
        }
    }

    cout << best << "\n";
    while (!save.empty()){
        cout << save.top().id << " ";
        save.pop();
    }
    cout << "\n";
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
