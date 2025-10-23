// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p;
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=200;
const ll INF=1e17;
using namespace std;
ll mod;
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
	ll p,q,a1,a2,k;
    cin>>p>>q>>a1>>a2>>k>>mod;
    n=2;
    if(k==1) {
        cout<<(a1%mod);return ;
    }
    if(k==2){
        cout<<(a2%mod);return ;
    }
    mat m={};
    m.a[1][1]=p%mod; m.a[1][2]=q%mod;m.a[2][1]=1ll;
    mat ans=quickmod(m,k-2);
    cout<<((ans.a[1][2]*a1%mod)+(ans.a[1][1]*a2%mod))%mod;
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