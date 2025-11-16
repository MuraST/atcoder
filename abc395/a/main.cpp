#include "template.hpp"

int main(void){
    ll N;
    cin>>N;
    vector<ll>A(N);
    rep(i,0,N){
        cin>>A[i];
    }
    bool ans = true;
    rep(i,0,N-1){
        if(A[i] >= A[i+1]){
            ans = false;
        }
    }
    Yes(ans);
}