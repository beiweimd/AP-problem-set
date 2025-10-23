// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const int inf=1e7;
const db eps=1e-10;
const int maxn=2e5;
using namespace std;
int n,m,V,T;
struct node{
    int id;
    int cab;
    int used;
};
struct Compare{
    bool operator()(const node&a,const node&b){
        if(a.used!=b.used) return a.used>b.used;
        else return a.cab<b.cab;
    }
};
int dis[maxn];
int weight[maxn];
vector<pair<int ,int > >e[maxn];
void dij(){
    priority_queue< node, vector<node>, Compare> q ; 
    q.push(node{T,V,1});
    for(int i=1;i<=n;i++){
        dis[i]=inf;
        //weight[i]=0;
    }
    dis[T]=1; weight[T]=V;
    while(!q.empty()){
        node k=q.top();
        q.pop();
        if(k.used>dis[k.id] or (k.used==dis[k.id] &&weight[k.id]>k.cab )) continue;
        for(const auto&[to,val]:e[k.id]){
            int d=dis[k.id],v=k.cab;
            if(val<=v){
                v-=val;
            }
            else {
                d++;
                v=V-val;
            }
            if (dis[to] > d) {
                dis[to] = d;
                weight[to] = v;
                q.push(node{to, v, d});
            } else if (dis[to] == d && weight[to] < v) {
                weight[to] = v;
                q.push(node{to, v, d});
            }
        }
    }
    return ;
}
void slove(){
    cin>>n>>m>>V>>T; 
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back(make_pair(v,w));
        swap(u,v);
        e[u].push_back(make_pair(v,w));
    } 
    for(int i=1;i<=n;i++){
        sort(e[i].begin(),e[i].end(),[](const pair<int,int>&a,const pair<int,int >&b){
            return a.second<b.second;
        }
        );
    }
    dij();
    for(int i=1;i<=n;i++){
        if(dis[i]==inf) cout<<-1<<" ";
        else cout<<dis[i]<<" ";
    }
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    slove();
    return 0;
}