#include "template.hpp"

int main(void){
    vector<ll>A(3);
    rep(i,0,3){
        cin>>A[i];
    }
    sort(all(A));
    bool ans = false;
    do{
        if(A[0]*A[1] == A[2]){
            ans = true;
        }
    }while(next_permutation(all(A)));
    Yes(ans);
}