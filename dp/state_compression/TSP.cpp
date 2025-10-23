// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p;
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
int g[30][30];
int dp[1100000][22]; // 走过的点为集合i 并且最后到 j的状态的 最小路径数量
int n;
void slove(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            dp[i][j]=1e7;
        }
    }
    // for(int k=0;k<n;k++){
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    //         }
    //     }
    // }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //cout<<g[i][j]<<" ";
        }
        //cout<<endl;
    }
    dp[1][0]=0;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)) continue;
            for(int k=0;k<n;k++){
                if(!(i & (1<<k))) continue;
                dp[i|(1<<j)][j]=min(dp[i|(1<<j)][j],dp[i][k]+g[k][j]);
            }
        }
    }
    int ans=1e8;
    for(int i=0;i<n;i++){
        ans=min(ans,dp[(1<<n)-1][i]+g[i][0]);
    }
    cout<<ans<<"\n";
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    slove();
    return (0-0);
}