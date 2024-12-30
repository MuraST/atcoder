#include "template.hpp"

int main(void){
    vector<ll>v(3);
    rep(i,0,3){
        cin>>v[i];
    }
    bool ans = false;
    if(v[0] == v[1] && v[1] == v[2]) ans = true;
    rep(i,0,1<<3){
        ll a = 0;
        ll b = 0;
        rep(j,0,3){
            if(i>>j &1){
                a += v[j];
            }else{
                b += v[j];
            }
        }
        if(a==b)ans = true;
    }
    Yes(ans);
}