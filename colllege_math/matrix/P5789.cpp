// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p;
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=2017;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=200;
const ll INF=1e17;
using namespace std;
int n;ll k;
struct  mat{
    ll a[maxn][maxn]; 
};
mat operator*(const mat&A,const mat&B){
    mat z={};
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
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
    int t,u,v;
	cin>>n>>t;
    mat m;
    for(int i=1;i<=t;i++){
        cin>>u>>v;
        m.a[u][v]=m.a[v][u]=1;
    }
    for(int i=0;i<=n;i++) m.a[i][i]=m.a[i][0]=1;
    cin>>k;
    ll q=0ll;
    mat ans=quickmod(m,k);
    for(int i=0;i<=n;i++){
        q+=ans.a[1][i];
        q%=mod;
    }
    cout<<q;
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