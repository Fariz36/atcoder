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
const int N = 100069;

int state[N];
bool visited[N];
vector<int> divisor[N];

int f(int x) {
    if (x == 1) return 0;
    if (x == 2) return 1;
    if (visited[x]) return state[x];

    unordered_map<int, bool> st;
    for (auto d : divisor[x]) {
        st[f(d)] = true;
    }

    int mex = 0;
    while (st.count(mex)) mex++;

    visited[x] = true;
    return state[x] = mex;
}

void solve() {
    int n, k;
    cin >> n;

    for (int i = 1; i < N; i++) {
        for (int j = 2*i; j < N; j += i) {
            divisor[j].pb(i);
        }
    }

    for (int i = 1; i < N; i++) {
        state[i] = f(i);
    }

    int arr[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans ^= state[arr[i]];
    }

    if (ans == 0) cout << "Bruno" << endl;
    else cout << "Anna" << endl;
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
