// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p;
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e3;
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
	cin>>k;
    mat m={};
    for(int i=1;i<=8;i++){
        if(i==5) {m.a[i][i]=0;continue;}
        else {m.a[i][i+1]=m.a[i+1][i]=1;}
    }
    m.a[1][8]=m.a[8][1]=1;
    m.a[6][5]=1;
    m.a[5][6]=m.a[5][4]=0;
    n=8; 
    mat ans=quickmod(m,k);
    // for(int i=1;i<=n;i++){
    //     //q+=ans.a[i][5];
    //     for(int j=1;j<=n;j++){
    //         cout<<ans.a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<ans.a[1][5]%mod;
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