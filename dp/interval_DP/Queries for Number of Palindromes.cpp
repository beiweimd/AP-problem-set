// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p;
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=5e3+100;
const ll INF=1e17;
using namespace std;
int q,l,r,dp[maxn][maxn]; // dp i j 代表[i,j]这个子串是不是回文串
int s1[maxn][maxn];
int query(int x1 ,int y1 ,int x2 ,int y2){
    return s1[x2][y2]+s1[x1-1][y1-1]-s1[x2][y1-1]-s1[x1-1][y2];
}
void slove(){
    string s;cin>>s;
    int n=s.length();
    s=" "+s;
    cin>>q;
    for(int i=1;i<=n;i++) dp[i][i]=1;
    for(int len=1;len<=n;len++){
        for(int i=1;i+len<=n;i++){
            int j=i+len;
            if(j-i==1) {
                dp[i][j]=(s[i]==s[j]?1:0);
            }
            else {
                if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            s1[i][j]=s1[i-1][j]+s1[i][j-1]-s1[i-1][j-1]+dp[i][j];
        }
    }
    while(q--){
        cin>>l>>r;cout<<query(l,l,r,r)<<"\n";
    }
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