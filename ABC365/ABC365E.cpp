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

    int arr[n+5];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 0; i < 30; i++) {
        int cnt0 = 1, cnt1 = 0, cnt = 0;
        int now = 0;
        for (int j = 1; j <= n; j++) {
            //cout << cnt0 << " " << cnt1 << endl;
            if (arr[j] & (1 << i)) {
                now++;
                if (now % 2 == 0) {
                    cnt += cnt1 - 1;
                    cnt0++;
                }
                else {
                    cnt += cnt0 - 1;
                    cnt1++;
                }
            }
            else {
                if (now % 2 == 0) {
                    cnt += cnt1;
                    cnt0++;
                }
                else {
                    cnt += cnt0;
                    cnt1++;
                }
            }
        }
        ans += (1<<i) * cnt;
    }
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