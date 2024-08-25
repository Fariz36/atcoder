#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;

using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 

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
//#define endl '\n'
#define sz(x) (int)x.size()

const int N = 2e5+69;
const int mod = 1e9 + 7;
vector<int> cycle;
vector<int> adj[N];
bool vis[N];

void solve() {
    int n, k;
    cin >> n >> k;

    int par[n+1][65];
    int arr[n+1];
    for (int i = 1; i <= n; i++) cin >> par[i][0];
    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 1; i <= 60; i++) {
        for (int j = 1; j <= n; j++) {
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }

    for (int i = 1; i <= n; i++) {
        int x = k;
        int ans = i;
        for (int j = 0; j <= 60; j++) {
            if (x & (1LL << j)) {
                ans = par[ans][j];
            }
        }
        cout << arr[ans] << " ";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc = 1;
    // cin >> tc;
  
    while (tc--) {
        solve();
    }
}
