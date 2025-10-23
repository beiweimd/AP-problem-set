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
ll t1,t2;
// struct Compare{
//     bool operator()(const pair<ll,ll> &a,const pair<ll,ll>&b){
//         if(a.first!=b.first ) return a.first>b.first;
//         else return a.second>b.second;
//     }
// };
// priority_queue< pair<ll,ll> ,vector<pair<ll,ll> > ,Compare > q;
ll ans,pre;
vector<pair<ll,ll> >p;
void slove(){
    cin>>n;for(int i=1;i<=n;i++){
        cin>>t1>>t2;
        p.push_back({t1,t2});
    }
    sort(p.begin(),p.end(),[](const pair<ll,ll> &a,const pair<ll,ll>&b){
        return a.second<b.second;
    }
    );
    priority_queue<ll>q;
    for(auto u:p){
        if(u.first+pre<=u.second){ // 如果可以修建
            ans++;
            pre+=u.first;
            q.push(u.first);
        }
        else{ // 不能修建的情况 那么这个时候 要么目前的这个不修 要么前面耗时最久的不修
            if(u.first>=q.top()) continue; //目前这个建筑耗费的时间最长 就没必要删除之前的
            ans--;
            pre-=q.top();
            pre+=u.first;
            q.pop();
            q.push(u.first);
            if(pre<=u.second){
                ans++;
            }
        }
    }
    cout<<ans;
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
		slove();
    }
    return (0-0);
}