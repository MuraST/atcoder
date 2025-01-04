#include <iostream>
 using namespace std;
 using ll = long long;

bool isS(ll x){
    string S = to_string(x);
    bool res = true;
    for(int i = 1;i < S.length();i++){
        if(S[0] <= S[i])res = false;
    }
    return res;
}

void f(ll x){
    ll res = 0;
    for(int i = 1;i <= x;i++){
        res += isS(i);
    }
    cout<<res<<endl;
}

int main(void){
    f(96);
    f(210);
}