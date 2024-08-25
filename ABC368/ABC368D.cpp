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
const int N = 2e5 + 69;

vector<int> adj[N];
int arr[N];
int ans;

void dfs(int u, int p = -1) {
    for (auto v : adj[u]) {
        if (v == p) continue;

        dfs(v, u);

        arr[u] += arr[v];
    }

    if (arr[u] == 0) ans--;
}

void solve() {
    int n, k;
    cin >> n >> k;

    ans = n;

    int root = 0;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;

        arr[x] = 1;
        root = x;
    }

    dfs(root);

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