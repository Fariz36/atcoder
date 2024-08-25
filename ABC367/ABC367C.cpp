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

const int mod = 1e9 + 7;

int r[9];
int n, k;
int arr[9];

void perm(int now) {
    if (now > n) {
        int sum = 0;
        rep(i, 1, n + 1) {
            sum += arr[i];
        }
        if (sum % k == 0) {
            rep(i, 1, n + 1) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    else {
        for (int i = 1; i <= r[now]; i++) {
            arr[now] = i;
            perm(now + 1);
        }
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> r[i];

    perm(1);
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
