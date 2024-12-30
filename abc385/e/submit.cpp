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


int N;
vector<vector<ll>>G;

int f(int root){
    int res = 1000000000;
    int x = G[root].size();
    int y;
    map<int,int>cnt;
    fore(v,G[root]){
        int knum = G[v].size()-1;
        cnt[knum]++;
    }
    fore(e,cnt){
        y = e.first;
        if(y == 0){
            x -= e.second;
            continue;
        }
        int sum = x*(y+1);
        chmin(res,N-1-sum);
        x -= e.second;
    }
    return res;
}

int main(void){
    cin>>N;
    G.resize(N);
    rep(i,0,N-1){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans = 1000000000;
    rep(i,0,N){
        int res = f(i);
        chmin(ans,res);
    }
    cout<<ans<<endl;
}
