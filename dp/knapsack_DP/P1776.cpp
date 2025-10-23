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
int n,W;
int dp[maxn];
using namespace std;
void slove(){
    cin>>n>>W;
    for(int i=1;i<=n;i++){
        int v,w,m;
        cin>>v>>w>>m;
        vector<int>compose;
        int base=1;
        while(base<m){
            m-=base;
            compose.push_back(base);
            base*=2;
        }
        compose.push_back(m);
        int len=compose.size();
        for(int j=len-1;j>=0;j--){ // 枚举二进制拆分的logm个物品
            for(int k=W;k>=w*compose[j];k--){
                dp[k]=max(dp[k],dp[k-w*compose[j]]+v*compose[j]);
            }
        }
    }
    cout<<dp[W];
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