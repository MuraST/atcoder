#include "template.hpp"

int main(void){
    ll N;
    cin>>N;
    vector<vector<ll>>A(N,vector<ll>(N));
    rep(i,0,N){
        ll j = N - i;
        if(i <= j){
            rep(k,i,j){
                rep(l,i,j){
                    A[k][l] = (i%2)+1;
                }
            }
        }
        
    }
    rep(i,0,N){
        rep(j,0,N){
            if(A[i][j] == 1){
                cout<<'#';
            }else{
                cout<<".";
            }
        }
        cout<<endl;
    }
}