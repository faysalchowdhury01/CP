#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 9;
int a[N][N];
long long prefix[N][N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a[i][j];
    }
  }

  // prefix sum of the matrix
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << prefix[i][j] << ' ';
    }
    cout << '\n';
  }

  int q; cin >> q;
  while (q--) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    cout << prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1] << '\n';
  }

  return 0;
}