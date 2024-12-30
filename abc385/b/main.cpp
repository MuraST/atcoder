#include "template.hpp"

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