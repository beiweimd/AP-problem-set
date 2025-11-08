// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p; 正推 线性求出1-n的逆元
// 先求出阶乘fac 快速幂算出fac[n]的阶乘 线性倒推fac[n-1-1]的逆元 invfac[i-1]=invfac[i]*i 
//单个数的逆元是 inv[i]=fact[i-1]*invfact[i]
//v.insert(v.begin() + pos, x);
//插入x到当做pos下标
//*(pos--) 错误写法 是先引用在减
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=55;
const ll INF=1e17;
using namespace std;
int n;
int pre[55][55];
int dp[maxn][maxn][maxn][maxn];
// 代表左上角切刀右下角的最小代价
int sum(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) { return 0; }
    return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
}
void slove(){
	cin>>n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char s;cin>>s;
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (s=='#');
        }
    }
    for(int h=1;h<=n;h++){
        for(int w=1;w<=n;w++){
            for(int x=1;x+h-1<=n;x++){
                for(int y=1;y+w-1<=n;y++){
                    int l=x+h-1;
                    int r=y+w-1;
                    if(sum(x,y,l,r)==0){
                        dp[x][y][l][r]=0;
                        continue;
                        //即说明这一块全部都是白色 不需要进行切除
                    }
                    int cost=max(h,w);
                    for(int k=x;k<l;k++){ //枚举横着切 这样就是一个小范围推大范围的搞法
                        cost=min(cost,dp[x][y][k][r]+dp[k+1][y][l][r]);
                    }
                    for(int k=y;k<r;k++){
                        cost=min(cost,dp[x][y][l][k]+dp[x][k+1][l][r]);
                    }
                    dp[x][y][l][r]=cost;
                }
            }
        }
    }
    cout<<dp[1][1][n][n];
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