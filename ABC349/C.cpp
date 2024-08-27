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
    string s, t;
    cin >> s >> t;

    int j = 0;

    for (int i = 0; i < s.length(); i++) {
      if (s[i] - 'a' == t[j] - 'A') j++;
    }

    if (j == 3) cout << "Yes" << endl;
    else {
      if (j == 2 && t[j] == 'X') cout << "Yes" << endl;
      else cout << "No" << endl;
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