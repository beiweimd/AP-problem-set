// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const int maxn=3e5;
const db pi=acos(-1);
const db eps=1e-10;
using namespace std;
int t,n,u,v,q,w,dep=1;
vector<pair<int,int> >e[maxn];
int val[20][maxn];
int f[20][maxn];
int deep[maxn];
void dfs (int x,int fa){
    deep[x]=dep;
    for(auto u:e[x]){
        int to=u.first;
        if(to!=fa) {
            f[0][to]=x;
            val[0][to]=u.second;
            dep++;
            dfs(to,x);
            dep--;
        }
    }
}
int query(int l,int r){
    int s=2e9;
   // cout<<deep[l]<<"*"<<deep[r]<<"*";
    if(deep[l]<deep[r] ) swap(l,r);
    int d=deep[l]-deep[r];
    for(int i=19;i>=0;i--){
        if((d&(1<<i))!=0){
            s=min(s,val[i][l] ) ;
            l=f[i][l];
        }
    }
    if(l==r) return s;
    for(int i=19;i>=0;i--){
        if(f[i][l]!=f[i][r]){
            s=min(s,min(val[i][l],val[i][r]));
            l=f[i][l];
            r=f[i][r];
        }
    }
    s=min(s,min(val[0][l],val[0][r]));
    return s;
}
void slove(){
    cin>>n>>q;
    for(int i=1;i<n;i++){
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dfs(1,-1);
    for(int j=1;j<=19;j++){
        for(int i=1;i<=n;i++){
            f[j][i]=f[j-1][f[j-1][i]];
            val[j][i]=min(val[j-1][i],val[j-1][f[j-1][i] ] )  ;
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;cin>>x>>y;
        cout<<query(x,y)<<"\n";
    }
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    t=1;
    while(t--){
		slove();
    }
    return 0;
}