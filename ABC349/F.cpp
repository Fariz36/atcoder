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

const int N = 2e5+69;
const int M = 1<<13;
int p2[N];

void solve() {
  int n, m;
  cin >> n >> m;

  p2[0] = 1;
  for (int i = 1; i < N; i++) {
    p2[i] = (p2[i-1] * 2) % mod;
  }

  if (m == 1) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;

      if (x == 1) cnt++;
    }

    cout << p2[cnt] - 1 << endl;
    return;
  }

  vector<ii> v;
  int temp = m;
  for (int i = 2; i*i <= m; i++) {
    if (i > temp) break;

    int cnt = 0;
    if (temp % i == 0) {
      while (temp % i == 0) {
        temp /= i;
        cnt++;
      }
      v.pb({i, cnt});
    }
  }
  if (temp > 1) {
    v.pb({temp, 1});
  }

  int arr[n+69], cnt[(1<<13)];
  memset(cnt, 0, sizeof cnt);

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];

    int mask = 0;
    if (m % arr[i] == 0) {
      for (int j = 0; j < v.size(); j++) {
        if (arr[i] % (int)pow(v[j].fi, v[j].se) == 0) {
          mask += (1<<j);
        }
      }

      cnt[mask]++;
    }
  }

  int M = 1<<v.size();

  int dp[M];
  memset(dp, 0, sizeof dp);
  dp[0] = p2[cnt[0]];

  for (int mask = 1; mask < M; mask++) {
    int new_dp[M];
    for (int i = 0; i < M; i++) new_dp[i] = dp[i];

    for (int i = M-1; i > 0; i--) {
      for (int j = 0; j < M; j++) {
        if ((j | mask) == i) {
          new_dp[i] += dp[j]*(p2[cnt[mask]] - 1);
          new_dp[i] %= mod;
        }
      }
    }

    for (int j = 0; j < M; j++) {
      dp[j] = new_dp[j];
    }
  }

  cout << dp[M - 1] % mod << endl;
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