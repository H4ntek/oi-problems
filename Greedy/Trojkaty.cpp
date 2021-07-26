//I OI
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

struct Frac{
    lli p;
    lli q;

    int check(Frac a, Frac b){
        lli lcm = (a.q * b.q) / __gcd(a.q, b.q);
        a.p *= (lcm / a.q);
        b.p *= (lcm / b.q);
        a.q = lcm;
        b.q = lcm;
        if (a.p < b.p){
            return 1;
        }
        if (a.p > b.p){
            return 0;
        }   
        else{
            return 2;
        }
    }

    bool operator < (const Frac &x){
        return check(*this, x) == 1;
    }
    bool operator > (const Frac &x){
        return check(*this, x) == 0;
    }
    bool operator <= (const Frac &x){
        return check(*this, x) >= 1;
    }
    bool operator >= (const Frac &x){
        return check(*this, x) % 2 == 0;
    }
    bool operator != (const Frac &x){
        return check(*this, x) != 2;
    }
    bool operator == (const Frac &x){
        return check(*this, x) == 2;
    }

    Frac operator + (Frac b){
        Frac c;
        lli lcm = ((*this).q * b.q) / __gcd((*this).q, b.q);
        (*this).p *= (lcm / (*this).q);
        b.p *= (lcm / b.q);
        (*this).q = lcm;
        b.q = lcm;
        c.q = (*this).q;
        c.p = (*this).p + b.p;
        return c;
    }

    void write(){
        cout << (*this).p << "/" << (*this).q << "\n";
    }
};

int power[4] = {1, 10, 100, 1000}; 

void solve(){
    int n;
    cin >> n;
    string s;
    vector <Frac> a(n);
    for (int i = 0; i < n; i++){
        Frac f;
        f.p = 0, f.q = 0;
        cin >> s;
        int mid;
        for (int j = 0; j < s.size(); j++){
            if (s[j] == '/'){
                mid = j;
                break;
            }
        }
        int po = 0;
        int l = mid - 1;
        while (l >= 0){
            f.p += power[po] * (int) (s[l] - '0');
            po++;
            l--;
        }
        int r = s.size() - 1;
        po = 0;
        while (r > mid){
            f.q += power[po] * (int) (s[r] - '0');
            po++;
            r--;

        }
        a[i] = f;
    }
    sort(a.begin(), a.end());
    cout << (a[0] + a[1] > a[n - 1] ? "TAK\n" : "NIE\n");
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
