// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=1002;
const ll INF=1e17;
using namespace std;
int n,k;
int dp[maxn*10]; // 前i个排列中 逆序对为j的数量
int sum[100][maxn*10];
void slove(){
    cin>>n>>k;
    sum[2][0]=1;
    for(int i=1;i<=n;i++){ // 枚举第几个数
        for(int j=0;j<=min(k,(i*(i-1))/2);j++){ // 枚举转移过来的i 的逆序对数量
            // for(int p=0;p<=min(i-1,j);p++){ // 枚举从p-1转移过来的 就是其实不需要考虑位置 因为我们肯定是可以 +0和 i 个 
            //     dp[i][j]+=dp[i-1][j-p];
            //     dp[i][j]%=mod;
            // }
            int lef=j;
            int rig=j-min(i-1,j);
            if(lef>rig) swap(lef,rig);
            if(lef<=0) dp[j]=sum[2][rig];
            else dp[j]=sum[2][rig]-sum[2][lef-1];
            dp[j]%=mod;
            sum[3][j]=dp[j];
            sum[3][j]%=mod;
        }
        for(int j=1;j<=k;j++){
            sum[2][j]=sum[3][j];
            sum[2][j]+=sum[2][j-1];
            sum[2][j]%=mod;
        }
    }
    cout<<(mod+dp[k])%mod;
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