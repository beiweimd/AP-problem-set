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
int n,m,ans,sum;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
vector< vector< char > >a;
vector< vector< int  > >clo;
int pos;
bool in_range(int x,int y){
    if(x<=0 or x>y) return false;
    else return true;
}
void check(int x,int y){
    queue<pair<int,int > > q;
    q.push({x,y});
    vector<pair<int,int > >path;
    vector<pair<int,int>> cells;          // 绝对坐标
    cells.push_back({x,y});
    clo[x][y]=pos;
    int shang=x,xia=x;
    int zuo=y,you=y;
    while(!q.empty()){
        auto k=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=dx[i]+k.first;
            int ty=dy[i]+k.second;
            if( in_range(tx,n) && in_range(ty,m)&&!clo[tx][ty]  &&a[tx][ty]=='.'){
                clo[tx][ty]=pos; // pos是指的是第几个联通快
                q.push({tx,ty});
                sum++; // 联通快的个数
                cells.push_back({tx , ty });
                shang=min(tx,shang);
                xia=max(tx,xia);
                zuo=min(zuo,ty);
                you=max(you,ty);
            }
        }
    }
    path.reserve(sum);
    for (auto [tx,ty] : cells) path.push_back({tx - shang, ty - zuo});
    int diffx=xia-shang;
    int diffy=you-zuo;
    for(int i=1;i+diffx<=n;i++){
        for(int j=1;j+diffy<=m;j++){
            if((i==shang && j==zuo)) continue;
            for(auto u:path){
                if(!in_range(i+u.first,n) or !in_range(j+u.second,m)) break;
                if( a[i+u.first][j+u.second]=='O') break;
                if(u==path[sum-1]) return ;
            }
        }
    }
    ans+=sum;
    return ;
}
void slove(){
    ans=0;
    cin>>n>>m;
    pos=0;
    a.assign(n+1, vector<char>(m+1));
    clo.assign(n+1, vector<int>(m+1, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='.' && clo[i][j]==0){
                sum=1; // 统计这个联通快有多少个
                pos++; // 代表是第几个联通快
                check(i,j);
            }
        }
    }
    cout<<ans<<"\n";
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
		slove();
    }
    return (0-0);
}
// // ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// // inv[i]=(p-p/i)*inv[p%i]%p; 正推 线性求出1-n的逆元
// // 先求出阶乘fac 快速幂算出fac[n]的阶乘 线性倒推fac[n-1-1]的逆元 invfac[i-1]=invfac[i]*i 
// //单个数的逆元是 inv[i]=fact[i-1]*invfact[i]
// #include <bits/stdc++.h>
// typedef long long ll;
// typedef long double db;
// const ll mod=1e9+7;
// const db pi=acos(-1);
// const db eps=1e-10;
// const int maxn=3e5;
// const ll INF=1e17;
// using namespace std;
// int n,m,ans,sum;
// int dx[4]={0,0,-1,1};
// int dy[4]={1,-1,0,0};
// vector< vector< char > >a;
// bool in_range(int x,int y){
//     if(x<=0 or x>y) return false;
//     else return true;
// }
// void check(int x,int y){
//     queue<pair<int,int > > q;
//     vector<vector<bool>>vis(n+1,vector<bool>(m+1));
//     vector<vector<bool>>vis2(n+1,vector<bool>(m+1));
//     q.push({x,y});
//     vis[x][y]=1;
//     int flag=sum-1;
//     while(!q.empty()){
//         auto k=q.front();
//         q.pop();
//         for(int i=0;i<4;i++){
//             int tx=dx[i]+k.first;
//             int ty=dy[i]+k.second;
//             if( in_range(tx,n) && in_range(ty,m)&&!vis[tx][ty]  &&a[tx][ty]=='.'){
//                 vis[tx][ty]=true;
//                 q.push({tx,ty});
//             }
//         }
//         int difx=k.first-x;
//         int dify=k.second-y;
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(i==x && j==y) continue;
//                 if(a[i][j]=='O') continue;
//                 int tx=i+difx;
//                 int ty=j+dify;
//                 if(vis2[i][j]) continue;
//                 if( !in_range(tx,n) or !in_range(ty,m) ) {
//                     flag--;
//                     vis2[i][j]=1;
//                     continue;
//                 }
//                 if(a[tx][ty]=='O') {flag--;vis2[i][j]=1;}
//             }
//         }
//     }
//     if(!flag) ans++;
// }
// void slove(){
//     ans=0;sum=0;
//     cin>>n>>m;
//     a.resize(n+1);
//     for(int i=1;i<=n;i++){
//         a[i].resize(m+1);
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             cin>>a[i][j];
//             if(a[i][j]=='.') sum++;
//         }
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(a[i][j]=='.'){
//                 check(i,j);
//             }
//         }
//     }
//     cout<<ans<<"\n";
// 	return;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int t=1;
//     cin>>t;
//     while(t--){
// 		slove();
//     }
//     return (0-0);
// }