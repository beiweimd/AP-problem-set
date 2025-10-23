// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=998244353;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
using namespace std;
int t,n,m,u,v;
ll dp[maxn];
int du[maxn];
vector<int >e[maxn];
ll f[maxn]; //代表的是以i结尾的长度
ll g[maxn]; //代表的是以i结尾的路径数量
ll quick_mod(ll a,ll b){
    ll s=1;
    while(b){
        if(b&1) {
            s=(s*a)%mod;
        }
        b=(b>>1);
        a*=a;
        a%=mod;
    }
    return s;
}
void top(){
    queue<int >q;
    for(int i=1;i<=n;i++) {
        if(du[i]==0) q.push(i);
    }
    while(!q.empty()){
        auto k=q.front();q.pop();
        for(auto u:e[k]){
            f[u]+=f[k]+g[k];
            g[u]+=g[k];
            g[u]%=mod;
            f[u]%=mod;
            du[u]--;
            if(!du[u])q.push(u);
        }
    }
}
void slove(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        e[u].push_back(v);
        du[v]++;
    }
    for(int i=1;i<=n;i++) g[i]=1;//初始化 因为题目说了路径的起点和终点可以重合
    top();
    array<ll,2>ans={0ll,0ll};
    //cout<<fixed<<setprecision(10)<<dp[n];
	for(int i=1;i<=n;i++){
        ans[0]+=f[i];
        ans[1]+=g[i];
    }
    ans[0]%=mod;
    ans[1]%=mod;
    //cout<<ans[0]<<" "<<ans[1]<<endl; 
    cout<<(mod+ans[0]*quick_mod(ans[1],mod-2))%mod;
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