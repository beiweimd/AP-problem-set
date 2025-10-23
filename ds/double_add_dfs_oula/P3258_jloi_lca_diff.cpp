// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=4e5;
using namespace std;
int t,n,u,v;
int a[maxn];
int deep[maxn];
ll cnt[maxn];
int f[20][maxn];
vector<int >e[maxn];
ll tag[maxn];
void dfs(int x,int fa,int dep){
    deep[x]=dep;
    for(auto u:e[x]){
        if(u!=fa){
            f[0][u]=x; // 更新f
            dfs(u,x,dep+1);
        }
    }
    return ;
}
int find(int l,int r){
    if(deep[l]<deep[r]) swap(l,r);
    int d=deep[l]-deep[r];
    for(int j=18;j>=0;j--){
        if((d&(1<<j))!=0){
            l=f[j][l];
        }
    }
    //cout<<l<<" "<<r<<"***"<<endl;
    if(l==r) return l;
    for(int j=18;j>=0;j--){
        if(f[j][l]!=f[j][r]){
            l=f[j][l];
            r=f[j][r];
        }
    }
    return f[0][l];
}
void dfs2(int x,int fa){
    for(auto u:e[x]){
        if(u!=fa){
            dfs2(u,x);
            tag[x]+=tag[u];
        }
    }
    return ;
}
void slove(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,-1,1);
    for(int j=1;j<=18;j++){
        for(int i=1;i<=n;i++){
            f[j][i]=f[ j-1]     [  f[j-1][i]    ]      ;
        }
    }
    for(int i=1;i<n;i++){
        int x=a[i];
        int y=a[i+1];
        int z=find ( x, y ) ; // 找到x y的lca
        tag[x]++;
        tag[y]++;
        tag[z]-=2;
        cnt[z]++;
        cnt[y]--; // 打标记 对路径的两端进行差分 那么一个点被经过的次数就是所有字数的和
        // 或者说一个标记的贡献只对这个点的父亲作用
    }
    dfs2(1,-1);
    for(int i=1;i<=n;i++){
       cout<<tag[i]+cnt[i]<<"\n";
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