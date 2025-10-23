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
int fa[maxn],x,y,n;
vector<int >e[20000];
int deep[20000][20],du[maxn];
int dep[maxn];
void dfs(int now,int pre){
    for(int j=1;j<=18;j++){
        deep[now][j]=deep[deep[now][j-1]][j-1];
    }
    dep[now]=dep[pre]+1;
    for(auto u:e[now]){
        if(u==pre) continue;
        dfs(u,now);
    }
    return ;
}
int query(int l,int r){
    if(dep[l]<dep[r]) swap(l,r);
    int diff=dep[l]-dep[r];
    for(int j=18;j>=0;j--){
        if(diff>=(1<<j)) {
            diff=diff-(1<<j);
            l=deep[l][j];
        }
    }
    //cout<<l<<" "<<r<<endl;
    if(l==r) return l;
    for(int j=18;j>=0;j--){
        if(deep[l][j]!=deep[r][j]){
            l=deep[l][j];
            r=deep[r][j];
        }
    }
    return deep[l][0];
}
void slove(){
    int root=1;
    for(int i=1;i<=n;i++) e[i].clear(),du[i]=0;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        fa[y]=x;
        du[y]++;
        e[y].push_back(x);
        e[x].push_back(y);
        deep[y][0]=x;
    }
    for(int i=1;i<=n;i++) if(!du[i]) root=i;
    dfs(root,0);
    cin>>x>>y;
    cout<<query(x,y)<<"\n";
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
		slove();
    }
    return (0-0);
}