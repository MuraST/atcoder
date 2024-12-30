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
    ll H,W,X,Y;
    cin>>H>>W>>X>>Y;
    X--;
    Y--;
    vector<string>S(H);
    rep(i,0,H){
        cin>>S[i];
    }
    string T;
    cin>>T;
    map<char,pair<ll,ll>>mp;
    mp['U']={-1,0};
    mp['D']={1,0};
    mp['L']={0,-1};
    mp['R']={0,1};
    int ans = 0;
    rep(i,0,T.length()){
        ll Xn = X + mp[T[i]].first;
        ll Yn = Y + mp[T[i]].second;
        if(S[Xn][Yn] != '#'){
            X = Xn;
            Y = Yn;
        }
        if(S[X][Y] == '@'){
            ans++;
            S[X][Y] ='.';
        }
    }
    X++;
    Y++;
    cout<<X<<" "<<Y<<" "<<ans<<endl;
}
