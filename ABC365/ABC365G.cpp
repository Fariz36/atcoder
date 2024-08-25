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

    vector<ii> line[n+5];
    for (int i = 1; i <= n; i++) {
        line[i].pb(mp(-1, -1));
    }

    for (int i = 1; i <= m; i++) {
        int t, p;
        cin >> t >> p;

        if (line[p].empty() || line[p].back().se != 0)
            line[p].pb(mp(t, 0));
        else {
            line[p].back().se = t;
        }
    }
    vector<int> pref[n+5];
    for (int i = 1; i <= n; i++) {
        line[i].pb(mp(1e9, 1e9));
        pref[i].pb(line[i][0].se - line[i][0].fi);
        for (int j = 1; j < sz(line[i]); j++) {
            pref[i].pb(pref[i].back() + line[i][j].se - line[i][j].fi);
        }
    }
    
    int q;
    cin >> q;

    map<ii, int> ada;
    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;

        if (line[b].size() < line[a].size()) {
            swap(a, b);
        }

        if (ada[mp(a, b)]) {
            cout << ada[mp(a, b)] << endl;
            continue;
        }

        int ans = 0;
        for (int i = 1; i < sz(line[a]) - 1; i++) {
            int l = lower_bound(all(line[b]), mp(line[a][i].fi, 0ll)) - line[b].begin();
            if (line[b][l-1].se > line[a][i].fi) l--;
            int r = lower_bound(all(line[b]), mp(line[a][i].se, 0ll)) - line[b].begin();
            if (r != 1) r--;

            //cout << l << ' ' << r << endl;
            if (l == r) {
                ans += max(0ll, min(line[a][i].se, line[b][r].se) - max(line[a][i].fi, line[b][l].fi));
            }
            else {
                ans += pref[b][r] - pref[b][l-1];
                
                if (line[b][l].fi < line[a][i].fi) {
                    ans -= line[a][i].fi - line[b][l].fi;
                }
                if (line[b][r].se > line[a][i].se) {
                    ans -= line[b][r].se - line[a][i].se;
                }
            }
        }

        cout << ans << endl;
        ada[mp(a, b)] = ans;
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