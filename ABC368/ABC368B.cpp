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
    int n, k;
    cin >> n;

    int arr[n+5];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    sort(arr+1, arr+n+1);
    while (arr[n-1] != 0) {
        arr[n]--;
        arr[n-1]--;

        sort(arr+1, arr+n+1);
        ans++;
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