#include "template.hpp"

int main(void){
    ll N,M,X;
    cin>>N>>M>>X;
    vector<vector<ll>>G(N),g(N);
    rep(i,0,M){
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        G[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<ll>>dist(N,vector<ll>(2,INF));
    vector<vector<ll>>flag(N,vector<ll>(2,0));
    min_priority_queue<pair<ll,ll>>que;
    dist[0][0] = 0;
    flag[0][0] = 0;
    que.push({0,0});
    while(!que.empty()){
        ll v = que.top().second /2;
        ll mode = que.top().second % 2;
        ll d = dist[v][mode];
        que.pop();
        if(flag[v][mode ] == 1) continue;
        flag[v][mode] = 1;
        if(!flag[v][1-mode]){
            if(d+X < dist[v][1-mode]){
                dist[v][1-mode] = d+X;
                que.push({d+X,2*v+(1-mode)});
            }
        }
        if(mode == 0){
            fore(next_v,G[v]){
                if(!flag[next_v][mode]){
                    if(d+1 < dist[next_v][mode]){
                        dist[next_v][mode] = d+1;
                        que.push({d+1,2*next_v+mode});
                    }
                }
            }
        }else{
            fore(next_v,g[v]){
                if(!flag[next_v][mode]){
                    if(d+1 < dist[next_v][mode]){
                        dist[next_v][mode] = d+1;
                        que.push({d+1,2*next_v+mode});
                    }
                }
            }
        }
    }
    ll ans = min(dist[N-1][0],dist[N-1][1]);
    if(ans == INF) ans = -1;
    cout<<ans<<endl;
}