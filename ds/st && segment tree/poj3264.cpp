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
const int maxn=1e5;
const ll INF=1e17;
using namespace std;
int dp[maxn][20][2];
int n,Q,l,r;
void init(){
    for(int j=1;j<=19;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            dp[i][j][0]=max(dp[i][j-1][0],dp[i+(1<<(j-1))][j-1][0]);
            dp[i][j][1]=min(dp[i][j-1][1],dp[i+(1<<(j-1))][j-1][1]);
        }
    }
}
int query_min(){
    if(l==r) return dp[l][0][0];
    int k=log2(r-l+1);
    return min( dp[l][k][1], dp[r-(1<<k)+1][k][1]);
}
int query_max(){
    if(l==r) return dp[l][0][0];
    int k=log2(r-l+1);
    return max( dp[l][k][0], dp[r-(1<<k)+1][k][0]);
}
void slove(){
    cin>>n>>Q;
    for(int i=1;i<=n;i++){
        cin>>dp[i][0][0];
        dp[i][0][1]=dp[i][0][0];
    }
    init();
    while(Q--){
        cin>>l>>r;
        cout<<query_max()-query_min()<<"\n";
    }
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