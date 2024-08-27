#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vii vector<ii>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define endl '\n'
#define sz(x) (int)x.size()

const int mod = 998244353;

vector<ii> ans;

void f(int a, int b, int l, int r, int len) {
  if (a > r || b < l || len == 0) return;
  if (a >= l && b <= r) {
    if (a == b) return;
    ans.pb({a, b});
    return;
  }

  len /= 2;
  f(a, a + len, l, r, len);
  f(a + len, b, l, r, len);
}

void solve() {
    int l, r;
    cin >> l >> r;

    f(0, (1ll)<<60, l, r, (1ll)<<60);

    cout << sz(ans) << endl;
    for (auto x : ans) cout << x.fi << " " << x.se << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc = 1;
  //cin >> tc;
  
  while (tc--) {
    solve();
  }
}