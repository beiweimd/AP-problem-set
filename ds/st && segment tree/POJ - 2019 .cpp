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
const int maxn=300;
const ll INF=1e17;
using namespace std;
int n,b,k;
vector<int> LG;  // 0..max(N_rows, N_cols) 的 floor(log2)
void build_logs(int L) {
    LG.assign(L + 1, 0);
    for (int i = 2; i <= L; i++) {
        LG[i] = LG[i >> 1] + 1;
    }
}
int dp[maxn][maxn][11][11][2]; // 代表i j左上角 纵向2的x次方 横向2的y次方的最大0 最小数值
void init(){
    int K = 10;
    for (int y = 1; y <= K; y++) {
        int hy = 1 << (y - 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j + (1 << y) - 1 <= n; j++) { 
                dp[i][j][0][y][0] = std::max(dp[i][j][0][y - 1][0], dp[i][j + hy][0][y - 1][0]);
                dp[i][j][0][y][1] = std::min(dp[i][j][0][y - 1][1], dp[i][j + hy][0][y - 1][1]);
            }
        }
    }
    for (int x = 1; x <= K; x++) {
        int hx = 1 << (x - 1);
        for (int y = 0; y <= K; y++) {
            for (int i = 1; i + (1 << x) - 1 <= n; i++) {    
                for (int j = 1; j + (1 << y) - 1 <= n; j++) { 
                    dp[i][j][x][y][0] = std::max(dp[i][j][x - 1][y][0], dp[i + hx][j][x - 1][y][0]);
                    dp[i][j][x][y][1] = std::min(dp[i][j][x - 1][y][1], dp[i + hx][j][x - 1][y][1]);
                }
            }
        }
    }

}
int query_max(int x1,int y1,int x2,int y2){
    int kx = 31 - __builtin_clz(x2 - x1 + 1);
    int ky = 31 - __builtin_clz(y2 - y1 + 1);
    int i2 = x2 - (1 << kx) + 1, j2 = y2 - (1 << ky) + 1;
    return max(
    max(dp[x1][y1][kx][ky][0], dp[i2][y1][kx][ky][0]),   
    max(dp[x1][j2][kx][ky][0], dp[i2][j2][kx][ky][0])
    );
}
int query_min(int x1,int y1,int x2,int y2){
    int kx = 31 - __builtin_clz(x2 - x1 + 1);
    int ky = 31 - __builtin_clz(y2 - y1 + 1);
    int i2 = x2 - (1 << kx) + 1, j2 = y2 - (1 << ky) + 1;
    return min(
    min(dp[x1][y1][kx][ky][1], dp[i2][y1][kx][ky][1]),   
    min(dp[x1][j2][kx][ky][1], dp[i2][j2][kx][ky][1])
    );
}
void slove(){
	cin>>n>>b>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>dp[i][j][0][0][0];
            dp[i][j][0][0][1]=dp[i][j][0][0][0];
        }
    }
    init();
    while(k--){
        int x,y;
        cin>>x>>y;
        cout<<query_max(x,y,x+b-1,y+b-1)-query_min(x,y,x+b-1,y+b-1)<<"\n";
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    slove();
    return (0-0);
}