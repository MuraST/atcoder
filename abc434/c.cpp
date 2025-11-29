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


void solve(){
    ll N,H;
    cin>>N>>H;
    ll mi,ma,pret;
    mi = H;
    ma = H;
    pret = 0;
    bool ans = true;
    rep(i,0,N){
        ll t,l,u;
        cin>>t>>l>>u;
        ll k = t - pret;
        mi = max(0LL,mi - k);
        ma = ma + k;
        //cout<<"!"<<mi << " " << ma<<endl;
        if(u < mi || ma < l){
            ans = false;
        }
        mi = max(mi,l);
        ma = min(ma,u);
        if(mi > ma)ans = false;
        //cout<<"!!"<<mi << " " << ma<<endl;
        pret = t;
    }
    Yes(ans);
}

int main(void){
    ll T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}