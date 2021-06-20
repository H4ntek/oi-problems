//VIII OI
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int N = 7;
int primes[N] = {3, 5, 7, 11, 13, 17, 19};
vector <vector <int>> factorization(10);
vector <pair <lli, int>> segment(1);

bool isPrime(int n){
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int nextPrime(int n){
    n++;
    while (!isPrime(n)){
        n++;
    }
    return n;
}

int prevPrime(int n){
    n--;
    while (!isPrime(n)){
        n--;
    }
    return n;
}

vector <bool> bin(int n){
    vector <bool> a(N, false);
    int i = 0;
    while (n){
        if (n & 1){
            a[i] = true;
        }
        n /= 2;
        i++;
    }
    return a;
}

vector <int> find_factorization(int n){
    vector <int> f;
    vector <bool> temp;
    for (int i = 1; i < (N + 1) * (N + 1); i++){
        temp = bin(i);
        int p = 0;
        for (int i = 0; i < N; i++){
            if (temp[i]){
                p += primes[i];
            }
        }
        if (p == n){
            for (int i = 0; i < N; i++){
                if (temp[i]){
                    f.push_back(primes[i]);
                }
            }
            return f;
        }
    } 
    return f;
}

void factor(){
    vector <int> pp;
    bool possible = true;
    while (possible){
        pp = find_factorization(factorization.size());
        if (!pp.empty()){
            factorization.push_back(pp);
        }
        else{
            possible = false;
        }
    }
}

void fill_segments(){
    segment[0].first = factorization.size() - 1;
    segment[0].second = primes[N - 1];
    while (segment.back().first <= (int) 2e9){
        lli temp = prevPrime((int) segment.back().first - 8);
        segment.push_back(make_pair(segment.back().first + temp, temp));
    }
}

vector <int> num_factorization(int n){
    vector <int> temp;
    for (int i = segment.size() - 1; i >= 1; i--){
        if (segment[i].first - segment[i].second + 1 <= n){
            temp.push_back(segment[i].second);
            n -= segment[i].second;
        }
    }
    for (int i = 0; i < factorization[n].size(); i++){
        temp.push_back(factorization[n][i]);
    }
    sort(temp.begin(), temp.end());
    return temp;
}

void solve(){
    int n;
    cin >> n;
    vector <int> a = num_factorization(n);
    cout << a.size() << "\n";
    for (int x : a){
        cout << x << " ";
    }
    cout << "\n";
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    factor();
    fill_segments();
    int t;
    //t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}