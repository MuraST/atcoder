
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

long long power(long long a,long long b,long long m){
    long long res = 1;
    a %= m;
    while(b > 0){
        if(b & 1) res = (res * a) % m;
        a = (a*a) % m;
        b >>= 1;
    }
    return res;
}

struct Comb{
    private:
        int MAX;
        long long MOD;
        vector<long long> fact;
        vector<long long> inv_fact;
    
    public:
        Comb(int max_n,long long mod){
            this->MAX = max_n;
            this->MOD = mod;

            fact.resize(MAX+1);
            inv_fact.resize(MAX+1);

            fact[0] = 1;
            for(int i = 1;i <= MAX;i++){
                fact[i] = (fact[i-1] * i) % MOD;
            }

            inv_fact[MAX] = power(fact[MAX], MOD-2,MOD);

            for(int i = MAX-1;i >= 0;i--){
                inv_fact[i] = (inv_fact[i+1] * (i+1)) % MOD;
            }
        }

        ll com(int n,int r){
            assert(0 <= r);
            assert(r <= n);
            assert(n <= MAX);

            long long res = fact[n];
            res = (res * inv_fact[r]) % MOD;
            res = (res * inv_fact[n-r]) % MOD;
            return res;
        }
};


using mint = modint998244353;



int main(void){
    string S;
    cin>>S;
    ll N = S.length();
    vector<vector<ll>>sum(N+1,vector<ll>(10,0));
    vector<vector<ll>>rsum(N+1,vector<ll>(10,0));
    rep(i,1,N+1){
        rep(j,0,10){
            sum[i][j] = sum[i-1][j];
        }
        sum[i][S[i-1]-'0']++;
    }
    rrep(i,N-1,0){
        rep(j,0,10){
            rsum[i] = rsum[i+1];
        }
        rsum[i][S[i]-'0']++;
    }

    mint ans = 0;
    Comb c(1000010,modA);
    rep(i,0,N){
        int m = S[i]-'0';
        if(m == 9) continue;
        ll ln = sum[i+1][m]-1;
        ll rn = rsum[i+1][m+1];
        
        //cout<<ln <<" " <<rn<<endl;
        if(rn == 0) continue;
        ans += c.com(ln+rn,ln+1);
    }
    cout<<ans.val()<<endl;
}
