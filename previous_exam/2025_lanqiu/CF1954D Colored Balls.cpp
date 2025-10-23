// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=998244353;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=5005;
const ll INF=1e17;
using namespace std;
int n,a[maxn];
ll sum[maxn][maxn],ans;
ll f[maxn][maxn];// 代表前i个物品凑出j的方案数量
void add(ll &x,ll y){
    x=(x+y)%mod;
    return ;
}
void slove()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    f[0][0]=sum[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=5000;j++){ 
            if(j>=a[i]) add(f[i][j],sum[i-1][j-a[i]]);
            sum[i][j]=(sum[i-1][j]+f[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5000;j++){
            add(ans,f[i][j]*max(a[i],(j-1)/2+1));
        }
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