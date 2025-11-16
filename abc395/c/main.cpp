#include "template.hpp"

int main(void){
    ll N;
    cin>>N;
    vector<vector<ll>>A(1000010);
    rep(i,0,N){
        ll num;
        cin>>num;
        A[num].push_back(i);
    }
    ll ans = INF;
    rep(i,0,1000010){
        rrep(j,A[i].size()-1,1){
            chmin(ans,A[i][j]-A[i][j-1]+1);
        }
    }
    if(ans == INF)ans = -1;
    cout<<ans<<endl;
}