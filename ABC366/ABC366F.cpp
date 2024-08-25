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

ii arr[N];

bool comp(ii p, ii q) {
  return p.se*(q.fi - 1) > q.se*(p.fi - 1);
}

void solve() {
  int n, k;
  cin >> n >> k;

  int dp[n+5][k+5];
  for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++) dp[i][j] = -1e9;
  for (int i = 0; i <= n; i++) dp[i][0] = 1;

  for (int i = 1; i <= n; i++) cin >> arr[i].fi >> arr[i].se;

  sort(arr + 1, arr + n + 1, comp);

  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      dp[j][i] = dp[j-1][i];
      if (dp[j-1][i-1] != -1e9) dp[j][i] = max(dp[j][i], dp[j-1][i-1]*arr[j].fi + arr[j].se);
    }
  }
  //cout << dp[2][1] << endl;
  cout << dp[n][k] << endl;
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