#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
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
ll gcd(ll a,ll b){
    if(a%b==0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}
ll lcm(ll a,ll b){
    return ll(a/gcd(a,b))*b;
}
bool isPrime(ll x){
    for(ll i = 2;i*i <= x;i++){
        if(x%i==0)return false;
    }
    return true;
 }
map<ll,ll> Prime_factor(ll x){
    map<ll,ll>res;
    for(ll i = 2;i*i <= x;i++){
        while(x%i==0){
            res[i]++;
            x/=i;
        }
    }
    if(x!=1)res[x]=1;
    return res;
}
vector<ll> getPrime(ll x){
    vector<ll>res;
    ll i,j;
    vector<bool>isprime(x+1,true);
    isprime[0]=false;
    isprime[1]=false;
    for(i = 2;i <= x;i++){
        if(isprime[i]){
            res.push_back(i);
            for(j=i*2;j<=x;j+=i){
                isprime[j]=false;
            }
        }
    }
    return res;
}
vector<ll> divisor(ll x){
    vector<ll>res;
    for(ll i = 1;i*i<=x;i++){
        if(x%i==0){
            res.push_back(i);
            if(i!=x/i)res.push_back(x/i);
        }
    }
    return res;
}
template <typename T>
class BIT{
    public:
        ll n;
        vector<T>data;

        BIT(ll n):n(n),data(n+1,0){
        }

        void add(ll i,T value){
            i++;
            if(i==0)return;
            for(ll k=i;k<=n;k+=(k & -k)){
                data[k]+=value;
            }
        }

        T sum(ll a,ll b){
            return sum_sub(b-1)-sum_sub(a-1);
        }

        T sum_sub(ll i){
            i++;
            ll sum=0;
            if(i==0)return sum;
            for(ll k=i;k>0;k-=(k & -k)){
                sum+=data[k];
            }
            return sum;
        }

        T get(ll i){
            return sum(i,i+1);
        }

        void update(ll i,T value){
            add(i,value-get(i));
        }

        ll lower_bound(T x){
            if(x<=0){
                return 0;
            }else{
                ll i,r;
                i=0;
                r=1;
                while(r<n)r=r<<1;
                for(ll len=r;len>0;len=len>>1){
                    if(i+len<n&&data[i+len]<x){
                        x-=data[i+len];
                        i+=len;
                    }
                }
                return i;
            }
        }
};
/*-----------------------------------------------------------------------------*/

int main(void){
    map<int,int>mp;
    rep(i,0,4){
        ll a;
        cin>>a;
        mp[a]++;
    }
    Yes(mp.size()==2);
}