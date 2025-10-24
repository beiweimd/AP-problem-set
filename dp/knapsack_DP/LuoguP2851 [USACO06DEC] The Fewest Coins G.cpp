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
const int maxn=2e6;
const int inf=1e9;
const int M=1300000;
const ll INF=1e17;
using namespace std;
int n,t;
int v[maxn],c[maxn];
int f[maxn]; // 代表不考虑数量的情况下 凑出来i要多少个硬币
int dp[maxn],sum,vmax;
void slove(){
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        vmax=max(vmax,v[i]);
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        sum=sum+c[i]*v[i];
    }
    sum=min(sum,t+vmax*vmax);
    f[0]=dp[0]=0;
    for(int i=1;i<=M;i++) f[i]=dp[i]=inf;
    for(int i=1;i<=n;i++){
        for(int j=0;j+v[i]<=M;j++){
            f[j+v[i]]=min(f[j+v[i]],f[j]+1);
        }
    }
    for(int i=1;i<=n;i++){
        vector<int >tp;
        int base=1;
        while(c[i]>base){
            c[i]-=base;
            tp.push_back(base);
            base*=2;
        }
        tp.push_back(c[i]);
        for(auto u:tp){
            for(int j=sum;j>=u*v[i];j--){
                dp[j]=min(dp[j],dp[j-u*v[i]]+u);
            }
        }
    }
    int ans=inf;
    for(int i=t;i<=sum;i++){
        if(dp[i]!=inf && f[i-t]!=inf){
            ans=min(ans,dp[i]+f[i-t]);
        }
    }
    if(ans==inf) cout<<-1;
    else cout<<ans;
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	slove();
    return (0-0);
}