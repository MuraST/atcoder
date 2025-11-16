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
    fenwick_tree<ll> fw_i(500010);
    fenwick_tree<ll> fw_sum(500010);
    vector<ll>A(N);
    for(int i = 0;i < N;i++){
        cin>>A[i];
        fw_i.add(A[i],1);
        fw_sum.add(A[i],A[i]);
    }

    int T,X,Y,L,R;
    while(Q--){
        cin>>T;
        if(T==1){
            cin>>X>>Y;
            X--;
            int x = A[X];
            int y = Y;
            A[X] = Y;
            fw_i.add(x,-1);
            fw_sum.add(x,-x);
            fw_i.add(y,1);
            fw_sum.add(y,y);
        }else{
            cin>>L>>R;
            if(L>=R){
                cout<<L*N<<endl;
                continue;
            }
            ll res = 0;
            res += fw_i.sum(0,L+1) * L;
            res += fw_sum.sum(L+1,R);
            res += fw_i.sum(R,500005) * R;
            cout<<res<<endl;
        }
    }
    return 0;
}
