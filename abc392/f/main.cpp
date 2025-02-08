#include "template.hpp"

ll op(ll a,ll b){
    return a + b;
}

ll e(){
    return 0;
}


ll tar;
bool f(ll v){
    return v < tar;
}


int main(void){
    ll N;
    cin>>N;
    vector<ll>P(N);
    rep(i,0,N){
        cin>>P[i];
        P[i]--;
    }
    vector<ll>ans(N);
    segtree<ll,op,e>seg(N+10);
    rep(i,0,N){
        seg.set(i,1);
    }
    rrep(i,N-1,0){
        tar = P[i]+1;
        ll index = seg.max_right<f>(0);
        ans[index] = i + 1;
        seg.set(index,0);
    }
    rep(i,0,N){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}