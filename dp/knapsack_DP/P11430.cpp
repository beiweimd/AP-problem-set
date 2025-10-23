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
ll dp[maxn],ans,n,m,f[maxn];
void slove(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int p,t,o;
        cin>>p>>t>>o;
        for(int j=m;j>=p;j--){
            // f代表的是前i-1个游戏中花费j代价的最大花费
            dp[j]=f[j-p]; // 这里dp是一个临时数组 代表的是你已经花费了p的代价学会玩这个游戏 但是还没有玩游戏并且总花费是j的情况的收益
        }
        for(int j=p+t;j<=m;j++){
            dp[j]=max(dp[j],dp[j-t]+o);
            f[j]=max(f[j],dp[j]);
        }
    }
    for(int i=1;i<=m;i++) ans=max(ans,f[i]);
    cout<<ans;
	return;
}
// 本题技巧 借用额外的一个存储信息 来维护DP的转移
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