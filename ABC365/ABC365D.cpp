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
    int n;
    cin >> n;

    string s;
    cin >> s;
    s = " " + s;

    int dp[n + 5][3];
    memset(dp, 0, sizeof dp);
    //0 mean P, 1 mean S, 2 mean R
    if (s[1] == 'R') dp[1][0] = 1;
    if (s[1] == 'P') dp[1][1] = 1;
    if (s[1] == 'S') dp[1][2] = 1;

    for (int i = 2; i <= n; i++) {
        if (s[i] == 'R') {
            dp[i][1] = -1e18;
            dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + 1;
            dp[i][2] = max(dp[i-1][1], dp[i-1][0]);
        }
        if (s[i] == 'P') {
            dp[i][2] = -1e18;
            dp[i][0] = max(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + 1;
        }
        if (s[i] == 'S') {
            dp[i][0] = -1e18;
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + 1;
        }
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
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