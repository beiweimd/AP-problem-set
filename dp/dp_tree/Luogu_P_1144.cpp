// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=100003;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=2e6;
using namespace std;
int t,n,m,u,v,vis[maxn],flag;
ll p,k,w,dp[maxn],dis[maxn],cnt[maxn];
vector<pair<int,ll> >e[maxn];
struct Compare{
    bool operator()(const pair<ll,int >&a,const pair<ll,int>&b){
        return a.first>b.first;
    }
};
void dij(){
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[1]=0;
    cnt[1]=1;
    priority_queue<pair<ll , int >,vector<pair<ll,int> >,Compare >q ;  // 第一个是距离 第二个是点
    q.push(make_pair( 0,1 ) );
    while(!q.empty()){
        auto   k=q.top();
        q.pop();
        if(vis[k.second]==1) continue;
            vis[k.second]=1;
            int v=k.second;
            for(auto [u,val]:e[k.second]){                
            if(dis[u] > dis[v] + val){   // 更短的路，直接更新并重置路径数
                dis[u] = dis[v] + val;
                cnt[u] = cnt[v];
                q.push(make_pair(dis[u], u));
            }
            else if(dis[u] == dis[v] + val){  // 一样长的路，累加
                cnt[u] = (cnt[u] + cnt[v]) % mod;
            }
            }
    }
    return ;
}
void slove(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        e[u].push_back({v,1});
        swap(u,v);
        e[u].push_back({v,1});
    }
    dij();
    for(int i=1;i<=n;i++){
        cout<<cnt[i]<<"\n";
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    t=1;
    while(t--){
        slove();
    }
    return 0;
}