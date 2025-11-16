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
    ll N,Q;
    cin>>N>>Q;
    vector<ll>op(Q),a(Q),b(Q);
    rep(i,0,Q){
        cin>>op[i];
        if(op[i] != 3){
            cin>>a[i]>>b[i];
            a[i]--;
            b[i]--;
        }else{
            cin>>a[i];
            a[i]--;
        }
    }

    vector<ll>convert(N);
    vector<ll>rev(N);
    rep(i,0,N){
        convert[i] = i;
        rev[i] = i;
    }
    vector<ll>hatopos(N);
    rep(i,0,N){
        hatopos[i] = i;
    }
    rep(i,0,Q){
        if(op[i] == 1){
            hatopos[a[i]] = convert[b[i]];
        }else if(op[i] == 2){
            swap(convert[a[i]],convert[b[i]]);
            swap(rev[convert[a[i]]],rev[convert[b[i]]]);
        }else{
            cout<<rev[hatopos[a[i]]]+1<<endl;
        }
    }
}
