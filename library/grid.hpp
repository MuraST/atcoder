#pragma once
#include "template.hpp"

const string UDLR = "UDLR";
constexpr pair<int,int> UV = {-1,0};
constexpr pair<int,int> DV = {1,0};
constexpr pair<int,int> LV = {0,-1};
constexpr pair<int,int> RV = {0,1};
constexpr int HV[] = {-1,1,0,0,-1,-1,1,1};
constexpr int WV[] = {0,0,-1,1,1,-1,-1,1};

pair<int,int> fdir(char dir){
    if(dir == 'U')return UV;
    if(dir == 'D')return DV;
    if(dir == 'L')return LV;
    if(dir == 'R')return RV;
    exit(1);
}

bool clampp(ll H,ll W,ll Hc,ll Wc,ll dir){
    ll Hn = Hc + HV[dir];
    ll Wn = Wc + WV[dir];
    if(clamp(Hn,0LL,H-1) != Hn || clamp(Wn,0LL,W-1) != Wn){
        return false;
    }
    return true;
}