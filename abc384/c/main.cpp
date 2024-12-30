#include "template.hpp"


bool fcomp(const pair<ll,string>& a,const pair<ll,string>& b){
    if(a.first != b.first){
        return a.first > b.first;
    }
    return a.second < b.second;
}
int main(void){
    string S ="ABCDE";
    vector<ll>val(5);
    rep(i,0,5){
        cin>>val[i];
    }
    vector<pair<ll,string>>P;
    rep(i,1,1<<5){
        int score = 0;
        string T = "";
        rep(j,0,5){
            if(i>>j &1){
                score += val[j];
                T += S[j];
            }
        }
        P.push_back({score,T});
    }
    sort(all(P),fcomp);
    fore(ans,P){
        cout<<ans.second<<endl;
    }
}