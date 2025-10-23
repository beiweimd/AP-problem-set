// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e2;
const ll INF=1e17;
using namespace std;
int tag[maxn],ans,n;
int dp[maxn][maxn];
void slove(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tag[i];
    }
    for(int i=n+1;i<=2*n;i++){
        tag[i]=tag[i-n];
    }
    tag[2*n+1]=tag[1];
    for(int len=1;len<=n;len++){
        for(int i=1;i+len<=2*n;i++){
            int j=i+len;
            for(int k=i;k<j;k++){
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+tag[k+1]*tag[i]*tag[j+1]);
                // i是头 j是尾 k是合并完的的那个 所以头的尾节点 是k后面一个 也就是k+1 同理 尾部尾结点是j+1 
            }
        }
    }
    for(int i=1;i<=n;i++) ans=max(ans,dp[i][i+n-1]);
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