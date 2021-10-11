//XXIV OI
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

//A - ciag
//B - roznice

vector <lli> A = {
1,
2,
4,
8,
16,
21,
42,
51,
102,
112,
224,
235,
470,
486,
972,
990,
1980,
2002,
4004,
4027,
8054,
8078,
16156,
16181,
32362,
32389,
64778,
64806,
129612,
129641,
259282,
259313,
518626,
518658,
1037316,
1037349,
2074698,
2074734,
4149468,
4149505,
8299010,
8299049,
16598098,
16598140,
33196280,
33196324,
66392648,
66392693,
132785386,
132785432,
265570864,
265570912,
531141824,
531141876,
1062283752,
1062283805,
2124567610};

vector <lli> B;
map <lli, pair <int, int>> where;

int b_search(int n){
    int l = 0, r = B.size() - 1, mid;
    while (l <= r){
        mid = (l + r) / 2;
        if (B[mid] == n){
            return mid;
        }
        else if (B[mid] < n){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return -1;
}

int first_geq_id(int n){
    int l = 0, r = B.size(), mid, ans = 0;
    while (l <= r){
        mid = (l + r) / 2;
        if (B[mid] < n){
            l = mid + 1;
        }
        else{
            r = mid - 1;
            ans = mid;
        }
    }
    return ans;
}

void solve(){
    int q, x, p;
    cin >> q;
    vector <int> queries(q);
    int max_x = 0;
    for (int i = 0; i < q; i++){
        cin >> x;
        queries[i] = x;
        max_x = max(max_x, x);
    }

    while (A.back() > 2 * max_x){
        A.pop_back();
    }

    for (int i = 1; i < (int) A.size(); i++){
        for (int j = 0; j < i; j++){
            B.push_back(A[i] - A[j]);
            where[A[i] - A[j]] = {i + 1, j + 1};
        }
    }
    sort(B.begin(), B.end());

    for (int n : queries){
        if (b_search(n) != -1){
            pair <int, int> temp = where[n];
            cout << temp.first << " " << temp.second << "\n";
        }
        else{
            p = A.size() + 2 * (n - first_geq_id(n)) - (A.size() % 2);
            cout << p << " " << p - 1 << "\n";
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
