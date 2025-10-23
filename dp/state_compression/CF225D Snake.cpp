// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p; 正推 线性求出1-n的逆元
// 先求出阶乘fac 快速幂算出fac[n]的阶乘 线性倒推fac[n-1-1]的逆元 invfac[i-1]=invfac[i]*i 
//单个数的逆元是 inv[i]=fact[i-1]*invfact[i]
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
int n,m,ex,ey,k,ans=1000;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char mp[20][20];
//int vis[20][20];
//bool collision[20][20]; //处理蛇的碰撞
bool dp[17][17][(2<<16)+10];
// 2^16=131072 1.5e5*400=6e7
int S(vector<pair<int ,int> >pos){ // 得到蛇身状态
    int state=0;
    for(int i=1;i<k;i++){
        auto  lef=pos[i-1];
        auto  rig=pos[i];
        int cnt=0;
        // 对应的话 应该是 0 向右走  1是向左走  2是向下走 3 是向上走
        //cout<<lef.first<<" "<<lef.second<<endl;
        if(lef.first==rig.first){
            if(lef.second+1==rig.second) cnt=0;
            else cnt=1;
        }
        else{
            if(lef.first+1==rig.first) cnt=2;
            else cnt=3;
        }
        state=state*4+cnt;
    }
    return state;
}
// void dfs(int x,int y,vector<pair<int ,int> >pos,int step){
//     //cout<<x<<" "<<y<<" "<<step<<endl;
//     int state=S(pos);
//     long long key = packKey(x, y, state);
//     auto it = memo.find(key);
//     if (it != memo.end() && it->second <= step) {
//         return;  // 这个状态更优/同优来过，没必要继续
//     }
//     memo[key] = step;
//     if(x==ex && y==ey){
//         ans=min(step,ans);
//         return ;
//     }
//     for(int i=0;i<4;i++){
//         int tx=x+dx[i];
//         int ty=y+dy[i];
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 collision[i][j]=0;
//             }
//         }
//         for(int i=1;i<k-1;i++){
//             collision[pos[i].first][pos[i].second]=1;
//         }
//         if(mp[tx][ty]=='#' or collision[tx][ty] or ty<=0 or tx<=0 or tx>n or ty>m or vis[tx][ty]  ) continue;
//         vector<pair<int ,int> >tpos;
//         tpos.push_back({tx,ty});
//         //cout<<tx<<" "<<ty<<" "<<step<<endl;
//         for(int j=0;j<k-1;j++){
//             tpos.push_back(pos[j]);
//         }
//         vis[tx][ty]=1;
//         dfs(tx,ty,tpos,step+1);
//         vis[tx][ty]=0;
//     }
//     return ;
// }
void bfs(vector<pair<int ,int> >tp){
    queue < vector<pair<int ,int> > > q;
    q.push(tp);
    queue < int > tim;
    tim.push(1);
    while (!q.empty()){
        auto pos=q.front();
        q.pop();
        int time=tim.front();
        tim.pop();
        int x=pos[0].first;
        int y=pos[0].second;
        if(x==ex && y==ey) {ans=min(ans,time);return ;}
        vector<pair<int ,int> >tpos;
        tpos.push_back({x,y});
        for(int j=0;j<k-1;j++){
            tpos.push_back(pos[j]);
        }
        for(int i=0;i<4;i++){
            int tx=x+dx[i];
            int ty=y+dy[i];
            if(mp[tx][ty]=='#'  or ty<=0 or tx<=0 or tx>n or ty>m   ) continue;
            int flag=0;
            for(int j=1;j<k-1;j++){
                if(tx==pos[j].first && ty==pos[j].second) flag=1;
            }
            if(flag) continue;
            tpos[0]={tx,ty};
            int state=S(tpos);
            if(dp[tx][ty][state] ) continue;
            dp[tx][ty][S(tpos)]=true;
            tim.push(time+1);
            q.push(tpos);
        }
    }   
    return ;
}
void slove(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            if(mp[i][j]=='@') {ex=i;ey=j;}
            else if(mp[i][j]=='#') continue;
            else if(mp[i][j]=='.') continue;
            else { k=max(k,(mp[i][j]-'0'));}
        }
    }
    vector<pair<int,int>>t;
    for(int ord=1;ord<=k;ord++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if((mp[i][j]-'0')==ord) t.push_back({i,j});
            }
        }
    }
    //dfs(t[0].first,t[0].second,t,1); dfs 超时了
    bfs(t);
    if(ans==1000 )cout<<-1;
    else cout<<ans-1;
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    slove();
    return (0-0);
}