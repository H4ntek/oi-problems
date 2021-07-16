//IX OI
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int maxl = 2002;

struct BigNum{
    int len;
    int base = 10;
    int data[maxl];
    int &operator [] (int i){
        return data[i];
    }
    const int &operator [] (int i) const{
        return data[i];
    }
    BigNum(){
        memset(data, 0, sizeof(data));
        len = 0;
    }
    void clear(){
        for (int i = len; i>= 1; i--){
            data[i] = 0;
        }
        len = 0;
    }

    int check (const BigNum &a, const BigNum &b){
        if (a.len > b.len){
            return 0;
        }
        if (b.len > a.len){
            return 1;
        }
        for (int i = a.len; i >= 1; i--){
            if (a.data[i] > b.data[i]){
                return 0;
            }
            if (a.data[i] < b.data[i]){
                return 1;
            }
        }
        return 2;
    }
    bool operator < (const BigNum &x){
        return check(*this, x) == 1;
    }
    bool operator > (const BigNum &x){
        return check(*this, x) == 0;
    }
    bool operator <= (const BigNum &x){
        return check(*this, x) >= 1;
    }
    bool operator >= (const BigNum &x){
        return check(*this, x) % 2 == 0;
    }
    bool operator != (const BigNum &x){
        return check(*this, x) != 2;
    }
    bool operator == (const BigNum &x){
        return check(*this, x) == 2;
    }

    BigNum operator = (const BigNum &x){
        for (int i = x.len + 1; i <= len; i++){
            data[i] = 0;
        }  
        for (int i = 1; i <= x.len; i++){
            data[i] = x.data[i];
        }
        len = x.len;
        return *this;
    }
    BigNum operator = (lli x){
        for (int i = len; i >= 0; i--){
            data[i] = 0;
        }
        len = 0;
        while (x){
            data[++len] = x % base;
            x /= base; 
        }
        return *this;
    }

	BigNum operator + (const BigNum &x){
        BigNum temp;
        int i, l = max(len, x.len);
        for (int i = 1; i <= l; i++){
            temp[i] = data[i] + x[i];
        }
        for (int i = 1; i <= l; i++){
            temp[i + 1] += temp[i] / base;
            temp[i] %= base;
        }
        temp.len = l;
        if (temp[temp.len + 1] != 0){
            temp.len++;
        }
        return temp;
    }
    BigNum operator - (const BigNum &x){
        BigNum temp;
        for (int i = 1; i <= len; i++){
            temp.data[i] = data[i] - x.data[i];
        }
        for (int i = 1; i <= len; i++){
            if (temp[i] < 0){
                temp.data[i] += base;
                temp.data[i + 1]--;
            }
        }
        temp.len = len;
        while (temp[temp.len] == 0 && temp.len > 1){
            temp.len--;
        }
        return temp;
    }
    BigNum operator * (const lli &x){
        BigNum temp;
        for (int i = 1; i <= len; i++){
            temp[i] = data[i] * x;
        }
        temp.len = len;
        for (int i = 1; i <= len; i++){
            temp[i + 1] += temp[i] / base;
            temp[i] %= base;
            if (temp[i + 1] != 0 && i + 1 > temp.len){
                temp.len++;
            }
        }
        return temp;
    }
    BigNum operator * (const BigNum &x){ 
        BigNum temp;
        for (int i = 1; i <= len; i++){
            if (data[i] != 0){
                for (int j = 1; j <= x.len; j++){
                    if (x.data[j] != 0){
                        temp.data[i + j -  1] += data[i] * x.data[j];
                        temp.data[i + j] += temp.data[i + j - 1] / base;
                        temp.data[i + j - 1] %= base;
                    }
                }
            }
        }
        temp.len = len + x.len - 1;
        while (temp.data[temp.len + 1] != 0){
            temp.len++;
        }
        return temp;
    }
    BigNum operator ^ (int x){
        BigNum temp, res;
        temp = *this;
        res = 1;
        for (int i = 1; i <= x; i++){
            res *= temp;
        }
        return res;
    }

    BigNum operator += (const BigNum &x){
        return *this = (*this + x);
    }
    BigNum operator -= (const BigNum &x){
        return *this = (*this - x);
    }
    BigNum operator *= (const lli &x){
        return *this = (*this * x);
    }
    BigNum operator *= (const BigNum &x){
        return *this = (*this * x);
    }

    void write(){
        cout << data[len];
        for (int i = len - 1; i >= 1; i--){
            cout << data[i];
        }
        cout << "\n";
    }
};

void solve(){
	int k, n, m, l;
	cin >> k >> n >> m >> l;
	vector <BigNum> dp(m + 1), pref(m + 2);
	dp[0] = 1, pref[0] = 1;
	for (int i = 1; i <= m; i++){
		if (i < l){
			dp[i] = dp[i - 1] * k;
		}
		else{
			dp[i] = (pref[i - 1] - pref[i - l]) * (k - 1);
		}
		pref[i] = pref[i - 1] + dp[i];
	} 
    BigNum x = dp[m] ^ (n / m);
    BigNum power;
    power = 1;
    int ans = 0;
    while ((power * 2) <= x){
        power *= 2;
        ans++;
    }
    cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	t = 1;
	//cin >> t;
	while (t--){
		solve();
	}
	return 0;
}
