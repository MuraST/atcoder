#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
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
    ll N,S;
    cin>>N>>S;
    vector<ll>A(2*N);
    ll allsum = 0;
    rep(i,0,N){
        cin>>A[i];
    }
    rep(i,0,N){
        allsum += A[i];
        A[N+i] = A[i];
    }
    S %= allsum;
    N*=2;


    bool ans = false;
    map<ll,ll>memo;
    vector<ll>sum(N+1);
    sum[0] = 0;
    rep(i,0,N){
        sum[i+1] = sum[i] + A[i];
    }

    rep(i,0,N+1){
        memo[sum[i]]++;
    }

    rep(i,0,N+1){
        if(memo.count(sum[i]+S)){
            ans = true;
        }
    }
    Yes(ans);
}
