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

        com(int n,int r){
            assert(0 <= r);
            assert(r <= n);
            assert(n <= MAX);

            long long res = fact[n];
            res = (res * inv_fact[r]) % MOD;
            res = (res * inv_fact[n-r]) % MOD;
        }
}