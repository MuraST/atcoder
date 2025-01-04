#include "template.hpp"

ll Ppow(ll x,ll n){
    ll res=1;
    while(n>0){
        if(n&1){
            res=res*x;
        }
        x=x*x;
        n>>=1;
    }
    return res;
}

ull g(ll n){
    if(n == 0)return 0;
    ull res = 0;
    rrep(i,9,1){
        res += Ppow(i,n-1);
    }
    res += g(n-1);
    return res;
}

ull h(string S,ll m){
    ull res = 0;
    ll x = S[0]-'0';
    ll n = S.length()-1;
    if(x >= m){
        return Ppow(m,n+1);
    }
    if(n == 0) return min(x+1,m);

    res += x*Ppow(m,n);
    res += h(S.substr(1,n),m);
    return res;
}


ull f(string S){
    ull res = 0;
    ll x = S[0]-'0';
    ll n = S.length()-1;
    if(n == 0) return x;
    rep(i,1,x){
        res += Ppow(i,n);
    }
    res += g(n);
    res += h(S.substr(1,n),x);
    
    return res;
}


int main(void){
    ll L,R;
    cin>>L>>R;
    string Ls,Rs;
    Ls = to_string(L-1);
    Rs = to_string(R);
    ull ans = f(Rs);
    ans -= f(Ls);
    cout<<ans<<endl;
}