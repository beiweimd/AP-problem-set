// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=998244353;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=2e3+100;
using namespace std;
int t,n,m,u,v;
ll inv[4*maxn];
ll dp[maxn][maxn*2],ans;// 代表有i个瓜子 j个瓜子壳的概率
ll add(ll a,ll b){
    return (a+b+mod)%mod;
}
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
void slove(){
    cin>>n;
    for(int i=1;i<=3*n;i++){
        inv[i]=quick_mod(i,mod-2);
    }
    // for(int i=n-1;i>=0;i--){
    //     for(int j=n*2;j>=0;j--){
    //         dp[i][j]=dp[i][j+1]*(j+1)*inv[i+j+1]; 
    //         dp[i][j]%=mod;
    //         if(j>=2) dp[i][j]=dp[i][j]+(dp[i+1][j-2]+1)*(i+1)*inv[i+j-1];
    //     //    dp[i][j]%=mod;
    //         dp[i][j]=add(dp[i][j],mod);
    //         cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
    //     }
    //     //cout<<dp[1][2]<<endl;        
    // }
/*
正推 反推 就是合法性(说起来有点怪)的东西，大概就是正推要避免一些无意义无期望的神奇东西，所以要计算概率
*/
    for(int i=1;i<=n;i++){
        for(int j=0;j<=2*n-2;j++){
            dp[i][j]=dp[i-1][j+2]*i%mod*inv[i+j]%mod; //这种是 扔一个瓜子 获得两个瓜子壳
            dp[i][j]++;
            if(j!=0) dp[i][j]+=dp[i][j-1]*j%mod*inv[i+j]%mod;
        }
    }
    cout<<dp[n][0]; // 代表最终状态 剩下n个瓜子和0个瓜子壳期望多少次
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