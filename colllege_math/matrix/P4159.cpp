// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p;
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=2009;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=110;
const ll INF=1e17;
using namespace std;
int n;
struct  mat{
    ll a[maxn][maxn]; 
};
mat operator*(const mat&A,const mat&B){
    mat z={};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                z.a[i][j]+=A.a[i][k]*B.a[k][j];
                z.a[i][j]%=mod;
            }
        }
    }
    return z;
}
mat quickmod(mat x,ll y){
    mat s={};
    for(int i=1;i<=n;i++) s.a[i][i]=1;
    while(y){
        if(y&1) s=s*x;
        x=x*x;
        y>>=1;
    }
    return s;
}
void slove(){
    ll k;
	cin>>n>>k;
    mat m={};
    for(int i=1;i<=n;i++){
        for(int j=1;j<9;j++){
            m.a[9*i-9+j][9*i-8+j]=1; // 把每个点拆成9个点 如果u到v有边 直接练到对应的点上的一些边
        }
    }
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        for(int j=0;j<n;j++){
            int w=s[j]-'0';
            if(w==0) continue;
            int u=9*i,v=9*j+(10-w);
            m.a[u][v]=1;
        }
    }
    n*=9;
    mat ans=quickmod(m,k);
    cout<<ans.a[9][n];
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