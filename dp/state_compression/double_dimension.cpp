// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=1e3;
using namespace std;
int t,n;
int a[maxn][maxn];
void slove(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    auto dp=a;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]+=dp[i][j-1];
        }
    }
    /*
    int query(int x1 ,int y1 ,int x2 ,int y2){
    return s[x2][y2]+s[x1-1][y1-1]-s[x2][y1-1]-s[x1-1][y2];//左上角是x1 y1 右下角是x2 y2
}//的二维前缀和形式
     */
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]+=dp[i-1][j ];
        }
    }
    int ans=-1e8;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int b=i;b<=n;b++){
                for(int c=j;c<=n;c++){
                    ans=max(ans,dp[b][c]+dp[i-1][j-1]-dp[b][j-1]-dp[i-1][c]);
                }
            }
        }
    }
    cout<<ans;
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    t=1;
    while(t--){
		slove();
    }
    return 0;
}