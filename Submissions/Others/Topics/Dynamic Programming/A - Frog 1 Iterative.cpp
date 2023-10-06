#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int n, height[N], dp[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, 0, sizeof dp);

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> height[i];
  }

  for(int i = n - 1; i >= 1; i--) {
    dp[i] = dp[i + 1] + abs(height[i + 1] - height[i]);
    if(i + 2 <= n) {
      dp[i] = min(dp[i], dp[i + 2] + abs(height[i + 2] - height[i]));
    }
  }

  cout << dp[1] << '\n';

  return 0;
}