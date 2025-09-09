#pragma region Macros

/*************** Includes **************/
#if defined(__has_include)
  #if __has_include(<bits/stdc++.h>)
    #include <bits/stdc++.h>
    #define HAS_BITS_STDCPP 1
  #else
    #define HAS_BITS_STDCPP 0
  #endif
#else
  #define HAS_BITS_STDCPP 0
#endif

#if !HAS_BITS_STDCPP
  #include <algorithm>
  #include <array>
  #include <bitset>
  #include <cassert>
  #include <cctype>
  #include <cerrno>
  #include <cfenv>
  #include <cfloat>
  #include <cinttypes>
  #include <climits>
  #include <cmath>
  #include <complex>
  #include <cstdarg>
  #include <cstddef>
  #include <cstdint>
  #include <cstdio>
  #include <cstdlib>
  #include <cstring>
  #include <deque>
  #include <functional>
  #include <iomanip>
  #include <ios>
  #include <iosfwd>
  #include <iostream>
  #include <iterator>
  #include <limits>
  #include <list>
  #include <map>
  #include <numeric>
  #include <queue>
  #include <random>
  #include <set>
  #include <stack>
  #include <string>
  #include <tuple>
  #include <type_traits>
  #include <unordered_map>
  #include <unordered_set>
  #include <utility>
  #include <vector>
#endif

/************** PBDS (optional) **************/
#if defined(__has_include)
  #if __has_include(<ext/pb_ds/assoc_container.hpp>)
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    #define HAS_PBDS 1
    using namespace __gnu_pbds;
  #else
    #define HAS_PBDS 0
  #endif
#else
  #define HAS_PBDS 0
#endif

#if HAS_PBDS
  template<class T>
  using ordered_set = tree<T, null_type, std::less<T>,
                           rb_tree_tag, tree_order_statistics_node_update>;
  template<class K, class V, class Cmp = std::less<K>>
  using ordered_map = tree<K, V, Cmp,
                           rb_tree_tag, tree_order_statistics_node_update>;
#else
  #include <set>
  #include <map>
  template<class T>
  using ordered_set = std::set<T>;
  template<class K, class V, class Cmp = std::less<K>>
  using ordered_map = std::map<K,V,Cmp>;
#endif

using namespace std;

/************** Size helpers (safe & portable) **************/
namespace util {
  // ssize: signed size (C++20 has std::ssize; provide a polyfill otherwise)
  #if defined(__cpp_lib_ssize) && __cpp_lib_ssize >= 201907L
    using std::ssize; // C++20
  #else
    template <class C>
    constexpr auto ssize(const C& c)
      -> std::make_signed_t<decltype(c.size())> {
      using R = std::make_signed_t<decltype(c.size())>;
      return static_cast<R>(c.size());
    }
    template <class T, size_t N>
    constexpr ptrdiff_t ssize(const T (&)[N]) noexcept {
      return static_cast<ptrdiff_t>(N);
    }
  #endif

  // isize: int に丸めたサイズ（競プロ用途）。必要なら INT_MAX チェックを入れてください。
  template <class C>
  constexpr int isize(const C& c){
    auto s = ssize(c);
    // assert(s <= std::numeric_limits<int>::max()); // 任意
    return static_cast<int>(s);
  }
}

// 使いやすいように持ってくる（グローバルに汚染したくない場合は削ってOK）
using util::isize; // e.g., rep(i, isize(v))
// using util::ssize; // 必要ならアンコメントして利用

/************** OS / Compiler detection **************/
#if defined(__APPLE__) && defined(__MACH__)
  #define OS_MAC 1
#else
  #define OS_MAC 0
#endif

#if defined(__linux__)
  #define OS_LINUX 1
#else
  #define OS_LINUX 0
#endif

#if defined(_MSC_VER)
  #define COMPILER_MSVC 1
#else
  #define COMPILER_MSVC 0
#endif

#if defined(__clang__)
  #define COMPILER_CLANG 1
#else
  #define COMPILER_CLANG 0
#endif

#if defined(__GNUG__)
  #define COMPILER_GCC 1
#else
  #define COMPILER_GCC 0
#endif

/************** Fast IO **************/
static inline void FAST_IO() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

/************** Type aliases **************/
using ll  = long long;
using ull = unsigned long long;
#if defined(__SIZEOF_INT128__)
  using i128 = __int128_t;
  using u128 = __uint128_t;
#endif
using ld  = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

template <typename T> using vc   = vector<T>;
template <typename T> using vvc  = vector<vector<T>>;
template <typename T> using vvvc = vector<vector<vector<T>>>;
using vi  = vc<int>;
using vl  = vc<ll>;
using vpi = vc<pii>;
using vpl = vc<pll>;

template <class T> using pq  = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

/************** Macros **************/
#define nl '\n'              // newline (portable, faster than std::endl)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
//#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rrep(i,n) for (int i=(int)(n)-1;i>=0;--i)
#define fore(i,a,b) for (int i=(int)(a); i<(int)(b); ++i)

#ifndef ONLINE_JUDGE
  #define debug(x) cerr << "[debug] " << #x << " = " << (x) << nl
#else
  #define debug(x)
#endif

/************** Constants **************/
const int    INF  = (int)1e9;
const ll     LINF = (ll)4e18; // safe big ll
const double EPS  = 1e-9;
const int    MOD  = 1'000'000'007;
//const int    MOD  = 998244353;
const double PI   = acos(-1.0);
constexpr int MAXN   = 200000 + 5;
constexpr int MAXLOG = 20;

/************** Grid directions **************/
constexpr pii dx4[4] = {{1,0},{0,1},{-1,0},{0,-1}};
constexpr pii dx8[8] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

/************** RNG **************/
static random_device rd;
static mt19937_64 rng((uint64_t)chrono::steady_clock::now().time_since_epoch().count() ^ ((uint64_t)rd()<<1));

/************** Utilities **************/
// gcd / lcm
static inline ll gcd_custom(ll a, ll b){
  while(b){ ll t=a%b; a=b; b=t; } return a;
}
static inline ll lcm_custom(ll a, ll b){
  return (a/gcd_custom(a,b))*b;
}

// ceil/floor for integers with negatives handled
template <class T, class S> static inline T div_floor(T x, S y){
  assert(y); if ((x^y)>=0) return x/ y; return - ( ( -x + y - 1 ) / y );
}

template <class T, class S> static inline T div_ceil(T x, S y){
  assert(y); if ((x^y)>=0) return (x + y - 1) / y; return - ( (-x)/y );
}

// pow for integers (fast exponentiation)
template <class T> static inline T POW(T x, long long n){
  T res = 1; while(n){ if(n&1) res *= x; x *= x; n >>= 1; } return res;
}

// Combination helper with modular arithmetic
template <class T> struct Comb {
  vector<T> fac, ifac; T MODV;
  Comb(int n, T mod): fac(n+1), ifac(n+1), MODV(mod){
    fac[0]=1; for(int i=1;i<=n;++i) fac[i]= (T)( ( (__int128)fac[i-1]*i ) % MODV );
    ifac[n]=mod_pow(fac[n], MODV-2);
    for(int i=n;i>0;--i) ifac[i-1]=(T)( ( (__int128)ifac[i]*i ) % MODV );
  }
  T mod_pow(T a, long long e) const { T r=1%MODV; a%=MODV; while(e){ if(e&1) r=(T)(((__int128)r*a)%MODV); a=(T)(((__int128)a*a)%MODV); e>>=1;} return r; }
  T fact(int n)  const { return fac[n]; }
  T comb(int n,int k) const { if(k<0||k>n) return 0; return (T)(((__int128)fac[n]*ifac[k])%MODV*ifac[n-k]%MODV); }
  T perm(int n,int k) const { if(k<0||k>n) return 0; return (T)(((__int128)fac[n]*ifac[n-k])%MODV); }
};

// prefix sums
template <class T> vector<T> RUI(const vector<T>& v){
  vector<T> res(v.size()+1); for(size_t i=0;i<v.size();++i) res[i+1]=res[i]+v[i]; return res;
}

// coordinate compression
template <class T> void zip(vector<T>& v){
  vector<T> t=v; sort(all(t)); t.erase(unique(all(t)), t.end());
  for(auto& x: v) x = (int)(lower_bound(all(t), x)-t.begin());
}

// primality (trial division)
static inline bool is_prime(long long n){
  if(n<2) return false; if(n%2==0) return n==2; for(long long p=3; p*p<=n; p+=2) if(n%p==0) return false; return true;
}

// integer binary search: f(mid) must be monotone
// returns last ok given initial ok,ng with f(ok)=true, f(ng)=false
// (typical: ok = -1, ng = N for lower_bound-like search)
template <class T, class F> T bin_search(T ok, T ng, F f){
  while ( (ok>ng ? ok-ng : ng-ok) > 1 ){
    T mid = ok + (ng - ok) / 2; // avoid overflow
    (f(mid) ? ok : ng) = mid;
  }
  return ok;
}

// floating binary search
template <class T, class F> T bin_search_double(T ok, T ng, F f, int iter=80){
  while(iter--){ T mid = (ok+ng)/2; (f(mid) ? ok : ng) = mid; } return ok;
}

/************** IO helpers **************/
template <class T> void read_vector(vector<T>& v, int n){ v.resize(n); for(auto& x: v) cin >> x; }

template <class T> void print_vector(const vector<T>& v){ for(const auto& x: v) cout << x << ' '; cout << nl; }

inline void YesNo(bool c){ cout << (c?"Yes":"No") << '\n'; }
inline void YESNO(bool c){ cout << (c?"YES":"NO") << '\n'; }
inline void yesno(bool c){ cout << (c?"yes":"no") << '\n'; }

// keep misspelling aliases for backward-compat (prints "False")
inline void TrueFulse(bool c){ cout << (c?"True":"False") << '\n'; }
inline void TRUEFULSE(bool c){ cout << (c?"TRUE":"FALSE") << '\n'; }
inline void truefulse(bool c){ cout << (c?"true":"false") << '\n'; }

/************** i128 printing (guarded) **************/
#if defined(__SIZEOF_INT128__)
static inline string to_string_i128(i128 x){
  if(x==0) return "0"; bool neg = x<0; if(neg) x = -x; string s; while(x){ int d = (int)(x%10); s.push_back('0'+d); x/=10; } if(neg) s.push_back('-'); reverse(all(s)); return s;
}
static inline ostream& operator<<(ostream& os, const i128& x){ return os << to_string_i128(x); }
#endif

/************** Treap (sum & size) **************/
struct Treap {
  struct Node {
    ll key; unsigned pri; int sz; ll val, sum; Node *l,*r;
    Node(ll k): key(k), pri((unsigned)rng()), sz(1), val(k), sum(k), l(nullptr), r(nullptr) {}
  };
  using P = Node*;
  static inline int gsz(P t){ return t ? t->sz : 0; }
  static inline ll gsum(P t){ return t ? t->sum: 0; }
  static inline void upd(P t){ if(!t) return; t->sz = 1 + gsz(t->l) + gsz(t->r); t->sum = t->val + gsum(t->l) + gsum(t->r); }

  // split by key: (< key) and (>= key)
  static pair<P,P> split(P t, ll key){
    if(!t) return {nullptr,nullptr};
    if(t->key < key){ auto pr = split(t->r, key); t->r = pr.first; upd(t); return {t, pr.second}; }
    else { auto pr = split(t->l, key); t->l = pr.second; upd(t); return {pr.first, t}; }
  }
  // merge where all keys in a < all keys in b
  static P merge(P a, P b){
    if(!a) return b; if(!b) return a;
    if(a->pri < b->pri){ a->r = merge(a->r, b); upd(a); return a; }
    else { b->l = merge(a, b->l); upd(b); return b; }
  }
  // insert node nd
  static P insert(P t, P nd){
    if(!t) return nd;
    if(nd->pri < t->pri){ auto pr = split(t, nd->key); nd->l=pr.first; nd->r=pr.second; upd(nd); return nd; }
    if(nd->key < t->key) t->l = insert(t->l, nd); else t->r = insert(t->r, nd); upd(t); return t;
  }
  // erase one instance of key
  static P erase(P t, ll key){
    if(!t) return nullptr;
    if(t->key == key){ P res = merge(t->l, t->r); delete t; return res; }
    if(key < t->key) t->l = erase(t->l, key); else t->r = erase(t->r, key); upd(t); return t;
  }
};


#pragma endregion

#define LOCAL_TEST_MAIN

/************** Main **************/
#ifdef LOCAL_TEST_MAIN
int main(){
  FAST_IO();
  return 0;
}
#endif

