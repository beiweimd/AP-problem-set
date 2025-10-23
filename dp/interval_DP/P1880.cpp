// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e3;
const ll INF=1e17;
using namespace std;
int n;
ll a[maxn],ans1,ans2=1e9;
ll dp[maxn][maxn];
ll f[maxn][maxn];
ll qz[maxn][maxn]; // 从i到j的和
void slove(){ 
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];a[i+n]=a[i];
        qz[i][i]=qz[n+i][n+i]=a[i];
    }
    for(int len=2;len<=n;len++){ // 长度
        for(int i=1;i+len-1<=2*n;i++){ // i起点 i+len-1是终点
            int x=i,y=i+len-1;
            for(int j=1;j<len;j++){ // 枚举的是从i之后第几个开始断
                qz[x][y]=qz[x][x+j-1]+qz[x+j][y];
                if(dp[x][y]==0) dp[x][y]=qz[x][y]+dp[x][x+j-1]+dp[x+j][y];
                else dp[i][i+len-1]=max(dp[i][i+len-1],qz[x][y]+dp[x][x+j-1]+dp[x+j][y]);
                
                
                if(f[i][i+len-1]==0) f[i][i+len-1]=f[x][x+j-1]+f[x+j][y]+qz[x][y];
                else f[i][i+len-1]=min(f[i][i+len-1],f[x][x+j-1]+f[x+j][y]+qz[x][y]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans2=min(ans2,f[i][i+n-1]);
        ans1=max(ans1,dp[i][i+n-1]);
    }
    cout<<ans2<<"\n"<<ans1;
	return;
}
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