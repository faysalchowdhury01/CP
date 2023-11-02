#include <bits/stdc++.h>
using namespace std;
const int N = 125;
int n, a[N];
long long prefix[N];
bitset<5005> vis[N][5005];
bitset<5005> dp[N][5005];

bool fun(int i, int sum1, int sum2) {
  if (i == 0) {
    if (sum1 == 0 and sum2 == 0) {
      return true;
    }
    return false;
  }
  if (vis[i][sum1][sum2]) return dp[i][sum1][sum2];
  bool ans = fun(i - 1, sum1, sum2);
  if (ans) {
    dp[i][sum1].set(sum2);
    return ans;
  }
  if (sum1 - a[i] >= 0) {
    ans = fun(i - 1, sum1 - a[i], sum2);
    if (ans) {
      dp[i][sum1].set(sum2);
      return ans;
    }
  }
  if (sum2 - a[i] >= 0) {
    ans = fun(i - 1, sum1, sum2 - a[i]);
    if (ans) {
      dp[i][sum1].set(sum2);
      return ans;
    }
  }
  return false;
}

int cs = 0;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] + a[i];
  }
  cout << "Case " << ++cs << ":\n";
  for (int i = 1; i <= n; i++) {
    if (prefix[i] % 3 == 0) {
      cout << fun(i, prefix[i] / 3, prefix[i] / 3) << '\n';
    }
    else {
      cout << 0 << '\n';
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}