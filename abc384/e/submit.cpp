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
    return clamp(Hn,0LL,H-1) == Hn && clamp(Wn,0LL,W-1) == Wn;
}


int main(void){
    ll H,W,X;
    cin>>H>>W>>X;
    ll Hc,Wc;
    cin>>Hc>>Wc;
    Hc--;
    Wc--;
    vector<vector<ll>>S(H,vector<ll>(W));
    rep(i,0,H){
        rep(j,0,W){
            cin>>S[i][j];
        }
    }
    vector<vector<bool>>flag(H,vector<bool>(W,false));
    flag[Hc][Wc] = true;

    ll mysiz = S[Hc][Wc];
    min_priority_queue<pair<ll,pair<ll,ll>>> todo;
    todo.push({0,{Hc,Wc}});
    while(!todo.empty()){
        ll siz = todo.top().first;
        pair<ll,ll> coord = todo.top().second;
        todo.pop();
        if(siz >= (mysiz + X-1)/X) continue;
        mysiz += siz;
        rep(k,0,4){
            Hc = coord.first;
            Wc = coord.second;
            if(!clampp(H,W,Hc,Wc,k)) continue;
            Hc += HV[k];
            Wc += WV[k];
            if(flag[Hc][Wc]) continue;
            flag[Hc][Wc] = true;
            todo.push({S[Hc][Wc],{Hc,Wc}});
        }
    }
    cout<<mysiz<<endl;
}
