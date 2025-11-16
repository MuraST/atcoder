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
    ll N,X,Y;
    cin>>N>>X>>Y;
    vector<ll>A(N);
    for(int i = 0;i < N;i++){
        cin>>A[i];
    }
    sort(all(A));

    vector<ll>W(N);
    for(int i = 0;i < N;i++){
        W[i] = Y * A[i];
    }
    for(int i = 1;i < N;i++){
        ll mo = (W[i] - W[0])%(Y-X);
        if(mo != 0){
            cout<<-1<<endl;
            return 0;
        }
        ll nu = (W[i] - W[0])/(Y-X);
        if(nu > A[i]){
            cout<<-1<<endl;
            return 0;
        }
        A[i] -= nu;
    }
    ll ans = 0;
    for(int i = 0;i < N;i++){
        ans += A[i];
    }
    cout<<ans<<endl;
    return 0;
}
