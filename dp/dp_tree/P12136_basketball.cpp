#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+100;
typedef long long ll;
int n,u,v,ans,mad;
int w[maxn];
int deep[maxn];
vector<int >e[maxn];
int f[maxn];
int dp[maxn][maxn];
void dfs(int x ,int fa){
    f[x]=fa;
	deep[x]=deep[f[x]]+1;
	for(auto u:e[x]){
		if(u!=fa){
			dfs(u,x);
		}
	}
	return ;
} 
void dfs2(int x,int fa){
    if(e[x].size()==1 && e[x][0]==fa){
        dp[x][w[x]]=1;
        return ;
    }
    for(auto u:e[x]){
        if(u==fa) continue;
        dfs2(u,x);
    }
    for(auto u:e[x]){
        if(u==fa) continue;
        for(int i=min(w[1],w[x]);i>=0;i--){
            if(dp[x][i]==0) continue;
            for(int j=1;j+i<=min(w[1],w[x]);j++){
                if(dp[u][j]==1 ){
                    dp[x][i+j]=1;
                }
            }
        }
        for(int i=1;i<=min(w[x],w[1]);i++){
            if(dp[u][i]==1) dp[x][i]=1;
        }
    }
    return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<n;i++){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
		dp[i][0]=1;
	}
	dfs(1,-1);
    dfs2(1,-1);
	for(int i=w[1];i>=0;i--){
		if(dp[1][i]==1) {cout<<i;break;}
	}
	return 0;
}
/*
9
9 7 3 7 1 6 2 2 7
1 2
1 3
2 4
2 5
2 6
6 7
6 8
6 9
*/