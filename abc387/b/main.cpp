#include "template.hpp"

int main(void){
    ll X;
    cin>>X;
    ll ans = 0;
    rep(i,0,9){
        rep(j,0,9){
            ll num = (i+1)*(j+1);
            if(num != X)ans += num;
        }
    }
    cout<<ans<<endl;
}