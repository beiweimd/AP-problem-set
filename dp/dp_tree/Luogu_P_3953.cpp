// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db eps=1e-10;
const int maxn=2e5;
using namespace std;
int t,n,m,u,v,vis[maxn],flag;
ll p,k,w,dis[maxn],sum,cnt[maxn];
ll dp[maxn][60]; // 代表1到u 距离为du+j的方案数
bool path[maxn][60]; // 代表在DP的时候 判断有没有0环 有的话 那么相同的状态会被访问到若干次
vector<pair<int,ll> >e[maxn];
vector<pair<int,ll> > e2[maxn];
void init(){
	flag=0;
	sum=0;
    for(int i=1;i<=n;i++){
        e[i].clear();
		e2[i].clear();
        vis[i]=0;
		cnt[i]=0;
		for(int j=0;j<=k;j++){
			dp[i][j]=0;
			path[i][j]=false;
		}
    }
	dp[1][0]=1;
    return ;
}
struct Compare{
    bool operator()(const pair<ll,int >&a,const pair<ll,int>&b){
        return a.first>b.first;
    }
};
void dij(){
    memset(dis, 0x3f, sizeof(dis));
    dis[1]=0;
    cnt[1]=1;
    priority_queue<pair<ll , int >,vector<pair<ll,int> >,Compare >q ;  // 第一个是距离 第二个是点
    q.push(make_pair( 0,1 ) );
	while(!q.empty()){
		auto k = q.top();
		q.pop();
		int v = k.second;
		if(vis[v]) continue;
		vis[v] = 1;
		for(const auto &[u,val] : e[v]){                
			if(dis[u] > dis[v] + val){   // 更短的路，直接更新并重置路径数
				dis[u] = dis[v] + val;
				cnt[u] = cnt[v];
				q.push(make_pair(dis[u], u));
			}
			else if(dis[u] == dis[v] + val){  // 一样长的路，累加
				cnt[u] = (cnt[u] + cnt[v]) % p;
			}
		}
	}
    return ;
}
ll DP(int x,int d){
	//cout<<x<<" "<<d<<endl;
	if(d<0 or flag) return 0;
	if(path[x][d]){
		//cout<<x<<" "<<d<<endl;
		flag=1;
		return 0;
	}
	if(dp[x][d]) return dp[x][d];
	path[x][d]=true;
	//cout<<x<<" "<<d<<endl;
	for(const  auto &[u,val]:e2[x]){
		dp[x][d]+=DP(u,dis[x]-dis[u]+d-val);
		dp[x][d]%=p;
	}
	path[x][d]=0;
	return dp[x][d];
}
void slove(){
    init();
    cin>>n>>m>>k>>p;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        e[u].push_back(make_pair(v,w));
		e2[v].push_back(make_pair(u,w));
    }
    dij();
	if(k==0){
		DP(n,1);
		if(flag) {cout<<-1<<"\n";return;}
		cout<<cnt[n]%p<<"\n";return ;
	}
	if(!vis[n]) {cout<<0<<"\n";return;}
	for(int i=0;i<=k;i++) DP(n,i);
	for(int i=0;i<=k;i++) sum+=dp[n][i],sum%=p;
	if(flag) {cout<<-1<<"\n";return;}
    //if(k==0)cout<<cnt[n]%p<<"\n";
    else cout<<sum%p<<"\n";
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        slove();
    }
    return 0;
}