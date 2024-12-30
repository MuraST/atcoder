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
    ll N,M;
    cin>>N>>M;
    ll Sx,Sy;
    cin>>Sx>>Sy;

    
    vector<ll>X(N),Y(N),C(M);
    vector<char>D(M);

    rep(i,0,N){
        cin>>X[i]>>Y[i];
    }
    rep(i,0,M){
        cin>>D[i]>>C[i];
    }

    
    map<ll,map<ll,ll>>qx,qy;
    ll Xn,Yn;
    rep(i,0,M){
        if(D[i]=='U'){
            Yn = Sy + C[i];
            qx[Sx][Sy]++;
            qx[Sx][Yn+1]--;
            Sy = Yn;
        }else if(D[i] == 'D'){
            Yn = Sy - C[i];
            qx[Sx][Yn]++;
            qx[Sx][Sy+1]--;
            Sy = Yn;
        }else if(D[i] == 'L'){
            Xn = Sx - C[i];
            qy[Sy][Xn]++;
            qy[Sy][Sx+1]--;
            Sx = Xn;
        }else{
            Xn = Sx + C[i];
            qy[Sy][Sx]++;
            qy[Sy][Xn+1]--;
            Sx = Xn;
        }
    }

    
    map<ll,vector<ll>>lx,ly;
    fore(mp,qx){
        ll psum = 0;
        ll sum = 0;
        fore(e,mp.second){
            sum += e.second;
            if(psum == 0 && sum > 0){
                lx[mp.first].push_back(e.first);
            }else if(psum > 0 && sum == 0){
                lx[mp.first].push_back(e.first);
            }
            psum = sum;
        }
    }

    fore(mp,qy){
        ll psum = 0;
        ll sum = 0;
        fore(e,mp.second){
            sum += e.second;
            if(psum == 0 && sum > 0){
                ly[mp.first].push_back(e.first);
            }else if(psum > 0 && sum == 0){
                ly[mp.first].push_back(e.first);
            }
            psum = sum;
        }
    }

    int ans = 0;
    vector<bool>flag(N,false);
    rep(i,0,N){
        if(!lx.count(X[i]))continue;
        int index = upper_bound(all(lx[X[i]]),Y[i])-lx[X[i]].begin();
        if(index%2 == 1){
            flag[i] = true;
            ans++;
        }
    }
    rep(i,0,N){
        if(flag[i])continue;
        if(!ly.count(Y[i]))continue;
        int index = upper_bound(all(ly[Y[i]]),X[i])-ly[Y[i]].begin();
        if(index%2 == 1){
            ans++;
        }
    }
    cout<<Sx<<" "<<Sy<<" "<<ans<<endl;
}
