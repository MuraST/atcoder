#include "template.hpp"

int main(void){
    string S;
    cin>>S;
    ll a,b,c;
    a = 0;
    b = 0;
    c = 0;
    stack<tuple<ll,ll,ll>>sa,sb,sc;
    bool ans = true;
    rep(i,0,S.length()){
        if(S[i] == '(' || S[i] == '[' || S[i] == '<'){
            if(S[i] == '('){
                a++;
                sa.push({a,b,c});
            }
            if(S[i] == '['){
                b++;
                sb.push({a,b,c});
            }
            if(S[i] == '<'){
                c++;
                sc.push({a,b,c});
            }
        }else{
            tuple<ll,ll,ll> t = {a,b,c};
            if(S[i] == ')'){
                if(sa.empty()){
                    ans = false;
                    break;
                }
                if(sa.top() != t){
                    ans = false;
                    break;
                }
                sa.pop();
                a--;
            }
            if(S[i] == ']'){
                if(sb.empty()){
                    ans = false;
                    break;
                }
                if(sb.top() != t){
                    ans = false;
                    break;
                }
                sb.pop();
                b--;
            }
            if(S[i] == '>'){
                if(sc.empty()){
                    ans = false;
                    break;
                }
                if(sc.top() != t){
                    ans = false;
                    break;
                }
                sc.pop();
                c--;
            }
        }
    }
    if(!sa.empty()){
        ans = false;
    }
    if(!sb.empty()){
        ans = false;
    }
    if(!sc.empty()){
        ans = false;
    }
    Yes(ans);
}