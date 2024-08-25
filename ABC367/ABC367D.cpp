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

int r[9];
int n, k;
int arr[9];

void solve() {
    int n, m;
    cin >> n >> m;

    int arr[2*n+5];
    arr[0] = 0;

    map<int, int> cnt;
    cnt[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];

        if (i != n) cnt[(arr[i]) % m]++;
    }
    for (int i = n+1; i <= 2*n; i++) {
        arr[i] = arr[i-n] + arr[i-1] - arr[i-n-1];
    }

    
    int ans = 0;
    for (int i = n; i < 2*n; i++) {
        int temp = ans;
        
        //cout << arr[i] % m << " " << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
        ans += cnt[(arr[i]) % m];
        cnt[(arr[i-n]) % m]--;
        cnt[(arr[i]) % m]++;

        //cout << i << " " << ans - temp << endl;
    }

    cout << ans << endl;
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
