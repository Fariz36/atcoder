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
  rep(i, 1, n+1) cin >> arr[i];
  arr[0] = 1e18;

  stack<int> st;
  st.push(0);

  int area = 0;
  int ans[n+5];
  memset(ans, 0, sizeof ans);

  for (int i = 1; i <= n; i++) {
    while (arr[st.top()] < arr[i]) {
      int h = arr[st.top()];
      int w = st.top();
      st.pop();
      w = w - st.top();
      
      area -= h * w;
    }
    

    int h = arr[i];
    int w = i - st.top();

    st.push(i);
    
    area += h * w;

    ans[i] = area + 1;
  }

  rep(i, 1, n+1) {
    cout << ans[i] << " ";
  }
}

signed main() {;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc = 1;
  //cin >> tc;
  
  while (tc--) {
    solve();
  }
}