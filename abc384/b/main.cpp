#include "template.hpp"

int main(void){
    int N,R;
    cin>>N>>R;
    vector<int>D(N),A(N);
    rep(i,0,N){
        cin>>D[i]>>A[i];
    }
    rep(i,0,N){
        bool flag = false;
        if(D[i] == 1){
            if(1600 <= R && R <= 2799){
                flag = true;
            }
        }else{
            if(1200 <= R && R <= 2399){
                flag = true;
            }
        }
        if(!flag)continue;
        R += A[i];
    }
    cout<<R<<endl;
}