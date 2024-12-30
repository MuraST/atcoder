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


bool fcomp(const pair<ll,string>& a,const pair<ll,string>& b){
    if(a.first != b.first){
        return a.first > b.first;
    }
    return a.second < b.second;
}
int main(void){
    string S ="ABCDE";
    vector<ll>val(5);
    rep(i,0,5){
        cin>>val[i];
    }
    vector<pair<ll,string>>P;
    rep(i,1,1<<5){
        int score = 0;
        string T = "";
        rep(j,0,5){
            if(i>>j &1){
                score += val[j];
                T += S[j];
            }
        }
        P.push_back({score,T});
    }
    sort(all(P),fcomp);
    fore(ans,P){
        cout<<ans.second<<endl;
    }
}
