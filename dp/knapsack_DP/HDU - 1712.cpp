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
const int maxn=3e3;
const ll INF=1e17;
using namespace std;
int n,m,a[maxn][maxn];
int dp[maxn];
int f[maxn];
void slove(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            //cout<<a[i][j]<<" ";
        }
        //cout<<endl;
    }
    for(int i=0;i<=m;i++) dp[i]=f[i]=0;
     // dp maxn指的是确定的前面i-1轮花费时间的最大利润
     //这里的f指的是这一轮更新的最大利润
     //使用两个是为了防止重复覆盖 导致一门课分段被选了两次
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            for(int k=j;k>=1;k--){    
                f[j]=max(f[j],dp[j-k]+a[i][k]);
            }
        }
        for(int j=0;j<=m;j++) dp[j]=max(dp[j],f[j]);
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    cout<<"\n";
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(1){
        cin>>n>>m;
        if(n==0 && m==0) break;
		slove();
    }
    return (0-0);
}