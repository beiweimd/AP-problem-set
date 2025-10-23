// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
using namespace std;
int t,n,m,u,v;
ll dp[maxn];
int cnt[maxn];
int du[maxn];
vector<int >e[maxn];
ll f[maxn]; //代表的是从1到i结点的期望距离
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
    q.push(n);
    while(!q.empty()){
        auto k=q.front();q.pop();
        int sz=e[k].size();
        for(auto u:e[k]){
           du[u]--;
           f[u]=f[u]+(f[k]+1)*quick_mod(cnt[u],mod-2);
           f[u]%=mod;
           if(!du[u]) q.push(u); 
        }
    }
}
void slove(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        e[v].push_back(u);
        du[u]++;cnt[u]++;
    }
    top();
    //cout<<fixed<<setprecision(10)<<dp[n];
	//cout<<f[n];
    // //cout<<ans[0]<<" "<<ans[1]<<endl; 
    //cout<<(mod+ans[0]*quick_mod(ans[1],mod-2))%mod;
    //cout<<3*quick_mod(2,mod-2)%mod;
    cout<<f[1];
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