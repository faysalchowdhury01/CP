#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int a = 1;
    for(int i = 2; i * i <= n; i++) {
      if(n % i == 0) {
        a = max(a, n / i);
      }
    }
    cout << a << ' ' << n - a << '\n';
  }

  return 0;
}