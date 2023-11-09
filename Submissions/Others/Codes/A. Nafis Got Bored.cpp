#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MIN = 1e9;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  map<int, int> mp;
  for (auto &x : a) {
    cin >> x;
    mp[x]++;
  }
  sort(a.begin(), a.end());
  int max_mex = 0;
  for (auto x : a) {
    if (max_mex == x) max_mex++;
  }
  int freq[max_mex];
  for (int i = 0; i < max_mex; i++) {
    int mn = min(30ll, mp[i]);
    freq[i] = (1 << mn) - 1;
  }
  for (int i = 1; i < max_mex; i++) {
    int mn = (int)(1ll * freq[i] * freq[i - 1]);
    freq[i] = min(MIN, mn);
  }

  int cur = max_mex;
  int add = (k + 1) / 2;
  int minus = k - add;
  long long ans = 0;

  while (minus > 0) {
    int right = n - (upper_bound(a.begin(), a.end(), cur) - a.begin());
    int mn = min(30ll, right);
    int possible = (1 << mn);
    if (cur == 0) {
      possible--;
      int apply = min(minus, possible);
      minus -= apply;
      ans -= (1ll * cur * apply);
    }
    else {
      possible = min(MIN, (int) (1ll * freq[cur - 1] * possible));
      int apply = min(minus, possible);
      minus -= apply;
      ans -= (1ll * cur * apply);
    }
    cur--;
  }

  cur = 0;
  while (add > 0) {
    int right = n - (upper_bound(a.begin(), a.end(), cur) - a.begin());
    int mn = min(30ll, right);
    int possible = (1 << mn);
    if (cur == 0) {
      possible--;
      int apply = min(add, possible);
      add -= apply;
      ans += (1ll * cur * apply);
    }
    else {
      possible = min(MIN, (int) (1ll * freq[cur - 1] * possible));
      int apply = min(add, possible);
      add -= apply;
      ans += (1ll * cur * apply);
    }
    cur++;
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}