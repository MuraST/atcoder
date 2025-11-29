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
    vector<vector<T>> csum;

    Sum2D(int H, int W) : H(H), W(W), init(false),
                          data(H, vector<T>(W, 0)),
                          csum(H + 1, vector<T>(W + 1, 0)) {}

    void build() noexcept {
        init = true;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                csum[i + 1][j + 1] =
                    data[i][j] + csum[i][j + 1] + csum[i + 1][j] - csum[i][j];
            }
        }
    }

    void reset() noexcept {
        for (int i = 0; i < H; ++i) {
            fill(data[i].begin(), data[i].end(), 0);
        }
        for (int i = 0; i <= H; ++i) {
            fill(csum[i].begin(), csum[i].end(), 0);
        }
        build();
    }

    T get(int y, int x) const noexcept {
        assert(0 <= y && y < H);
        assert(0 <= x && x < W);
        return data[y][x];
    }

    void set(int y, int x, T v) noexcept {
        assert(0 <= y && y < H);
        assert(0 <= x && x < W);
        init = false;
        data[y][x] = v;
    }

    T sum(int sy, int sx, int ty, int tx) const noexcept {
        assert(init);
        assert(0 <= sy && sy < H);
        assert(0 <= sx && sx < W);
        assert(0 <= ty && ty <= H);
        assert(0 <= tx && tx <= W);
        assert(sy <= ty && sx <= tx);
        return csum[ty][tx] - csum[sy][tx] - csum[ty][sx] + csum[sy][sx];
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


    vector<vector<ll>>tiles(H,vector<ll>(W,0));
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            tiles[y][x] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        tiles[U[i]][L[i]]++;
        tiles[U[i]][R[i]]--;
        tiles[D[i]][L[i]]--;
        tiles[D[i]][R[i]]++;
    }

    for (int y = 0; y < H; y++) {
        for (int x = 1; x < W; x++) {
            tiles[y][x] += tiles[y][x - 1];
        }
    }

    for (int y = 1; y < H; y++) {
        for (int x = 0; x < W; x++) {
            tiles[y][x] += tiles[y - 1][x];
        }
    }

    ll base = 0;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if(0 < tiles[y][x])base++;
            if(1 < tiles[y][x]){
                tiles[y][x] = 0;
            }
        }
    }

    Sum2D<ll> sum(2010,2010);
    rep(i,0,H){
        rep(j,0,W){
            sum.set(i,j,tiles[i][j]);
        }
    }
    sum.build();

    base = 2000 * 2000 - base;
    rep(i,0,N){
        ll num = sum.sum(U[i],L[i],D[i],R[i]);
        cout<< base + num <<endl;
    }
    return 0;


}