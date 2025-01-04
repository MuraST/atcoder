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

const string UDLR = "UDLR";
constexpr pair<int,int> UV = {-1,0};
constexpr pair<int,int> DV = {1,0};
constexpr pair<int,int> LV = {0,-1};
constexpr pair<int,int> RV = {0,1};
constexpr int HV[] = {-1,1,0,0,-1,-1,1,1};
constexpr int WV[] = {0,0,-1,1,1,-1,-1,1};

pair<int,int> fdir(char dir){
    if(dir == 'U')return UV;
    if(dir == 'D')return DV;
    if(dir == 'L')return LV;
    if(dir == 'R')return RV;
    exit(1);
}

bool clampp(ll H,ll W,ll Hc,ll Wc,ll dir){
    ll Hn = Hc + HV[dir];
    ll Wn = Wc + WV[dir];
    if(clamp(Hn,0LL,H-1) != Hn || clamp(Wn,0LL,W-1) != Wn){
        return false;
    }
    return true;
}
int main(void){
    ll H,W;
    cin>>H>>W;
    vector<string>S(H);
    rep(i,0,H){
        cin>>S[i];
    }
    pair<ll,ll>St,G;
    rep(i,0,H){
        rep(j,0,W){
            if(S[i][j] == 'S'){
                St = {i,j};
            }
            if(S[i][j] == 'G'){
                G = {i,j};
            }
        }
    }

    deque<pair<pair<ll,ll>,bool>>que;
    vector<vector<vector<ll>>>flag(H,vector<vector<ll>>(W,vector<ll>(2,INF)));
    que.push_back({St,true});
    que.push_back({St,false});
    flag[St.first][St.second][0] = 0;
    flag[St.first][St.second][1] = 0;

    while(!que.empty()){
        pair<ll,ll> coord = que.front().first;
        bool b = que.front().second;
        que.pop_front();
        rep(k,0,2){
            ll d = k + b*2;
            ll Hn = coord.first;
            ll Wn = coord.second;
            if(!clampp(H,W,Hn,Wn,d))continue;
            Hn += HV[d];
            Wn += WV[d];
            if(S[Hn][Wn] == '#')continue;
            if(flag[Hn][Wn][1-b] != INF)continue;
            flag[Hn][Wn][1-b] = flag[coord.first][coord.second][b] + 1;
            que.push_back({{Hn,Wn},1-b});
        }
    }

    ll ans = min(flag[G.first][G.second][0],flag[G.first][G.second][1]);
    if(ans == INF) ans = -1;
    cout<<ans<<endl;
    return 0;
}
