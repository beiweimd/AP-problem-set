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
const int maxn=2e7+100;
const ll INF=1e17;
using namespace std;
int n,A,B,C;
ll a[maxn];
void slove(){
    scanf("%d%d%d%d%d", &n, &A, &B, &C, a + 1);
    for (int i = 2; i <= n; i++)
	    a[i] = ((long long) a[i - 1] * A + B) % 100000001;
    for (int i = 1; i <= n; i++)
	    a[i] = a[i] % C + 1;
    db ans=0;
    for(int i=1;i<n;i++){
        ans=ans+1.0/max(a[i],a[i+1]);
    }
    ans=ans+1.0/max(a[1],a[n]);
    cout<<fixed<<setprecision(3)<<ans;
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