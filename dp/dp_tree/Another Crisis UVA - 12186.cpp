// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p; 正推 线性求出1-n的逆元
// 先求出阶乘fac 快速幂算出fac[n]的阶乘 线性倒推fac[n-1-1]的逆元 invfac[i-1]=invfac[i]*i 
//单个数的逆元是 inv[i]=fact[i-1]*invfact[i]
//v.insert(v.begin() + pos, x);
//插入x到当做pos下标
//*(pos--) 错误写法 是先引用在减
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
int  n,T;
int f[maxn],dp[maxn];
vector<int> e[maxn];
void dfs(int x, int fa){
    vector<int>tp; 
    int cnt=0;
    for(auto u:e[x]){
        if(u==fa ) continue;
        cnt++;
        dfs(u,x);
        tp.push_back(dp[u]);
    }
    if(cnt==0) {
        dp[x]=1;
        return;
    }
    sort(tp.begin(),tp.end());
    int ned=ceil(cnt*T*0.01);
    for(int i=0;i<ned;i++){
        dp[x]+=tp[i];
    }
    return ;
}
void slove(){
    for(int i=1;i<=n;i++){
        cin>>f[i];
        e[f[i]].push_back(i);
    }
    dfs(0,-1);
    cout<<dp[0]<<"\n";
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(cin>>n>>T){
        if(n+T==0) break;
        for(int i=0;i<=n;i++) e[i].clear(),dp[i]=0;
        slove();
    }
    return (0-0);
}