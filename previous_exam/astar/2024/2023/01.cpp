// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p;
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=5e4;
const ll INF=1e17;
const int inf=2e9;
using namespace std;
int x,y,te,fe,s,t,f,n,m,ans=2e9;
vector<int >e[maxn];
struct node
{
    int pos,cnt;
};
int p[4][maxn];
void slove(){
    cin>>te>>fe>>s>>t>>f>>n>>m;
    for(int i=0;i<=2;i++){
        for(int j=0;j<=40001;j++){
            p[i][j]=inf;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    queue<node > q[3];
    q[0].push(node{t,0});
    q[1].push(node{f,0});
    array<int,3>dis;
    p[0][t]=0;
    p[1][f]=0;
    dis[0]=te;dis[1]=fe;dis[2]=te+fe-s;
    while(1){
        int lena=q[0].size();
        int lenb=q[1].size();
        int lenc=q[2].size();
        if(lena+lenb+lenc==0) break;
        for(int i=0;i<=2;i++){
            if(q[i].size()==0) continue;
            auto now=q[i].front();
            if(i==0) {
                if((p[1][now.pos]!=inf)){
                    p[2][now.pos]=min(p[2][now.pos],now.cnt+p[1][now.pos]);
                    q[2].push(node{now.pos,now.cnt+p[1][now.pos]} );
                }
            } 
            if(i==1){
                if((p[0][now.pos]!=inf)){
                    p[2][now.pos]=min(p[2][now.pos],now.cnt+p[0][now.pos]);
                    q[2].push(node{now.pos,now.cnt+p[0][now.pos]} );
                }
            }
            q[i].pop();
            for(auto to:e[now.pos]){
                if(p[i][to]>p[i][now.pos]+dis[i]){
                    q[i].push(node{to,now.cnt+dis[i]});
                    p[i][to]=p[i][now.pos]+dis[i];
                }
            }
        }
    }
    if(p[2][n]==2e9 or (p[0][n]==2e9 or p[1][n]==2e9) ) cout<<-1;
    else cout<<min(p[2][n],p[0][n]+p[1][n]);
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    slove();
    return (0-0);
}