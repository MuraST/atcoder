#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <class T>
using min_priority_queue = priority_queue<T,vector<T>,greater<T>>;
constexpr long long INF32 = 1000000000;
constexpr long long INF = (1LL<<60);
constexpr long long modA = 998244353;
constexpr long long modB = 1000000007;
constexpr long double PIE = acos(-1);
#define rep(i,a,b) for(ll i = a;i < (ll)b;i++)
#define rrep(i,a,b) for(ll i = a;i >= (ll)b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
#define YES(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define Yes(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define yes(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

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
