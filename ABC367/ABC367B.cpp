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

void solve() {
    string s;
    cin >> s;

    int koma = -1;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == '.') {
            koma = i;
            break;
        }
    }

    int l = s.size() - 1;
    while (s[l] == '0') {
        l--;
    }

    if (koma == -1) {
        cout << s << endl;
    } else {
        if (l == koma) {
            cout << s.substr(0, koma) << endl;
        } else {
            cout << s.substr(0, l + 1) << endl;
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
