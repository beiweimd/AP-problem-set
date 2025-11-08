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
const int maxn=3e3;
const ll INF=1e17;
using namespace std;
int n,m;
string s;
int dp[maxn][maxn];
map<char,int>add,del;
void slove(){
	cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        char op;int a,b;
        cin>>op>>a>>b;
        add[op]=a;
        del[op]=b;
    }
    for(int len=1;len<=m;len++){
        for(int i=0;i+len<m;i++){
            int j=i+len;
            dp[i][j]=min({
                add[s[i]]+dp[i+1][j],
                del[s[i]]+dp[i+1][j],
                add[s[j]]+dp[i][j-1],
                del[s[j]]+dp[i][j-1]
            });
            //cout<<i<<" "<<j<<endl;
            if(s[i]==s[j]) {
                //cout<<i<<" "<<j<<""; 
                dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
            }
        }
    }
    cout<<dp[0][m-1];
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