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

int arr[3][3];
int dp[19683];
int visited[19683];

int get(int mask, int i) {
  return (mask / (int)pow(3, i)) % 3;
}

int f(int mask, int turn = 1) {
  if (visited[mask]) return dp[mask];
  visited[mask] = 1;

  int cnt = 0;
  for (int i = 0; i < 9; i++) {
    if (get(mask, i) != 0) cnt++;
  }

  if (cnt == 9) return dp[mask] = 0;

  if (get(mask, 0) == get(mask, 1) && get(mask, 1) == get(mask, 2) && get(mask, 0) == 3-turn) return dp[mask] = -1e18;
  if (get(mask, 3) == get(mask, 4) && get(mask, 4) == get(mask, 5) && get(mask, 3) == 3-turn) return dp[mask] = -1e18;
  if (get(mask, 6) == get(mask, 7) && get(mask, 7) == get(mask, 8) && get(mask, 6) == 3-turn) return dp[mask] = -1e18;

  if (get(mask, 0) == get(mask, 3) && get(mask, 3) == get(mask, 6) && get(mask, 0) == 3-turn) return dp[mask] = -1e18;
  if (get(mask, 1) == get(mask, 4) && get(mask, 4) == get(mask, 7) && get(mask, 1) == 3-turn) return dp[mask] = -1e18;
  if (get(mask, 2) == get(mask, 5) && get(mask, 5) == get(mask, 8) && get(mask, 2) == 3-turn) return dp[mask] = -1e18;

  if (get(mask, 0) == get(mask, 4) && get(mask, 4) == get(mask, 8) && get(mask, 0) == 3-turn) return dp[mask] = -1e18;
  if (get(mask, 2) == get(mask, 4) && get(mask, 4) == get(mask, 6) && get(mask, 2) == 3-turn) return dp[mask] = -1e18;

  int sum = 0;
  for (int i = 0; i < 9; i++) {
    if (get(mask, i) == 0) {
      sum += arr[i / 3][i % 3];
    }
  }

  int ans = 1e18;
  
  for (int i = 0; i < 9; i++) {
    if (get(mask, i) == 0) {
      int new_mask = mask + (turn * (int)pow(3, i));
      ans = min(ans, f(new_mask, 3-turn));
    }
  }

  return dp[mask] = sum - ans;
}

void solve() {
  int sum = 0;
  rep(i, 0, 3) {
    rep(j, 0, 3) {
      cin >> arr[i][j];
      sum += arr[i][j];
    }
  }

  int ans = f(0);

  /*
  for (int i = 0; i < 19683; i++) {
    if (dp[i] == -1e18) {
      for (int j = 0; j < 9; j++) {
        cout << get(i, j) << " ";
        if (j % 3 == 2) cout << endl;
      }
      cout << endl;
    }
  }
  */

//cout << ans << endl;

  if (ans > sum - ans) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;
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