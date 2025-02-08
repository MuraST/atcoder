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
    vector<ll>K(N);
    vector<map<ll,ll>>A(N);
    rep(i,0,N){
        cin>>K[i];
        rep(j,0,K[i]){
            ll num;
            cin>>num;
            A[i][num]++;
        }
    }
    ld out = 0;
    rep(i,0,N){
        rep(j,i+1,N){
            ld ans = 0;
            ll Ki = K[i];
            ll Kj = K[j];
            fore(e,A[i]){
                ll ni = e.second;
                ll nj = 0;
                if(A[j].count(e.first)){
                    nj = A[j][e.first];
                }
                ld res = ni*nj;
                res /= (ld)Ki;
                res /= (ld)Kj;
                ans += res;
            }
            chmax(out,ans);
        }
    }
    cout<<fixed<<setprecision(15)<<out<<endl;
}
