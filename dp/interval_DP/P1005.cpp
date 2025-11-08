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
int n,m;
ll ans,dp[100][110],val[110][110];
//这里的dp[i j]代表 还剩i j这个区间没有被选的最大得分
ll qp(ll a,ll b){
    ll s=1;
    while (b) {
        if (b & 1) { s = s * a; }
        a = a * a;
        b >>= 1;
    }
    return s;
}
void slove(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>val[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m;k++) dp[j][k]=0ll;
        }
        for(int len=m-1;len>=1;len--){
            for(int j=1;j+len-1<=m;j++){
                int k=j+len-1;
                //剩的这个区间不能再左边 才能选择最左边
                int used=m-(k-j+1);
                if(j!=1) dp[j][k]=max(dp[j][k],dp[j-1][k]+val[i][j-1]*qp(2,used));
                if(k!=m) dp[j][k]=max(dp[j][k],dp[j][k+1]+val[i][k+1]*qp(2,used));
            }
        }
        ll ans1=0ll;
        for(int j=1;j<=m;j++) {
            ans1=max(ans1,dp[j][j]+val[i][j]*qp(2,m));
        }
        ans+=ans1;
    }
    cout<<ans;
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