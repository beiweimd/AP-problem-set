// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=5e3+100;
using namespace std;
int t,n,m;
ll f[maxn][maxn]; // 代表顶点i到顶点j组成的多边形的直径
struct point{
    ll x,y;
    point operator-(const point &a){
        return point{x-a.x,y-a.y};
    }
};
point p[maxn];
ll sq(ll x){return x*x;}
ll  dis(point a,point b){
    return sq(a.x-b.x)+sq(a.y-b.y);
}
int cross(point a,point b){
    return a.x*b.y-a.y*b.x;
}
void slove(){
    ll ans=9e18;
    cin>>n;
    for(int i=0;i<n;i++){
        ll tx,ty;cin>>tx>>ty;
        p[i]=(point{tx,ty});
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++) f[i][j]=0;
    }
    for(int len=2;len<=n;len++ ){ // len是长度 
        for(int i=0;i<n;i++){// i是起点 k是终点
            int k=(i+len-1)%n;
            f[i][k]=max(max(  dis(p[i],p[k]),f[(i+1)%n][k]),f[i][ (k+n-1)%n] );
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int pre=(i-1+n)%n;
            int nex=(i+1)%n;
            if(i==j) continue;
            if( cross(p[pre]-p[i],p[j]-p[i])==0 ) continue;
            if( cross(p[nex]-p[i],p[j]-p[i])==0 ) continue;
            ans=min(ans,f[i][j]+f[j][i]);
        }
    }
    cout<<ans<<"\n";
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    //t=1;
    while(t--){
		slove();
    }
    return 0;
}