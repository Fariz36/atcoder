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

    int x = 0;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 1; i <= n; i++) {
        int l = 1, r = 1e9, ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;

            int sum = mid;
            sum += 2*(((x+mid)/3) - x/3);

            if (sum < arr[i]) {
                l = mid+1;
            }
            else {
                ans = mid;
                r = mid-1;
            }
        }
        x = x + ans;
        //cout << x << endl;
    }
    cout << x << endl;
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