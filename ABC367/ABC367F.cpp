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
#define endl '\n'
#define sz(x) (int)x.size()

const int N = 2e5+69;
const int mod = 1e9 + 7;
vector<int> cycle;
vector<int> adj[N];
bool vis[N];

void solve() {
    random_device rd; 
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<long long> dis(-1e13, 1e13);

    int n, q;
    cin >> n >> q;

    map<int, int> m;
    for (int i = 1; i <= n; i++) {
        m[i] = dis(rng);
    }

    int a[n+5], b[n+5];
    a[0] = b[0] = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        a[i] = m[x];
        a[i] += a[i-1];
    }

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        b[i] = m[x];
        b[i] += b[i-1];
    }

    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int x = a[r1] - a[l1-1];
        int y = b[r2] - b[l2-1];

        if (x == y) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
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
