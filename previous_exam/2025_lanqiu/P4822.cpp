// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
int n,m,k,u,v,s,t;
ll w,dis[maxn],ans=INF;
bool vis[maxn];
vector<pair<int ,ll>>e[maxn];
struct Compare{
    bool operator()(const pair<ll,int >&a ,const pair<ll,int > &b){
        return a.first>b.first;
    }
};
priority_queue<pair<ll,int >,vector<pair<ll,int > >,Compare >q;
void init(){
    for(int j=1;j<=n*k+n;j++){
        dis[j]=INF;  
        vis[j]=0;
    }
    for(int j=1;j<=n*k+n;j+=n){
        dis[j]=0;
        q.push({0,j});
    }
}
void dij(){
    init();
    while(!q.empty()){
        auto k1=q.top();
        q.pop();
        if(vis[k1.second]==1) continue;
        vis[k1.second]=1;
        for(auto [to,val]:e[k1.second]){
            if(dis[to]>=val+k1.first){
                dis[to]=val+k1.first;
                q.push({dis[to],to});
            }
        }
    }
}
void slove(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
        w=w/2;
        for(int j=1;j<=k;j++){
            u+=n;v+=n;
            e[u-n].push_back({v,w});
            e[v-n].push_back({u,w});
            e[u].push_back({v,w*2});
            e[v].push_back({u,w*2});
        }
    }
    dij();
    for(int j=n;j<=n*k+n;j+=n){
        //cout<<dis[j]<<endl;
        ans=min(ans,dis[j]);
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