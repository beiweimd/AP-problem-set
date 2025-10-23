// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p; 正推 线性求出1-n的逆元
// 先求出阶乘fac 快速幂算出fac[n]的阶乘 线性倒推fac[n-1-1]的逆元 invfac[i-1]=invfac[i]*i 
//单个数的逆元是 inv[i]=fact[i-1]*invfact[i]
#include <bits/stdc++.h>
typedef long long ll;
const ll mod=1e9+7;
const double pi=acos(-1);
const double eps=1e-10;
const int maxn=4e5;
const ll INF=1e17;
using namespace std;
int n,m;
double x[maxn],y[maxn];
vector<int >line[30][30];
int e[30][30];
int dp[maxn];
std::pair<double, double> solve(double x1, double y1, double x2, double y2) {
    double numerator_a = x1 * y2 - x2 * y1;
    double denominator_a = x1 * x2 * (x2 - x1);
    double a = numerator_a / denominator_a;
    double b = (y1 / x1) - a * x1;
    return {a, b};
}
void slove(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            e[i][j]=0;
        }
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            auto coefficient=solve(x[i],y[i],x[j],y[j]);
            double a=coefficient.first,b=coefficient.second;
            int pre=0;
            if(a>-1*eps) continue;
            for(int k=1;k<=n;k++){
                if (fabs(y[k] - (a*x[k]*x[k] + b*x[k])) <= eps) {
                    line[i][j].push_back(k-1);
                    pre=pre+(1<<(k-1));
                }
            }
            e[i-1][j-1]=pre;
        }
    }
    for(int i=1;i<(1<<n);i++) dp[i]=100;
    for(int  i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)) continue;
            dp[i|(1<<j)]=min(dp[i]+1,dp[i|(1<<j)]);
        }
        for(int l=0;l<n;l++){
            for(int r=0;r<n;r++){
                dp[i|e[l][r]]=min(dp[i|e[l][r]],dp[i]+1);
            }
        }
    }
    cout<<dp[(1<<n)-1]<<"\n";
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
		slove();
    }
    return (0-0);
}