// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
using namespace std;
int n;
ll d,l,ans,pre;
vector<pair<ll,ll> > p;
void slove(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>d>>l;
        p.push_back({d,l});
    }
    sort(p.begin(),p.end(),[](const pair<ll,ll>&a,const pair<ll,ll> &b){
        if(a.first!=b.first) return a.first<b.first;
        else return a.second>b.second;
    }
);
    priority_queue<ll,vector<ll>,greater<ll> > q;
    for(auto u:p){
        if(pre<u.first){ // 如果说时间是够用的话
            ans+=u.second;
            pre++;
            q.push(u.second);
        }
        else{
            if(u.second<=q.top()) continue;
            ans-=q.top();
            q.pop();
            ans+=u.second;
            q.push(u.second);
        }
    }
    cout<<ans;
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    slove();
    return (0-0);
}