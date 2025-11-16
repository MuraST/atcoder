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
    ll N,M,X;
    cin>>N>>M>>X;
    vector<vector<ll>>G(N),g(N);
    rep(i,0,M){
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        G[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<ll>>dist(N,vector<ll>(2,INF));
    vector<vector<ll>>flag(N,vector<ll>(2,0));
    min_priority_queue<pair<ll,ll>>que;
    dist[0][0] = 0;
    flag[0][0] = 0;
    que.push({0,0});
    while(!que.empty()){
        ll v = que.top().second /2;
        ll mode = que.top().second % 2;
        ll d = dist[v][mode];
        que.pop();
        if(flag[v][mode ] == 1) continue;
        flag[v][mode] = 1;
        if(!flag[v][1-mode]){
            if(d+X < dist[v][1-mode]){
                dist[v][1-mode] = d+X;
                que.push({d+X,2*v+(1-mode)});
            }
        }
        if(mode == 0){
            fore(next_v,G[v]){
                if(!flag[next_v][mode]){
                    if(d+1 < dist[next_v][mode]){
                        dist[next_v][mode] = d+1;
                        que.push({d+1,2*next_v+mode});
                    }
                }
            }
        }else{
            fore(next_v,g[v]){
                if(!flag[next_v][mode]){
                    if(d+1 < dist[next_v][mode]){
                        dist[next_v][mode] = d+1;
                        que.push({d+1,2*next_v+mode});
                    }
                }
            }
        }
    }
    ll ans = min(dist[N-1][0],dist[N-1][1]);
    if(ans == INF) ans = -1;
    cout<<ans<<endl;
}
