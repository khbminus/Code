#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>
#include <string>
#include <cassert>

using namespace std;

mt19937 rnd((uint64_t) new char);

int64_t rand(int64_t x, int64_t y) { return rnd() % (y - x + 1) + x; }

template<typename t>
t min(t a) {
    return a;
}

template<typename t, typename... ts>
t min(const t &a, const ts &... as) {
    t tmp = min(as...);
    return tmp < a ? tmp : a;
}

template<typename t>
t max(t a) {
    return a;
}

template<typename t, typename... ts>
t max(const t &a, const ts &... as) {
    t tmp = max(as...);
    return tmp > a ? tmp : a;
}

void prn(ostream &os) {
    os << '\n';
}

void prn() {
    cout << '\n';
}

template<typename t, typename... ts>
void prn(ostream &os, const t &a, const ts &... b) {
    os << a << ' ';
    prn(os, b...);
}

template<typename t, typename... ts>
void prn(const t &a, const ts &... b) {
    cout << a << ' ';
    prn(cout, b...);
}

#ifdef LOCAL

template<typename... ts>
void deb(const ts &... b) {
    prn(cerr, "DEBUG", b...);
}

#else
template<typename... ts>
void deb(const ts&... b){

}
#endif

#define vec_in(v) for (auto& i : v) cin >> i;

template<typename T>
void vec_out(const T &v) {
    auto end = v.end();
    --end;
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " \n"[it == end];
    }
}

#define repab(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) repab(i, 0, n)
#define repab_(i, a, b) for (int i = b - 1; i >= a; i--)
#define rep_(i, n) repab_(i, 0, n)
#define infc for(;;)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using vi = vector<int>;
using vll = vector<int64_t>;
using pii = pair<int, int>;
using pll = pair<int64_t, int64_t>;
using ll = int64_t;
//------------------------------------------------------------------------------

#define int ll
vector<vector<vector<int>>> g;
vector<vector<int>> matrix;
vector<vector<int>> used;
int cnt = 0;

bool dfs(int v, int x) {
    used[x][v] = 1;
    cnt++;
    for (int u : g[x][v]) {
        if (used[x][u] == 1) {
            return 1;
        }
        if (used[x][u] == 2) continue;
        if (dfs(u, x)) return 1;
    }
    used[x][v] = 2;
    return 0;
}

int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int n;
    cin >> n;
    g.assign(3, vector<vector<int>>(n));
    matrix.assign(3, vector<int>(n));
    used.assign(3, vector<int>(n));
    rep(i, 3) {
        rep(j, n) {
            cin >> matrix[i][j];
            g[i][j].push_back(matrix[i][j] - 1);
        }
    }
    vector<vector<int>> cycles(3);
    rep(i, 3) {
        rep(j, n) {
            if (!used[i][j]) {
                cnt = 0;
                dfs(j, i);
                cycles[i].push_back(cnt);
            }
        }
    }
    ll ans = 0;
    rep(i, cycles[0].size()) {
        rep(j, cycles[1].size()) {
            rep(k, cycles[2].size()) {
                vector<ll> gg = {__gcd(cycles[0][i], cycles[1][j]), __gcd(cycles[0][i], cycles[2][k]),
                                 __gcd(cycles[1][j], cycles[2][k])};
                ans += gg[0] * gg[1] * gg[2] / __gcd(gg[0], gg[1]);
            }
        }
    }
    cout << min(ans, n * n * n) << '\n';
}
