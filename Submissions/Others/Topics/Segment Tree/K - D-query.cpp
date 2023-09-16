#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 3e4 + 9, QQ = 2e5 + 9;
int a[N], ans[QQ];
vector<pair<int, int>> Q[QQ]; 

struct ST {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = 0; // change here
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r]; // change here
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] += x; // change here
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = tree[l] + tree[r]; // change here
  }
  int query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return 0; // return appropriate value
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L + R); // change this
  }
} st;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int q; cin >> q;
  for(int i = 1; i <= q; i++) {
    int l, r; cin >> l >> r;
    Q[r].push_back({l, i});
  }

  st.build(1, 1, n);

  map<int, int> mp;
  for(int r = 1; r <= n; r++) {
    if(mp.find(a[r]) != mp.end()) {
      st.upd(1, 1, n, mp[a[r]], -1);
    }
    mp[a[r]] = r;
    st.upd(1, 1, n, r, 1);


    for(auto i: Q[r]) {
      int l = i.first, id = i.second;
      ans[id] = st.query(1, 1, n, l, r);
    }
  }

  for(int i = 1; i <= q; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}