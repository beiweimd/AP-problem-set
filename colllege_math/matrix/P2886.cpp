// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p;
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=110;
const ll INF=1e17;
using namespace std;
ll n;
struct  mat{
    ll a[maxn][maxn]; 
};
mat operator*(const mat&A,const mat&B){
    mat z={};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                //if(A.a[i][k]+B.a[k][j]==0) continue;
                if(z.a[i][j]==0) z.a[i][j]=A.a[i][k]+B.a[k][j];
                else z.a[i][j]=min(z.a[i][j],A.a[i][k]+B.a[k][j]);
            }
        }
    }
    return z;
}
mat quickmod(mat x,ll y){
    mat s=x;
    y--;
    while(y){
        if(y&1) s=s*x;
        x=x*x;
        y>>=1;
    }
    return s;
}
map<int,int>mp;
void slove(){
    ll k;
    int t,s,e,top=1;
    cin>>k>>t>>s>>e;
    mat m={};
    for(int i=1;i<=101;i++){
        for(int j=1;j<=101;j++){
            m.a[i][j]=1e9;
        }
    }
    for(int i=1;i<=t;i++){
        int u,v;ll w;
        cin>>w>>u>>v;
        //cout<<w<<" "<<u<<" "<<v<<endl;
        if(mp[u]==0) {mp[u]=top;top++;}
        swap(u,v);
        if(mp[u]==0) {mp[u]=top;top++;}
        int l=mp[u],r=mp[v];
        if(m.a[l][r]==0) m.a[l][r]=m.a[r][l]=w;
        else
        {
            m.a[r][l]=min(m.a[r][l],w);
            m.a[l][r]=min(m.a[l][r],w);
        }
    }
    n=top-1;
    for(int i=1;i<top;i++){
        for(int j=1;j<top;j++){
            //cout<<m.a[i][j]<<" ";
        }
        //cout<<endl;
    }
    mat ans=quickmod(m,k);
    cout<<ans.a[mp[s]][mp[e]];//<<" "<<ans.a[mp[e]][mp[s]];
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