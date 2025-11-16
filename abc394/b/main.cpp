#include "template.hpp"

int main(void){
    ll N;
    cin>>N;
    vector<pair<int,string>>S(N);
    rep(i,0,N){
        string in;
        cin>>in;
        S[i] = {in.length(),in};
    }
    sort(all(S));
    string ans = "";
    rep(i,0,N){
        ans += S[i].second;
    }
    cout<<ans<<endl;
}