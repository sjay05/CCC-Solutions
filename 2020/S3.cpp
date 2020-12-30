/*
 *  author: sjay05
 */
#include <bits/stdc++.h>

using namespace std;

#include <unistd.h>

template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

struct Scanner {
  int fd = -1;
  char line[(1 << 15) + 1];
  size_t st = 0, ed = 0;
  void reread() {
    memmove(line, line + st, ed - st);
    ed -= st;
    st = 0;
    ed += ::read(fd, line + ed, (1 << 15) - ed);
    line[ed] = '\0';
  }
  bool succ() {
    while (true) {
      if (st == ed) {
        reread();
        if (st == ed) return false;
      }
      while (st != ed && isspace(line[st])) st++;
      if (st != ed) break;
    }
    if (ed - st <= 50) {
      bool sep = false;
      for (size_t i = st; i < ed; i++) {
        if (isspace(line[i])) {
          sep = true;
          break;
        }
      }
      if (!sep) reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
  bool read_single(T& ref) {
    if (!succ()) return false;
    while (true) {
      size_t sz = 0;
      while (st + sz < ed && !isspace(line[st + sz])) sz++;
      ref.append(line + st, sz);
      st += sz;
      if (!sz || st != ed) break;
      reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  bool read_single(T& ref) {
    if (!succ()) return false;
    bool neg = false;
    if (line[st] == '-') {
      neg = true;
      st++;
    }
    ref = T(0);
    while (isdigit(line[st])) {
      ref = 10 * ref + (line[st++] & 0xf);
    }
    if (neg) ref = -ref;
    return true;
  }
  template <class T> bool read_single(V<T>& ref) {
    for (auto& d : ref) {
      if (!read_single(d)) return false;
    }
    return true;
  }
  template <class T> bool read_single(array<T,2>& ref) {
    if (!read_single(ref[0])) return false;
    if (!read_single(ref[1])) return false;
    return true;
  }
  template <class T> bool read_single(array<T,3>& ref) {
    if (!read_single(ref[0])) return false;
    if (!read_single(ref[1])) return false;
    if (!read_single(ref[2])) return false;
    return true;
  }
  template <class T> bool read_single(array<T,4>& ref) {
    if (!read_single(ref[0])) return false;
    if (!read_single(ref[1])) return false;
    if (!read_single(ref[2])) return false;
    if (!read_single(ref[3])) return false;
    return true;
  }
  void read() {}
  template <class H, class... T> void read(H& h, T&... t) {
    bool f = read_single(h);
    assert(f);
    read(t...);
  }
  Scanner(FILE* fp) : fd(fileno(fp)) {}
};
 
struct Printer {
public:
  template <bool F = false> void write() {}
  template <bool F = false, class H, class... T>
  void write(const H& h, const T&... t) {
    if (F) write_single(' ');
    write_single(h);
    write<true>(t...);
  }
  template <class... T> void writeln(const T&... t) {
    write(t...);
    write_single('\n');
  }

  Printer(FILE* _fp) : fp(_fp) {}
  ~Printer() { flush(); }

private:
  static constexpr size_t SIZE = 1 << 15;
  FILE* fp;
  char line[SIZE], small[50];
  size_t pos = 0;
  void flush() {
    fwrite(line, 1, pos, fp);
    pos = 0;
  }
  void write_single(const char& val) {
    if (pos == SIZE) flush();
    line[pos++] = val;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  void write_single(T val) {
    if (pos > (1 << 15) - 50) flush();
    if (val == 0) {
      write_single('0');
      return;
    }
    if (val < 0) {
      write_single('-');
      val = -val; // todo min
    }
    size_t len = 0;
    while (val) {
      small[len++] = char(0x30 | (val % 10));
      val /= 10;
    }
    for (size_t i = 0; i < len; i++) {
      line[pos + i] = small[len - 1 - i];
    }
    pos += len;
  }
  void write_single(const string& s) {
    for (char c : s) write_single(c);
  }
  void write_single(const char* s) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++) write_single(s[i]);
  }
  template <class T> void write_single(const V<T>& val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write_single(' ');
      write_single(val[i]);
    }
  }
};

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

typedef uint64_t HT;
 
mt19937 rng(787788789);
 
struct hash61 {
  static const HT md = (1LL << 61) - 1;
  static HT step;
  static vector<HT> pw;
 
  static HT addmod(HT a, HT b) {
    a += b;
    if (a >= md) a -= md;
    return a;
  }
 
  static HT submod(HT a, HT b) {
    a += md - b;
    if (a >= md) a -= md;
    return a;
  }
 
  static HT mulmod(HT a, HT b) {
    HT l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
    HT l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    HT ret = (l & md) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & md) + (ret >> 61);
    ret = (ret & md) + (ret >> 61);
    return ret - 1;
  }
 
  void ensure_pw(int sz) {
    int cur = (int) pw.size();
    if (cur < sz) {
      pw.resize(sz);
      for (int i = cur; i < sz; i++) {
        pw[i] = mulmod(pw[i - 1], step);
      }
    }
  }
 
  vector<HT> pref;
  int n;
 
  template<typename T>
  hash61(const T& s) {
    n = (int) s.size();
    ensure_pw(n + 1);
    pref.resize(n + 1);
    pref[0] = 1;
    for (int i = 0; i < n; i++) {
      pref[i + 1] = addmod(mulmod(pref[i], step), s[i]);
    }
  }
 
  inline HT operator()(const int from, const int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    return submod(pref[to + 1], mulmod(pref[from], pw[to - from + 1]));
  }
};
 
HT hash61::step = (md >> 2) + rng() % (md >> 1);
vector<HT> hash61::pw = vector<HT>(1, 1);  

int main() {
#ifdef lc
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  string n, h;
  sc.read(n, h);
  vector<int> fn(27);
  vector<int> fh(27);
  for (int i = 0; i < (int) n.size(); i++) {
    fn[n[i] - 'a'] += 1;
  }
  for (int i = 0; i < (int) n.size(); i++) {
    fh[h[i] - 'a'] += 1;
  }
  hash61 ht(h);
  set<long long> st;
  int end = h.size() - n.size();
  for (int i = 0; i + n.size() <= h.size(); i++) {
    bool perm = true;
    for (int c = 0; c < 26; c++) {
      if (fn[c] != fh[c]) {
        perm = false;
        break;
      }
    }
    if (perm) {
      st.insert(ht(i, i + n.size() - 1));
    }
    if (i != end) {
      int ch1 = h[i + n.size()] - 'a';
      int ch2 = h[i] - 'a';
      fh[ch1] += 1;
      fh[ch2] -= 1;
    }
  }
  pr.writeln(st.size());
  return 0;
}
