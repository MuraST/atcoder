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

int main(void){
    ll N;
    cin>>N;
    vector<ll>X(N);
    vector<ll>R(N);
    rep(i,0,N){
        cin>>X[i]>>R[i];
    }

    map<ll,ll>mt;

    rep(i,0,N){
        mt[X[i]-R[i]] = 1;
        mt[X[i]+R[i]] = 1;
    }

    ll Nt = 0;
    fore(e,mt){
        e.second = N+Nt;
        Nt++;
    }

    mf_graph<ll>G(N+Nt+2);
    rep(i,0,N){
        G.add_edge(N+Nt,i,1);
    }
    rep(i,0,Nt){
       G.add_edge(N+i,N+Nt+1,1);
    }
    rep(i,0,N){
        G.add_edge(i,mt[X[i]+R[i]],1);
        G.add_edge(i,mt[X[i]-R[i]],1);
    }
    ll ans = G.flow(N+Nt,N+Nt+1);
    cout<<ans<<endl;
    return 0;
}