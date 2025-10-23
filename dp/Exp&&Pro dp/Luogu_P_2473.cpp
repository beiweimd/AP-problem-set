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
const int maxn=110;
const ll INF=1e17;
using namespace std;
int k,n;
int p[maxn];
int constraint[maxn];
db dp[maxn][63000];
int vis[maxn];
db dfs(int x,int state){
    db s=0.0;
    if(dp[x][state]>-1e8) return dp[x][state];
    if(x==k+1){
        return 0;
    }
    dp[x][state]=0;
    for(int i=1;i<=n;i++){
        if((constraint[i]&state)==constraint[i]  ){
            s+=max(dfs(x+1,state),dfs(x+1,state|(1<<(i-1)))+p[i]);
        }//说明这个东西能选
        else{
            s+=dfs(x+1,state);
        }
    }
    s=s/n;
    dp[x][state]=s;
    return s;
}
void slove(){
    cin>>k>>n;
    for(int i=0;i<=k;i++){
        for(int j=0;j<(1<<(n));j++){
            dp[i][j]=-1e8;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>p[i];
        int cnt=0,num;
        while(1){
            cin>>num;if(num==0) break;
            cnt=cnt+(1<<(num-1));
        }
        constraint[i]=cnt;
        //cout<<cnt<<endl;
    }
    cout<<fixed<<setprecision(6)<<dfs(1,0);
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