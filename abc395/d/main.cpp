#include "template.hpp"

int main(void){
    ll N,Q;
    cin>>N>>Q;
    vector<ll>op(Q),a(Q),b(Q);
    rep(i,0,Q){
        cin>>op[i];
        if(op[i] != 3){
            cin>>a[i]>>b[i];
            a[i]--;
            b[i]--;
        }else{
            cin>>a[i];
            a[i]--;
        }
    }

    vector<ll>convert(N);
    vector<ll>rev(N);
    rep(i,0,N){
        convert[i] = i;
        rev[i] = i;
    }
    vector<ll>hatopos(N);
    rep(i,0,N){
        hatopos[i] = i;
    }
    rep(i,0,Q){
        if(op[i] == 1){
            hatopos[a[i]] = convert[b[i]];
        }else if(op[i] == 2){
            swap(convert[a[i]],convert[b[i]]);
            swap(rev[convert[a[i]]],rev[convert[b[i]]]);
        }else{
            cout<<rev[hatopos[a[i]]]+1<<endl;
        }
    }
}