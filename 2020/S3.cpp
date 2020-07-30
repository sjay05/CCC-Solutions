#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 972663749, mod2 = 972663749;
const ll base = 31, base2 = 131;

struct PolyHash {
  vector<ll> p, p2, h, h2;

  void init(string s) {
    p.resize(s.size() + 1);
    p2.resize(s.size() + 1);
    h.resize(s.size() + 1);
    h2.resize(s.size() + 1);
    p[0] = 1; p2[0] = 1;
    int n = (int) s.size();
    for (int i = 1; i <= n; i++) {
      p[i] = p[i - 1] * base % mod;
      p2[i] = p2[i - 1] * base2 % mod2;
    }
    h[0] = s[0] - 'a' + 1;
    h2[0] = s[0] - 'a' + 1;
    for (int i = 1; i < n; i++) {
      h[i] = (h[i - 1] * base % mod + (s[i] - 'a' + 1)) % mod;
      h2[i] = (h2[i - 1] * base2 % mod2 + (s[i] - 'a' + 1)) % mod2;
    }
  }
  pair<ll,ll> get(int i, int j) {
    if (i == 0) {
      return {h[j], h2[j]};
    } else {
      ll v1 = (h[j] - h[i - 1] * p[j - (i - 1)] % mod + mod) % mod;
      ll v2 = (h2[j] - h2[i - 1] * p2[j - (i - 1)] % mod2 + mod2) % mod2;
      return {v1, v2};
    }
  }
};

string n, h;
PolyHash ht;
set<pair<ll,ll>> st;
int fn[26], fh[26];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> h;
  ht.init(h);
  for (int i = 0; i < n.size(); i++) {
    int ch = n[i] - 'a';
    fn[ch]++;
  }
  for (int i = 0; i < n.size(); i++) {
    int ch = h[i] - 'a';
    fh[ch]++;
  }
  int en = h.size() - n.size();
  for (int i = 0; i + n.size() <= h.size(); i++) {
    bool perm = true;
    for (int c = 0; c < 26; c++) {
      if (fn[c] != fh[c]) {
        perm = false;
        break;
      }
    }
    if (perm) {
      st.insert(ht.get(i, i + n.size() - 1));
    }
    if (i != en) {
      int ch1 = h[i + n.size()] - 'a';
      int ch2 = h[i] - 'a';
      fh[ch1]++; fh[ch2]--;
    }
  }
  cout << st.size() << "\n";
}
