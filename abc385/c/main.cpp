#include "template.hpp"

int main(void){
    ll N;
    cin>>N;
    vector<ll>H(N);
    rep(i,0,N){
        cin>>H[i];
    }
    int ans = 1;
    rep(i,1,N){
        rep(j,0,i){
            int ren = 0;
            int height = -1;
            for(int k = j;k < N;k += i){
                if(height != H[k]){
                    height = H[k];
                    ren = 1;
                }else{
                    ren++;
                    ans = max(ans,ren);
                }
            }
        }
    }
    cout<<ans<<endl;
}