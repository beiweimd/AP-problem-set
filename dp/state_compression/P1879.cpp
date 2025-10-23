// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p;
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e8;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
int n,m,a[13][13],f[13];
ll dp[13][1<<13],ans;
int quick(int a,int b){
    int s=1;
    while(b){
        if(b&1) s=s*a;        
        b>>=1;
        a=a*a;
    }
    return s;
}
bool check(int x){
    for(int i=0;i<m;i++){
        int l=(x&(1<<i));
        int r=(x&(1<<i+1));
        if(l!=0 && r!=0) return true;
    }
    return false;
}
void slove(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
        for(int j=m;j>=1;j--){
            sum=sum+a[i][j]*(1<<(j-1));
        }
        f[i]=sum;
        //cout<<sum<<endl;
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<(1<<m);j++){
            for(int k=0;k<(1<<m);k++){
                if( j&k) continue; // 上下有没有相邻的
                if((k&f[i])!=k) continue; //判断k中有没有不能中的
                if(check(j) or check(k)) continue;
                dp[i][k]+=dp[i-1][j];
            }
        }
    }
    for(int i=0;i<(1<<m);i++){
        //cout<<dp[n][i]<<endl;
        ans+=dp[n][i];
    }
    cout<<ans%mod;
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