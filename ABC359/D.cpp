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

void solve() {
  int n, k;
  string s;

  cin >> n >> k >> s;

  int dp[n+5][(1<<k)];
  memset(dp, 0, sizeof dp);

  for (int mask = 0; mask < (1<<k); mask++) {
    int ada = 1;
    for (int i = 0; i < k; i++) {
      if ((mask & (1<<i)) && s[i] == 'A') ada = 0;
      if (!(mask & (1<<i)) && s[i] == 'B') ada = 0;
    }

    if (ada) {
      bool pal = 1;
      for (int i = 0; i < k/2; i++) {
        if (((mask>>i) & 1) != ((mask>>(k-i-1)) & 1)) pal = 0;
      }

      if (pal) ada = 0;
    }
    dp[0][mask] = ada;

    //cout << 0 << " " << mask << " " << dp[0][mask] << endl;
  }

  for (int i = 1; i <= n-k; i++) {
    for (int mask = 0; mask < (1<<k); mask++) {
      //check if valid
      bool valid = 1;
      for (int j = 0; j < k; j++) {
        if (mask & (1<<j) && s[i+j] == 'A') valid = 0;
        if (!(mask & (1<<j)) && s[i+j] == 'B') valid = 0;
      }

      bool pal = 1;
      for (int j = 0; j < k/2; j++) {
        if (((mask>>j) & 1) != ((mask>>(k-j-1)) & 1)) pal = 0;
      }
      if (pal) valid = 0;

      int mask_prev_0 = 0, mask_prev_1 = 0;
      if (!valid) dp[i][mask] = 0;
      else {
        mask_prev_0 = (mask & ((1<<(k-1))-1)) << 1;
        mask_prev_1 = mask_prev_0 | 1;

        dp[i][mask] = dp[i-1][mask_prev_0] + dp[i-1][mask_prev_1];
        dp[i][mask] %= mod;
      }

      //cout << i << " " << mask << " " << mask_prev_0 << " " << mask_prev_1 << " " << dp[i][mask] << endl;
    }
  }

  int ans = 0;
  for (int mask = 0; mask < (1<<k); mask++) {
    ans += dp[n-k][mask];
    ans %= mod;
  }

  cout << ans << endl;
}

signed main() {;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc = 1;
  //cin >> tc;
  
  while (tc--) {
    solve();
  }
}