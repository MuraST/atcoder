#include "template.hpp"


int N;
vector<vector<ll>>G;

int f(int root){
    int res = 1000000000;
    int x = G[root].size();
    int y;
    map<int,int>cnt;
    fore(v,G[root]){
        int knum = G[v].size()-1;
        cnt[knum]++;
    }
    fore(e,cnt){
        y = e.first;
        if(y == 0){
            x -= e.second;
            continue;
        }
        int sum = x*(y+1);
        chmin(res,N-1-sum);
        x -= e.second;
    }
    return res;
}

int main(void){
    cin>>N;
    G.resize(N);
    rep(i,0,N-1){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans = 1000000000;
    rep(i,0,N){
        int res = f(i);
        chmin(ans,res);
    }
    cout<<ans<<endl;
}