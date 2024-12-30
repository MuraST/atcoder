#include "template.hpp"

int main(void){
    int N;
    char c1,c2;
    cin>>N>>c1>>c2;
    string S;
    cin>>S;
    rep(i,0,N){
        if(S[i]!=c1){
            S[i] = c2;
        }
    }
    cout<<S<<endl;
}