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
const int maxn=4e5;
const ll INF=1e17;
using namespace std;
int n;
string s;
db f[maxn]; // 代表到i为止的期望
db g[maxn];  //代表 i所在的级长的o段的长度的期望
void slove(){
	cin>>n>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        if(s[i]=='?'){
            f[i]=f[i-1]+0.5*(1+2*g[i-1]);
            g[i]=(g[i-1]+1)*0.5;
        }
        if(s[i]=='x') {
            f[i]=f[i-1];
            g[i]=0;
        }
        if(s[i]=='o'){
            f[i]=f[i-1]+1+2*g[i-1];
            g[i]=g[i-1]+1;
        }
    }
    cout<<fixed<<setprecision(4)<<f[n];
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