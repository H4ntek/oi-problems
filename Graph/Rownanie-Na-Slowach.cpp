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

void DFS(int node){
    vis[node] = true;
    for (int child : adj[node]){
        if (!vis[child]){
            DFS(child);
        }
    }
}

int mult(int x, int res[], int res_size){
    int carry =0;
    for (int i = 0; i < res_size; i++){
        int pr = res[i] * x + carry;
        res[i] = pr % 10;
        carry = pr / 10;
    }
    while (carry){
        res[res_size] = carry % 10;
        carry /= 10;
        res_size++;
    }
    return res_size;
}

void bigPower(int x, int n){
    if (n == 0){
        cout << "1\n";
        return;
    }
    int res[100000];
    int res_size = 0;
    int temp = x;
    while (temp != 0){
        res[res_size] = temp % 10;
        res_size++;
        temp /= 10;
    }
    for (int i = 2; i <= n; i++){
        res_size = mult(x, res, res_size);
    }
    for (int i = res_size - 1; i >= 0; i--){
        cout << res[i];
    }
    cout << "\n";
}

void solve(){
    for (int i = 0; i < maxn; i++){
        adj[i].clear();
        vis[i] = false;
    }
    sz.clear();
    first_index.clear();
   int n, x, a, b;
   char c;
   int suma_len = 0;
   cin >> n;
   for (c = 'a'; c < (char) ('a' + n); c++){
       cin >> x;
       suma_len += x;
       sz[c] = x;
       first_index[c] = (c == 'a' ? 2 : first_index[(char) (c - 1)] + sz[(char) (c - 1)]);
   }
   int ll, lr, total_ll = 0, total_lr = 0;
   cin >> ll;
   vector <char> l;
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
   vector <char> r;
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
   char prevl = ';', prevr = ';', cl, cr;
   int in_rowl = -1, in_rowr = -1;
   for (int i = 0; i < total_ll; i++){
       cl = l[i], cr = r[i];
       if (cl != prevl){
        in_rowl = 0;  
        prevl = cl;
       }
       else{
           in_rowl++;
       }
       if (cr != prevr){
           in_rowr = 0;
           prevr = cr;
       }
       else{
           in_rowr++;
       }
       
       if (isDigit(cl) && isDigit(cr)){
           if (cl != cr){
               cout << "0\n";
               return;
           }
       }
       else if (isDigit(cl)){
            if (cl == '0'){
                a = 0;
            }
            else{
                a = 1;
            }
            b = first_index[cr] + in_rowr;
       }
       else if (isDigit(cr)){
           if (cr == '0'){
               b = 0;
           }
           else{
               b = 1;
           }
           a = first_index[cl] + in_rowl;
       }
        else{
            a = first_index[cl] + in_rowl;
            b = first_index[cr] + in_rowr;
        }   
        adj[a].push_back(b);
        adj[b].push_back(a);
   }
   DFS(0);
   if (!vis[1]){
       DFS(1);
   }
    int cc = 0;
    for (int i = 2; i <= suma_len + 1; i++){
        if (!vis[i]){
            DFS(i);
            cc++;
        }
    }
    bigPower(2,cc);
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
