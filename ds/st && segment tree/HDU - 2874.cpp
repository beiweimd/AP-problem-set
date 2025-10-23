// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p; 正推 线性求出1-n的逆元
// 先求出阶乘fac 快速幂算出fac[n]的阶乘 线性倒推fac[n-1-1]的逆元 invfac[i-1]=invfac[i]*i 
//单个数的逆元是 inv[i]=fact[i-1]*invfact[i]
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
int n,m,c,l,r;
int f[maxn];
ll dis[maxn];
int deep[maxn];
bool vis[maxn];
int dp[maxn][20];
vector<pair<int,int > >e[maxn];
int getf(int v){
    if(f[v]==v)
        return v;    
    else {
        f[v]=getf(f[v]);
        return f[v];
    }
} 
void merge(int v,int u){
    int t1,t2;
    t1=getf(v);
    t2=getf(u);
    if(t1!=t2){
        f[t2]=f[t1];    //这里要让两人的祖先相同，合并祖先。
    }
    return ;
}
void dfs(int x,int fa, int cost ){
    dis[x]=dis[fa]+cost;
    dp[x][0]=fa;
    deep[x]=deep[fa]+1; 
    for(int j=1;j<=18;j++){
        dp[x][j]=dp[dp[x][j-1]][j-1];
    }
    for(auto u:e[x]){
        if(u.first==fa) continue;
        dfs(u.first,x,u.second);
    }
    return ;
}
int query(int l ,int r){
    if(deep[l]<deep[r]) swap(l,r);
    if(l==r ) return l;
    int diff=abs(deep[l]-deep[r]);
    for(int j=18;j>=0;j--){
        if(diff&(1<<j)) {
            l=dp[l][j];
        }
    }
    if(l==r)  return l;
    for(int j=18;j>=0;j--){
        if(dp[l][j]!=dp[r][j] ){
            l=dp[l][j];
            r=dp[r][j];
        }
    }
    return dp[l][0];
}
void slove(){
    //cin>>n>>m>>c;
    for(int i=1;i<=n;i++) {f[i]=i;e[i].clear();vis[i]=false;}
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
        merge(u,v);
    }
    for(int i=1;i<=n;i++){
        int clo=getf(i);
        if(vis[clo]) continue;
        vis[clo]=true;
        dfs(clo,0,0);
    }
    while(c--){
        cin>>l>>r;
        if(getf(l)!=getf(r) ){
            cout<<"Not connected";
        }
        else {cout<<dis[l]+dis[r]-2*dis[query(l,r)];}
        cout<<"\n";
    }
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(cin>>n>>m>>c){
        slove();
    }
    return (0-0);
}