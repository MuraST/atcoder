#include "template.hpp"

int main(void){
    string S;
    cin>>S;
    string ans = "";
    rep(i,0,S.length()){
        if(S[i] == '2'){
            ans += '2';
        }
    }
    cout<<ans<<endl;
}