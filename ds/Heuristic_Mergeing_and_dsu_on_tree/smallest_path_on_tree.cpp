// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// 使用离线的思想解决 很类似克鲁斯卡尔算法(最小生成树那个)
// 就是你按照这个边的大小进行排序 维护每个点集(联通块) 然后append一条边的时候 那么边的两边的点彼此最小的路径边权就是这条边
// 然后按照启发式合并的思想 俩个连通块(集合)合并就行了
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
using namespace std;
int t,n,q,u,v,w;
vector<array<int,3> > e;
vector<pair<int,int> > query[maxn];//代表询问的id和点
int f[maxn],ans[maxn],belong[maxn];
vector<int >point[maxn];//合并的集合 这里是点集
int find(int x){
    if(f[x]==x) return x;
    else {
        f[x]=find(f[x]);
        return f[x];
    }
}
void slove(){
	cin>>n>>q;
    for(int i=1;i<n;i++){
        cin>>u>>v>>w; 
        e.push_back({w,u,v});
    }
    for(int i=1;i<=n;i++){
        f[i]=i;
        belong[i]=i;
        point[i].push_back(i);
    }
    sort(e.begin(),e.end());
    reverse(e.begin(),e.end());// 处理边
    for(int i=1;i<=q;i++){
        cin>>u>>v;
        query[u].push_back({i,v});
        query[v].push_back({i,u});//处理这个询问
    }
    for(int i=0;i<n-1;i++){
        u=find(e[i][1]),v=find(e[i][2]); // 这里要注意 一定是两个点集的老大
        if(point[u].size()>point[v].size()) swap(u,v);
        for(auto [id,to]:query[u]){
            //cout<<e[i][0]<<" "<<to<<" "<<v<<endl; 
            if(ans[id]!=0) continue;
            if(belong[to]==v){
                ans[id]=e[i][0];
            }
            else query[v].push_back({id,to});
        }
        for(auto x:point[u]){
            point[v].push_back(x);
            belong[x]=v;
        }
        point[u].clear();//启发式合并的东西
        query[u].clear();
        f[u]=v;
    }
    for(int i=1;i<=q;i++){
        cout<<ans[i]<<"\n";
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