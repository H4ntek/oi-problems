//II OI
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

struct Node{
	int l;
	int r;
};

const int maxn = 2503;

Node tree[maxn];
int gen_trav[maxn];

string brackets(int v){ //works
	string ls = "", rs = "";
	int left = tree[v].l, right = tree[v].r;
	if (left != -1){
		ls = brackets(left);
	}
	if (right != -1){
		rs = brackets(right);
	}
	string here = "(" + ls + rs + ")";
	return here;
}

void geneal(int v, int par){
	gen_trav[v] = par;
	int left = tree[v].l, right = tree[v].r;
	if (left != -1){
		geneal(left, v);
	}
	if (right != -1){
		geneal(right, v);
	}
}

void solve(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> tree[i].l >> tree[i].r;
	}
	geneal(1, 0);
	string brack = brackets(1);
	for (int i = 1; i <= n; i++){
		cout << gen_trav[i] << " ";
	}
	cout << "\n" << brack;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t = 1;
	//cin >> t;
	while (t--){
		solve();
	}
	return 0;
}
