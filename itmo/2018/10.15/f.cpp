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
using namespace std;

#define all(x) (x).begin(), (x).end()
mt19937 rnd((uint64_t) new char);
int64_t rand(int64_t x, int64_t y){ return rnd() % (y - x + 1) + x; }
template<typename t>
t min(t a){
    return a;
}
template<typename t, typename... ts>
t min(const t& a, const ts&... as){
    t tmp = min(as...);
    return tmp < a ? tmp : a;
}
template<typename t>
t max(t a){
    return a;
}
template<typename t, typename... ts>
t max(const t& a, const ts&... as){
    t tmp = max(as...);
    return tmp > a ? tmp : a;
}
void prn(ostream& os){
    os << '\n';
}
void prn(){
    cout << '\n';
}
template<typename t, typename... ts>
void prn(ostream& os, const t& a, const ts&... b){
    os << a << ' ';
    prn(os, b...);
}
template<typename t, typename... ts>
void prn(const t& a, const ts&... b){
    cout << a << ' ';
    prn(cout, b...);
}
#define vec_in(v) for (auto& i : v) cin >> i;
#define vec_out(v) for (const auto& i : v) cout << i << ' '; cout << '\n';
#define repab(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) repab(i, 0, n)
#define repab_(i, a, b) for (int i = b - 1; i >= a; i--)
#define rep_(i, n) repab_(i, 0, n)
#define infc for(;;)
using vi = vector<int>;
using vll = vector<int64_t>;
using pii = pair<int, int>;
using pll = pair<int64_t, int64_t>;
using ll = int64_t;
//------------------------------------------------------------------------------
#define int ll
int ln = 0, lm = 0;
int n, m;
vector<int> num;
int used[7];
int ans = 0;
void rec(int pos){
    if (pos == ln + lm){
        ll tmp = 0;
        for (int i = 0; i < ln; i++){
            tmp = tmp * 7 + num[i];
        }
        if (tmp >= n) return;
        tmp = 0;
        for (int i = 0; i < lm; i++) tmp = tmp * 7 + num[i + ln];
        if (tmp < m) {
            // cout << tmp << '\n';
            // vec_out(num);
            ans++;
        }
        return;
    }
    for (int i = 0; i < 7; i++){
        if (used[i]) continue;
        num.push_back(i);
        used[i] = 1;
        rec(pos + 1);
        used[i] = 0;
        num.pop_back();
    }

}

int32_t main(){
#ifdef LOCAL
    #else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    cin >> n >> m;
    int tn = n - 1, tm = m - 1;
    do{
        ln++;
        tn /= 7;
    } while(tn > 0);
    do{
        lm++;
        tm /= 7;
    } while (tm > 0);
    if (ln + lm > 7){
        prn(0);
        return 0;
    }
    // cout << ln + lm << '\n';
    rec(0);
    cout << ans << '\n';
}  
