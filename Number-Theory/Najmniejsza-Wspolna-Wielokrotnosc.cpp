#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int INF = 1e9 + 3;

const lli ending_values[4] = {2000000, 70000, 10000, 3000};

lli special_case(lli n){
    lli m = 4*n + 1;
    lli root = sqrt(m);
    for (lli i = root - 8; i <= root + 8; i++){
        if (i * i == m){
            if (i % 2 == 1){
                return (i - 1) / 2;
            }
        }
    }
    return 0;
}

lli __lcm(lli a, lli b){
    return (a / __gcd(a, b)) * b;
}

lli LCM(int first, int last){
    lli res = 1;
    for (int i = first; i <= last; i++){
        res = __lcm(res, i);
    }
    return res;
}

int b_search(const vector <pair <lli, pair <int, int>>> &a, lli n){
    int l = 0, r = a.size(), mid, ans = -1;
    while (l <= r){
        mid = (l + r) / 2;
        if (a[mid].first < n){
            l = mid + 1;
        }
        else if (a[mid].first == n){
            ans = mid;
            r = mid - 1;
        }
        else{
            r = mid - 1;
        }
    }
    return ans;
}

void solve(){
    int q, where, ans_start, ans_end;
    lli n, temp;
    bool found;
    vector <pair <lli, pair <int, int>>> answers; /* {LCM, {start, start + len - 1}} */
    for (int k = 3; k <= 100; k++){
        for (int start = 1; start <= ending_values[min(3, k - 3)]; start++){
            answers.emplace_back(LCM(start, start + k - 1), make_pair(start, start + k - 1));
        }
    }
    sort(answers.begin(), answers.end());

    cin >> q;
    while (q--){
        found = false;
        ans_start = ans_end = INF;
        cin >> n;
        //special case
        temp = special_case(n);
        if (temp){
            found = true;
            ans_start = temp;
            ans_end = temp + 1;
        }
        
        //b. search the answer
        where = b_search(answers, n);
        if (where == -1){
            if (found){
                cout << ans_start << " " << ans_end << "\n";
            }
            else{
                cout << "NIE\n";
            }
        }
        else{
            if (answers[where].second.first < ans_start){
                cout << answers[where].second.first << " " << answers[where].second.second << "\n";
            }
            else{
                cout << ans_start << " " << ans_end << "\n";
            }
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    //cin >> t;
    t = 1;
    while (t--){
        solve();
    }
    return 0;
}
