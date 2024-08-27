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

int expo(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

int divide(int a, int b) {
  a %= mod;
  b %= mod;
  return (a * expo(b, mod - 2)) % mod;
}

int multiply(int a, int b) {
  a %= mod;
  b %= mod;
  return (((a * b) % mod) + mod) % mod;
}

int add(int a, int b) {
  a %= mod;
  b %= mod;
  return (((a + b) % mod) + mod) % mod;
}

void solve() {
  int n, k;
  cin >> n >> k;

  int ans = 1;
  for (int i = 1; i <= k; i++) {
    int temp = 0;
    temp += multiply(multiply(divide(n-1, n), divide(n-1, n)), ans);
    temp += multiply(multiply(divide(1, n), divide(1, n)), ans);
    temp += 2*multiply(multiply(divide(1, n), divide(1, n)), (1 - ans));

    temp %= mod;
    temp = (temp + mod) % mod;

    ans = temp;
  }
  
  int x = ans;
  int y = divide((1 - ans + mod) % mod, n - 1);
  int sum = (n*(n+1))/2;

  sum--;
  cout << add(ans, multiply(sum, y)) << endl;
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