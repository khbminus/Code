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
void deb(const ts &... b) {

}

#endif

#define vec_in(v) for (auto& i : v) cin >> i;
#define vec_out(v) for (const auto& i : v) cout << i << ' '; cout << '\n';
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



int32_t main() {
#ifdef LOCAL
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<pii> rows;
    vector<pii> column;
//    cout << -1 << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            arr[i][j] = tmp - arr[i][j];
            if (arr[i][j] < 0){
                cout << "-1\n";
                return 0;
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (arr[0][j] + arr[i][0] - arr[0][0] != arr[i][j]){
                cout << "-1\n";
                return 0;
            }
        }
    }

    int mn = INT_MAX;
    for (int i = 0; i < m; i++) mn = min(mn, arr[0][i]);
    if (mn != 0) {
        rows.push_back({0, mn});
        for (int i = 0; i < m; i++) arr[0][i] -= mn;
    }
    for (int i = 0; i < m; i++){
        if (arr[0][i] == 0) continue;
        column.push_back({i, arr[0][i]});
        int tmp = arr[0][i];
        for (int j = 0; j < n; j++) arr[j][i] -= tmp;
    }
    for (int i = 1; i < n; i++){
        if (arr[i][0] == 0) continue;
        rows.push_back({i, arr[i][0]});
        int tmp = arr[i][0];
        for (int j = 0; j < m; j++) arr[i][j] -= tmp;
    }
    cout << rows.size() + column.size() << '\n';

    for (auto i : rows){
        cout << "R " << i.first + 1 << ' ' << i.second << '\n';
    }
    for (auto i : column){
        cout << "C " << i.first + 1 << ' ' << i.second << '\n';
    }
}
