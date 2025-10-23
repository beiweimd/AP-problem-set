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
const int maxn=4000;
const ll INF=1e17;
using namespace std;
int n,m,ans;
int  flag[maxn];
int dp[maxn];
int a[maxn];
void d(){
  dp[0]=1;
  for(int i=1;i<=3000;i++) dp[i]=0;
  int c=0;
  for(int i=1;i<=n;i++){
    if(flag[i]) continue;
    else c++;
    for(int j=3000;j>=a[i];j--){
      dp[j]|=dp[j-a[i]];
    }
  }
  int tmp=0;
  for(int i=1;i<=3000;i++) {
    if(dp[i]) {
      tmp++;
    } 
  }
  ans=max(ans,tmp);
  return ;
}
void dfs(int x,int cnt){ // x代表选到了第几个数 cnt代表舍弃了几个
  if(cnt>m) return ;
  if(x==n  ){
    if(cnt==m) d();
    return ;
  }
  dfs(x+1,cnt); // 不丢这一个
  flag[x+1]=true; // 1代表丢了
  dfs(x+1,cnt+1);
  flag[x+1]=false;
}
void slove(){
	cin>>n>>m;
  for(int i=1;i<=n;i++) cin>>a[i];
  dfs(0,0);
  cout<<ans;
  return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
		slove();
    }
    return (0-0);
}