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
    int n, m;
    cin >> n >> m;

    int arr[n+5];
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    if (sum <= m) cout <<"infinite\n";
    else {
        int l = 0, r = 1e18, ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                sum += min(mid, arr[i]);
            }
            if (sum <= m) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        } 
        cout << ans << endl;
    }
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