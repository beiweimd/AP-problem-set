#include<bits/stdc++.h>
using namespace std;
const int N=4e5+50,M=2e6+50;
#define ll long long
ll size[N],dp[N];
ll edge[M];
int ver[M],head[N],Next[M],tot,son[N];
void add(int x,int y,ll z){
	ver[++tot]=y,edge[tot]=z,Next[tot]=head[x],head[x]=tot;
	ver[++tot]=x,edge[tot]=z,Next[tot]=head[y],head[y]=tot;
}
int n,t;
void dfs1(int x,int fa){
	for(int i=head[x];i;i=Next[i]){
		int y=ver[i];
		if(y==fa)continue;
		dfs1(y,x);
		if(son[y]>1)size[x]+=min(edge[i],size[y]);
		else size[x]+=edge[i];
	}
}
void dfs2(int x,int fa){
	for(int i=head[x];i;i=Next[i]){
		int y=ver[i];
		if(y==fa)continue;
		if(son[x]==1)dp[y]=size[y]+edge[i];
		else if(son[y]>1)dp[y]=min(dp[x]-min(size[y],edge[i]),edge[i])+size[y];
		else dp[y]=min(dp[x]-edge[i],edge[i])+size[y];
		dfs2(y,x);
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		tot=0;
		for(int i=1;i<=n;i++)head[i]=0,size[i]=0,dp[i]=0,son[i]=0;
		for(int i=1;i<n;i++){
			int x,y;
			ll z;
			scanf("%d%d%lld",&x,&y,&z);
			son[x]++,son[y]++;
			add(x,y,z);
		}
		dfs1(1,0);
		dp[1]=size[1];
		dfs2(1,0);
		ll maxn=dp[1];
		for(int i=2;i<=n;i++){
			maxn=max(maxn,dp[i]);
		}
		printf("%lld\n",maxn);
	}
    return 0;
}
