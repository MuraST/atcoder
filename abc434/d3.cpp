#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <class T>
using min_priority_queue = priority_queue<T,vector<T>,greater<T>>;
constexpr long long INF32 = 1000000000;
constexpr long long INF = (1LL<<60);
constexpr long long modA = 998244353;
constexpr long long modB = 1000000007;
constexpr long double PIE = acos(-1);
#define rep(i,a,b) for(ll i = a;i < (ll)b;i++)
#define rrep(i,a,b) for(ll i = a;i >= (ll)b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
#define YES(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define Yes(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define yes(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


template <typename T>
struct Sum2D {
    int H, W;
    bool init;
    vector<vector<T>> data;
    vector<vector<T>> diff;
    vector<vector<T>> csum;

    Sum2D(int H, int W) : H(H), W(W), init(false),
                          data(H, vector<T>(W, 0)),
                          diff(H + 1, vector<T>(W + 1, 0)),
                          csum(H + 1, vector<T>(W + 1, 0)) {}

    void add_rect(int sy, int sx, int ty, int tx, T v) {
        // [sy,ty) [sx,tx)
        assert(0 <= sy && sy <= ty && ty <= H);
        assert(0 <= sx && sx <= tx && tx <= W);

        diff[sy][sx] += v;
        diff[sy][tx] -= v;
        diff[ty][sx] -= v;
        diff[ty][tx] += v;

        init = false;
    }

    void set(int y, int x, T v) noexcept {
        assert(0 <= y && y < H);
        assert(0 <= x && x < W);

        data[y][x] = v;

        init = false;
    }

    void build() noexcept {
        init = true;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                T v = diff[i][j];
                if (i) v += diff[i - 1][j];
                if (j) v += diff[i][j - 1];
                if (i && j) v -= diff[i - 1][j - 1];
                diff[i][j] = v;
                data[i][j] += v;
            }
        }

        for (int i = 0; i <= H; i++){
            fill(diff[i].begin(), diff[i].end(), 0);
            fill(csum[i].begin(), csum[i].end(), 0);
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                csum[i + 1][j + 1] =
                    data[i][j] + csum[i][j + 1] + csum[i + 1][j] - csum[i][j];
            }
        }
    }


    T get(int y, int x) const {
        assert(init);
        assert(0 <= y && y < H);
        assert(0 <= x && x < W);
        return data[y][x];
    }

    T sum(int sy, int sx, int ty, int tx) const {
        assert(init);
        assert(0 <= sy && sy <= ty && ty <= H);
        assert(0 <= sx && sx <= tx && tx <= W);

        return csum[ty][tx] - csum[sy][tx] - csum[ty][sx] + csum[sy][sx];
    }

    void reset() {
        for (int i = 0; i < H; i++) fill(data[i].begin(), data[i].end(), 0);
        for (int i = 0; i <= H; i++) fill(diff[i].begin(), diff[i].end(), 0);
        for (int i = 0; i <= H; i++) fill(csum[i].begin(), csum[i].end(), 0);
        build();
    }
};


int main(void){
    ll N;
    cin>>N;
    vector<ll>U(N),D(N),L(N),R(N);
    rep(i,0,N){
        cin>>U[i]>>D[i]>>L[i]>>R[i];
        U[i]--;
        L[i]--;
    }

    ll H = 2010;
    ll W = 2010;
    Sum2D<ll>s(H,W);
    //全部2次元imos
    rep(i,0,N){
        s.add_rect(U[i],L[i],D[i],R[i],1);
    }
    s.build();

    //2雲以上かぶっている (確定させて取り除く)
    ll base = 2000*2000;
    vector<vector<bool>>db(H,vector<bool>(W,false));
    rep(i,0,H){
        rep(j,0,W){
            ll num = s.get(i,j);
            if(1 <= num) base--;
            if(2 <= num) db[i][j] = true;
        }
    }
    rep(i,0,H){
        rep(j,0,W){
            if(db[i][j]) s.set(i,j,0);
        }
    }
    s.build();

    //1雲ぬいて差分を足す
    rep(i,0,N){
        ll num = s.sum(U[i],L[i],D[i],R[i]);
        cout<< base + num <<endl;
    }
    return 0;
}