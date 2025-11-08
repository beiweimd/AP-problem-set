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
const int maxn=3e3;
const ll INF=1e17;
using namespace std;
int n;
ll val[maxn];
ll dp[maxn][maxn];
// 拿走区间[i,j]能获得的最大价值
void slove(){
	cin>>n;
    for(int i=2;i<n;i++){
        for(int j=i;j<n;j++){
            dp[i][j]=INF;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=2;i<n;i++){
        dp[i][i]=val[i]*val[i-1]*val[i+1];
    }
    for(int len=1;len<=n;len++){ // 枚举长度
        for(int i=2;i+len<n;i++){
            int j=i+len;
            // 这里是枚举k 就是最后一次拿走卡片的位置
            for(int k=i;k<=j;k++){
                dp[i][j]=min(dp[i][j],
                val[k]*val[i-1]*val[j+1]+
                dp[i][k-1]+dp[k+1][j]
                );
            }
        }
    }
    cout<<dp[2][n-1];
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