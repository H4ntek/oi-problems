//IX OI
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int maxn = (1 << 16);

lli st[2 * maxn], lazy[2 * maxn];
lli cap;

void propagate(int me, int left, int right){
	st[left] += lazy[me];
	st[right] += lazy[me];
	lazy[left] += lazy[me];
	lazy[right] += lazy[me];
	lazy[me] = 0;
}

lli query(int me, int ss, int se, int qs, int qe){ //finds max in [qs, qe]
	if (ss > qe || se < qs){
		return 0;
	}
	if (ss >= qs && se <= qe){
		return st[me];
	}

	int left = 2 * me, right = 2 * me + 1, mid = (ss + se) / 2;
	propagate(me, left, right);

	lli ql = query(2 * me, ss, mid, qs, qe), qr = query(2 * me + 1, mid + 1, se, qs, qe);
	return max(ql, qr);
}

void update(int me, int ss, int se, int us, int ue, int val){ //add val to everything in [us, ue]
	if (ss > ue || se < us){
		return;
	}
	if (ss >= us && se <= ue){
		st[me] += val;
		lazy[me] += val;
		return;
	}

	int left = 2 * me, right = 2 * me + 1, mid = (ss + se) / 2;
	propagate(me, left, right);

	update(left, ss, mid, us, ue, val);
	update(right, mid + 1, se, us, ue, val);

	st[me] = max(st[left], st[right]);
}

void solve(){
    int len, q, l, r;
	lli res, n;
	cin >> len >> cap >> q;
	while (q--){
		cin >> l >> r >> n;
		res = query(1, 1, len, l, r - 1);
		if (res + n <= cap){
			cout << "T\n";
			update(1, 1, len, l, r - 1, n);
		}
		else{
			cout << "N\n";
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
