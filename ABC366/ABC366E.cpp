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

const int N = 2e5 + 5;

int x[N], y[N];
int prefx[N], prefy[N];
int n, d;

int cnt(int a, int b) {
  int xx = 0, yy = 0;
  int pos = lower_bound(x+1, x+n+1, a) - x;
  xx = (pos-1)*a - prefx[pos-1] + (prefx[n]-prefx[pos-1])-(n-pos+1)*a;

  pos = lower_bound(y+1, y+n+1, b) - y;
  yy = (pos-1)*b - prefy[pos-1] + (prefy[n]-prefy[pos-1])-(n-pos+1)*b;

  return xx + yy;
}

void solve() {
  cin >> n >> d;

  rep(i, 1, n+1) {
    cin >> x[i] >> y[i];
  }
  sort(x+1, x+n+1);
  sort(y+1, y+n+1);
  for (int i = 1; i <= n; i++) {
    prefx[i] = prefx[i-1] + x[i];
    prefy[i] = prefy[i-1] + y[i];
  }

  int medx = x[(n+1)/2];
  int medy = y[(n+1)/2];

  int l = medx, r = medx+1;
  bool melebar = 1;
  int ans = 0;

  for (int i = y[n] - d - 1; i <= y[1] + d + 1; i++) {
    
    if (cnt(l, i) <= d) while (cnt(l, i) <= d) l--;
    else while (cnt(l+1, i) > d && l+1 <= medx) l++;

    if (cnt(r, i) <= d) while (cnt(r, i) <= d) r++;
    else while (cnt(r-1, i) > d && r-1 >= medx) r--;

    if (r == l) continue;
    //cout << "hitung : " << i << " " << l << " " << r << endl;
    ans += r - l - 1;
  }

  cout << ans << endl;
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