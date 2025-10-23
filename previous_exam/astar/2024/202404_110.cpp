// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p;
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=998244353;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=5010;
const ll INF=1e17;
using namespace std;
int n,k;ll ans; string s;
ll dp[10][maxn][2][2]; // i结尾修改了k次并且最后一个是0/1的情况有多少
int c(int pos,int y){
    int num=s[pos]-'0';
    if(y==1) num=(num^1);
    return num;
}
void slove(){
    cin>>n>>k;
	cin>>s;
    s=" "+s;
    if(n==1){
       if(k==0) cout<<1;
       else cout<<2;
       return ; 
    }
    if(n==2){
        if(k==0) cout<<1;
        if(k==1) cout<<3;
        if(k>=2) cout<<4;
        return ;
    } //  比较狗屎的特判
    dp[2][0][c(1,0)][c(2,0)]=1;
    dp[2][2][c(1,1)][c(2,1)]=1;
    dp[2][1][c(1,1)][c(2,0)]=1;
    dp[2][1][c(1,0)][c(2,1)]=1;
    for(int i=3;i<=n;i++){
        int x=c(i,0);
        for(int j=0;j<i;j++){ // 枚举前面改变了多少次
            for(int l=0;l<=1;l++){
                for(int r=0;r<=1;r++){
                    if(l==1 && r==1 && x==0) continue;
                    dp[1][j][r][x]+=dp[2][j][l][r];
                    dp[1][j][r][x]%=mod;
                }
            }
        }
        x=c(i,1);
        for(int j=0;j<i;j++){ // 枚举前面改变了多少次
            for(int l=0;l<=1;l++){
                for(int r=0;r<=1;r++){
                    if(l==1 && r==1 && x==0) continue;
                    dp[1][j+1][r][x]+=dp[2][j][l][r];
                    dp[1][j+1][r][x]%=mod;
                }
            }
        }
        for(int j=0;j<=i;j++){
            for(int l=0;l<=1;l++){
                for(int r=0;r<=1;r++){
                    dp[2][j][l][r]=dp[1][j][l][r];
                    dp[1][j][l][r]=0; // 滚动优化记得清空数组
                }
            }
        }
    }
    for(int i=0;i<=k;i++){
        for(int l=0;l<=1;l++){
            for(int r=0;r<=1;r++){
                ans+=dp[2][i][l][r];
                ans%=mod;
            }
        }
    }
    cout<<(ans+mod)%mod;
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