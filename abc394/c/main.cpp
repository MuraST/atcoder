#include "template.hpp"

int main(void){
    string S;
    cin>>S;
    ll wlen = 0;
    rep(i,0,S.length()){
        if(S[i] == 'W'){
            wlen++;
        }else{
            if(S[i] == 'A'){
                cout<<'A';
                rep(j,0,wlen){
                    cout<<'C';
                }
            }else{
                rep(i,0,wlen){
                    cout<<'W';
                }
                cout<<S[i];
            }
            wlen = 0;
        }
    }
    rep(i,0,wlen){
        cout<<'W';
    }
    cout<<endl;
}