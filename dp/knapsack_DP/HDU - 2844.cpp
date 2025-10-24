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
using namespace std;
int n,m,a[maxn],c[maxn];
bool dp[maxn];
void slove(){
    dp[0]=true;
    for(int i=1;i<=m;i++) dp[i]=false;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++){
        vector<int >t;
        int base=1;
        while(c[i]>base){
            c[i]-=base;
            t.push_back(base);
            base*=2;
        }
        t.push_back(c[i]);
        for(auto u:t){
            for(int j=m;j>=u*a[i];j--){
                dp[j]|=dp[j-u*a[i]];
            }
        }
    }    
    int ans=0;
    for(int i=1;i<=m;i++) if(dp[i]) ans++;
    cout<<ans<<"\n";
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