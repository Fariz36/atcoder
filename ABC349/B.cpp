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
    int cnt[26] = {0};
    string s;
    cin >> s;

    for (char c : s) {
        cnt[c - 'a']++;
    }

    for (int i = 1; i <= 100; i++) {
      int ada = 0;
      for (int j = 0; j < 26; j++) {
        if (cnt[j] == i) ada++;
      }

      if (ada == 0 || ada == 2) continue;
      cout << "No" << endl;
      return;
    }

    cout << "Yes" << endl;
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