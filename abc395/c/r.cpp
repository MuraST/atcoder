#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

struct Exist {

    ll num;
    ll loc;

    bool operator<(const Exist& another) const {
        return num*300000 + loc < another.num*300000 + another.loc;
    }

};

int main() {

    int N;
    cin >> N;

    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<Exist> exist;
    
    rep(i, N) {

        exist.push_back({A[i],i});

    }

    sort(exist.begin(), exist.end());

    int ans = -1;

    rep(i, N-1) {
        
        int j = 1;
        while (exist[i].num == exist[i+j].num) {
            j++;
            
            if (exist[i].num != exist[i+j].num) {
                if (ans == -1) {
                    ans = exist[i+j-1].loc - exist[i].loc + 1;
                } else if (ans > exist[i+j-1].loc - exist[i].loc + 1) {
                    ans = exist[i+j-1].loc - exist[i].loc + 1;
                }
                i += j;
                break;
            }
            
        }
       
    }

    //rep(i, N) {
    //    cout << exist[i].loc << " " << exist[i].num << endl;
    //}

    cout << ans;


}