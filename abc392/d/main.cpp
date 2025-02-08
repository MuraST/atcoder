#include "template.hpp"

int main(void){
    ll N;
    cin>>N;
    vector<ll>K(N);
    vector<map<ll,ll>>A(N);
    rep(i,0,N){
        cin>>K[i];
        rep(j,0,K[i]){
            ll num;
            cin>>num;
            A[i][num]++;
        }
    }
    ld out = 0;
    rep(i,0,N){
        rep(j,i+1,N){
            ld ans = 0;
            ll Ki = K[i];
            ll Kj = K[j];
            fore(e,A[i]){
                ll ni = e.second;
                ll nj = 0;
                if(A[j].count(e.first)){
                    nj = A[j][e.first];
                }
                ld res = ni*nj;
                res /= (ld)Ki;
                res /= (ld)Kj;
                ans += res;
            }
            chmax(out,ans);
        }
    }
    cout<<fixed<<setprecision(15)<<out<<endl;
}