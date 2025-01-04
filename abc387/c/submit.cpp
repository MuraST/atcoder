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

ll Ppow(ll x,ll n){
    ll res=1;
    while(n>0){
        if(n&1){
            res=res*x;
        }
        x=x*x;
        n>>=1;
    }
    return res;
}

ull g(ll n){
    if(n == 0)return 0;
    ull res = 0;
    rrep(i,9,1){
        res += Ppow(i,n-1);
    }
    res += g(n-1);
    return res;
}

ull h(string S,ll m){
    ull res = 0;
    ll x = S[0]-'0';
    ll n = S.length()-1;
    if(x >= m){
        return Ppow(m,n+1);
    }
    if(n == 0) return min(x+1,m);

    res += x*Ppow(m,n);
    res += h(S.substr(1,n),m);
    return res;
}


ull f(string S){
    ull res = 0;
    ll x = S[0]-'0';
    ll n = S.length()-1;
    if(n == 0) return x;
    rep(i,1,x){
        res += Ppow(i,n);
    }
    res += g(n);
    res += h(S.substr(1,n),x);
    
    return res;
}


int main(void){
    ll L,R;
    cin>>L>>R;
    string Ls,Rs;
    Ls = to_string(L-1);
    Rs = to_string(R);
    ull ans = f(Rs);
    ans -= f(Ls);
    cout<<ans<<endl;
}
