// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e4+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
using namespace std;
int t,n,u,v,i;
ll ans,mx;
vector<int >e[maxn];
vector<ll>f[maxn];
ll w[maxn];
ll sum[maxn];//代表的是某个点邻居的数值之和
ll cnt[maxn];//代表的是某个点邻居平方之和
void slove(){
    cin>>n;for(int i=1;i<n;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(auto u:e[i]){
            f[i].push_back(w[u]);
            sum[i]+=w[u];
            cnt[i]=cnt[i]+w[u]*w[u];
        }
        sort(f[i].begin(),f[i].end(),greater<ll>());
    }
    for(int i=1;i<=n;i++){
        if(f[i].size()>=2){
            mx=max(mx,f[i][0]*f[i][1]);
            ans=ans+sum[i]*sum[i]-cnt[i];
            ans%=mod;
        }
    }
    cout<<mx<<" "<<(ans+mod)%mod;
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
/* 爆搜多的写法 时间复杂度最坏是是n^2 显然会超时
// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e4+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
using namespace std;
int t,n,u,v,i;
ll ans,mx;
vector<int >e[maxn];
ll w[maxn];
void dfs(int x,int fa,int cnt){
    if(cnt>=3) return ;
    for(auto u:e[x]){
        if(u!=fa){
            if(cnt==1){
            mx=max(w[u]*w[i],mx);
            ans+=w[u]*w[i];
            ans%=mod;
            }
            dfs(u,x,cnt+1);
        }
    }
    return ;
}
void slove(){
    cin>>n;for(int i=1;i<n;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    i=1;
    for(;i<=n;i++){
        dfs(i,-1,0);
    }
    cout<<mx<<" "<<(ans+mod)%mod;
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
 */