// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const ll INF=1e17;
const int maxn=3e5;
using namespace std;
ll dis[maxn],a[maxn];
int n,m,k,vis[maxn];
vector<pair<int,ll> >e[maxn];
struct Compare {
    bool operator()(const pair<ll, int>& a, const pair<ll, int>& b) {
        return a.first > b.first;
    }
};
priority_queue<pair<ll, int>, vector<pair<ll, int>>, Compare> q;
void check(){
    while(!q.empty()){
        auto k=q.top();
        q.pop();
        int x=k.second;
        //ll tim=k.first;
        if(x<0){
            a[-1*x]--;
            if(a[-1*x]<=0) {dis[-1*x]=min(dis[-1*x],k.first);q.push({k.first,-1*x});}
            continue;
        }
        if(vis[x]==1) continue;
        vis[x]=1;
        for(auto [u,w]:e[x]){
            if(a[u]<=1 && dis[x]+w<=dis[u]){
                dis[u]=dis[x]+w;
                q.push({dis[u],u});
            }
            else q.push({dis[x]+w,-u});
        }
    }
    return ;
}
void slove(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=0) dis[i]=INF;
    }
    for(int j=1;j<=k;j++){
        ll t;cin>>t;
        int num,id;cin>>num;
        for(int i=1;i<=num;i++){
            cin>>id;
            dis[id]=min(dis[id],t);
        }
    }
    for(int i=1;i<=n;i++){
        if(dis[i]!=INF) q.push({dis[i],i});
    }
    for(int i=1;i<=m;i++){
        int u,v;ll w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
    }
    check();
    for(int i=1;i<=n;i++){
        if(dis[i]!=INF) cout<<dis[i]<<" ";
        else cout<<-1<<" ";
    }
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    slove();
    return (0-0);
}