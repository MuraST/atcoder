#include "template.hpp"

int main(void){
    ll N,M;
    cin>>N>>M;
    vector<ll>A(M);
    vector<ll>B(M);

    rep(i,0,M){
        cin>>A[i]>>B[i];
        A[i]--;
        B[i]--;
    }
    dsu d(N);
    vector<pair<ll,pair<ll,ll>>>P;
    rep(i,0,M){
        if(d.same(A[i],B[i])){
            P.push_back({i,{A[i],B[i]}});
        }else{
            d.merge(A[i],B[i]);
        }
    }
    map<ll,deque<pair<ll,pair<ll,ll>>>>task;
    fore(e,P){
        ll l = d.leader(e.second.first);
        task[l].push_back(e);
    }
    //task[l]に余分なケーブルをpush

    map<ll,ll>lead;
    rep(i,0,N){
        lead[d.leader(i)] = 1;
    }

    set<pair<ll,ll>>S;
    fore(e,lead){
        ll le = e.first;
        S.insert({(ll)task[le].size(),le});
    }
    //Sに{余分ケーブル数,リーダー}をinsert

    vector<tuple<ll,ll,ll>>ans;
    while(S.size()>1){
        pair<ll,ll> ne = *(S.begin());
        S.erase(S.begin());
        //一番余裕がないグループをneにとってくる

        auto itr = S.end();
        itr--;
        pair<ll,ll> pa = *itr;
        S.erase(itr);
        //一番余ってるグループをpaにとってくる

        pair<ll,pair<ll,ll>>tas = task[pa.second].front();
        task[pa.second].pop_front();
        //tasに余分ケーブルを引っ張ってくる
        ans.push_back({tas.first+1,tas.second.first+1,ne.second+1});

        pa.first--;
        S.insert(pa);
    }

    cout<<ans.size()<<endl;
    rep(i,0,ans.size()){
        cout<<get<0>(ans[i])<<" "<<get<1>(ans[i])<<" "<<get<2>(ans[i])<<endl;
    }
}