//V OI
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

unordered_map <char, int> sz, first_index;

const int maxn = 1e4 + 3;

vector <int> adj[maxn];
bool vis[maxn];

bool isDigit(const char &c){
    return c == '0' || c == '1';
}

void solve(){
   int n, x, a, b;
   char c;
   cin >> n;
   for (c = 'a'; c < (char) ('a' + n); c++){
       cin >> x;
       sz[c] = x;
       first_index[c] = (c == 'a' ? 2 : first_index[(char) (c - 1)] + sz[(char) (c - 1)]);
   }
   int ll, lr, total_ll = 0, total_lr = 0;
   cin >> ll;
   vector <char> l(ll);
   for (int i = 0; i < ll; i++){
       cin >> c;
       if (isDigit(c)){
           l.push_back(c);
           total_ll++;
       }
       else{
           l.resize(l.size() + sz[c], c);
           total_ll += sz[c];
       }
   }
   cin >> lr;
   vector <char> r(ll);
   for (int i = 0; i < lr; i++){
       cin >> c;
       if (isDigit(c)){
            r.push_back(c);
            total_lr++;
       }
       else{
           r.resize(r.size() + sz[c], c);
           total_lr += sz[c];
       }
   }
   if (total_lr != total_ll){
       cout << "0\n";
       return;
   }
   for (int i = 0; i < total_ll; i++){
       char cl = l[i], cr = r[i];
       if (isDigit(cl) && isDigit(cr)){
           if (cl != cr){
               cout << "0\n";
               return;
           }
       }
       if (isDigit(cl)){
            if (cl == '0'){
                a = 0;
            }
            else{
                a = 1;
            }
       }
       if (isDigit(cr)){
           if (cr == '0'){
               b = 0;
           }
           else{
               b = 1;
           }
       }
     //dokonczyc
   }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    //t = 1;
    while (t--){
        solve();
    }
    return 0;
}

