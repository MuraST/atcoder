#include "template.hpp"

int main(void){
    ll N,M;
    cin>>N>>M;
    vector<bool>flag(N+1,0);
    rep(i,0,M){
        ll A;
        cin>>A;
        flag[A]=1;
    }
    ll cnt = 0;
    rep(i,1,N+1){
        if(!flag[i])cnt++;
    }
    cout<<cnt<<endl;
    rep(i,1,N+1){
        if(!flag[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}