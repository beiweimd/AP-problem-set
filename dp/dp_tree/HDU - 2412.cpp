#include <bits/stdc++.h>
const int maxn=2e3+110;
using namespace std;
int n,top,ans;
string s,s1,s2;
map<string,int>mp;
vector<int >e[maxn];
int f[maxn][2];
// 1 代表选自己 0代表不选自己 的子树的最大数量
bool g[maxn][2];
// 代表这个点及其子树 选或不选的最大选择方法是否唯一
void dfs(int x    ,int fa  ){
    f[x][1]=1;
    g[x][0]=g[x][1]=1;
    for(auto u:e[x]){
        if(u==fa ) continue;
        dfs(u,x);
        f[x][0]+=max(f[u][0],f[u][1]);
        if(f[u][0]==f[u][1]) g[x][0]=0;
        f[x][1]+=f[u][0];
        if(g[u][0]==0) g[x][1]=0;
    }
    return ;
}
void slove(){
    for(int i=1;i<=n;i++) f[i][0]=f[i][1]=0;
    for(int i=1;i<=n;i++) e[i].clear();
    ans=0;
    top=0;
    mp.clear();
    cin>>s;
    top++;
    mp[s]=top;
    for(int i=1;i<n;i++){
        cin>>s1>>s2;
        if(!mp[s1]) {top++;mp[s1]=top;}
        if(!mp[s2]) {top++;mp[s2]=top;}
        e[mp[s1]].push_back(mp[s2]);
        e[mp[s2]].push_back(mp[s1]);
    }
    dfs(1,0);
    bool flag=0;
    if(f[1][0]>f[1][1]){
        ans=f[1][0];
        flag=g[1][0];
    } else if(f[1][0]<f[1][1]){
        ans=f[1][1];
        flag=g[1][1];
    }
    else ans=f[1][1];
    cout<<ans<<" ";
    cout<<(flag?"Yes":"No");
    cout<<"\n";
}
int main() {
	while(cin>>n){
	    if(n==0) break;
	    slove();
	}
	return 0;
}
