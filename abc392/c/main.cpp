#include "template.hpp"

int main(void){
    ll N;
    cin>>N;
    vector<ll>P(N);
    vector<ll>Q(N);
    rep(i,0,N){
        cin>>P[i];
        P[i]--;
    }
    rep(i,0,N){
        cin>>Q[i];
    }
    map<ll,ll>mp;
    rep(i,0,N){
        mp[Q[i]] = i;
    }

    rep(i,0,N){
        cout<<Q[P[mp[i+1]]]<<" ";
    }
    cout<<endl;
}