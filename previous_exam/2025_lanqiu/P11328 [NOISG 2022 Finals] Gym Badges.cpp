// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=6e5;
using namespace std;
int n;
ll x[maxn],l[maxn],ans,pre;
void slove(){
	cin>>n;for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        cin>>l[i];
    }
    vector<pair<ll,ll> >p;
    for(int i=1;i<=n;i++){
        p.push_back({x[i],l[i]+x[i]});
    }
    sort(p.begin(),p.end(),[](const pair<ll,ll>&a,const pair<ll,ll>&b ){
        if(a.second!=b.second) return  a.second<b.second;
        else return a.first<b.first;
    }
    );
    priority_queue<ll>q;
    for(auto u:p){
        if(pre+u.first<=u.second){
            ans++;
            pre+=u.first;
            q.push(u.first);
        }
        else{
            if(u.first>=q.top()) continue;
            ans--;
            pre-=q.top();
            q.pop();
            if(pre+u.first<=u.second){
                ans++;
                pre+=u.first;
                q.push(u.first);
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