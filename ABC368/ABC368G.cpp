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

vector<int> arr(N), brr(N);
int n;

struct segtree{
    // segment tree bottom up traversal
    // 0-indexing, left child is 2*i, right child is 2*i+1, parent is floor(i/2)
    // template for sum range
    int n;
    vector<int> segment;
    int init = 0; // initialize array value
    int operation(int a, int b){return a+b;} // segment tree operation
    segtree(vector<int> array){
        n = log2(array.size()-1) + 1;
        n = (1<<n);
        segment = vector<int>(2*n, init);
        for(int i=0;i<n;i++){
            if (brr[i] == 1) add(i, array[i]);
        }
    }
    void add(int idx, int val){
        idx += n;
        segment[idx] += val;
        for(idx/=2;idx>=1;idx/=2){
            segment[idx] = operation(segment[2*idx], segment[2*idx + 1]); 
        }
    }
    int sum(int l, int r) {
        if (r < l) return 0;

        l += n;
        r += n;
        int ans = init;
        while (l <= r) {
            if (l%2 == 1) ans = operation(ans, segment[l++]);
            if (r%2 == 0) ans = operation(ans, segment[r--]);
            l /= 2; r /= 2;
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;

    arr.resize(n);
    brr.resize(n);

    multiset<int> pos;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> brr[i];

        if (brr[i] != 1) {
            pos.insert(i);
        }
    }
    pos.insert(n);

    segtree st(arr);

    int q;
    cin >> q;

    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            b--;
            st.add(b, c - arr[b]);
            arr[b] = c;
        }
        else if (a == 2) {
            b--;
            
            if (brr[b] == 1 && c != 1) {
                pos.insert(b);
                st.add(b, -arr[b]);
            }
            else if (brr[b] != 1 && c == 1) {
                pos.erase(pos.find(b));
                st.add(b, arr[b]);
            }

            brr[b] = c;
        }
        else if (a == 3) {
            b--;
            c--;

            auto it = pos.lower_bound(b);
            
            vector<int> v;
            while (*it <= c) {
                v.push_back(*it);
                it++;

                if (it == pos.end()) {
                    break;
                }
            }

            int dp[v.size() + 1];
            memset(dp, 0, sizeof dp);
            dp[0] = 0;

            int bef = b;
            int sz = v.size();
            for (int i = 1; i <= sz; i++) {
                dp[i-1] += st.sum(bef, v[i-1] - 1);
                dp[i] = max(arr[v[i-1]] + dp[i-1], brr[v[i-1]] * dp[i-1]);
                bef = v[i-1] + 1;
            }

            cout << dp[sz] + st.sum(bef, c) << endl;
        }
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