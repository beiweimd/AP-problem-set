// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
int ans;
int n,m,l,r,a[1100][1100],dis[1100][1100][3];
struct node{
    int x,y,t,odd;
};
int dx[8]={0,0,-1,1,-1,-1,1,1};
int dy[8]={1,-1,0,0,-1,1,-1,1};
void slove(){
    cin>>n>>m>>l>>r;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) a[i][j]=0,dis[i][j][0]=dis[i][j][1]=1e8;
    }
    dis[1][1][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char s;cin>>s;
            if(s=='1') a[i][j]=1;
        }
    }
    queue<node>q;
    q.push(node{1,1,0,0});
    while(!q.empty()){
        auto k=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int tx=k.x+dx[i];
            int ty=k.y+dy[i];
            if(ty>0 && ty<=m && tx>0 && tx<=n && a[tx][ty]==1 && dis[tx][ty][(k.odd+1)%2]==1e8){
                dis[tx][ty][(k.odd+1)%2]=k.t+1;
                q.push(node{tx,ty,k.t+1,(k.odd+1)%2});
            }
        }
    }
    if(l==r){
        if(l%2==0){ // 能走的是个偶数 此时你每轮走的有效步数就是 2 4 6。。。l 到重点肯定是偶数步
            if(dis[n][m][0]==1e8) ans=-1;
            else {ans=dis[n][m][0]/l; if ( dis[n][m][0]%l!=0 ) ans++;} // 直接向上取整即可 
        }
        else{ // 只能走一个固定的奇数 那么假设走了x次 x为偶数的时候 等价于单次2*l的偶数情况 x为奇数的时候 那么就是走了 x次1 3 5 .。。n
            ans=-1;
            if(dis[n][m][0]!=1e8){ // 我们先计算走偶数和奇数步到终点需要几轮 满足就记录答案
                ans=dis[n][m][0]/(l*2); if ( dis[n][m][0]%(l*2)!=0 ) ans++;
                ans*=2;
            }
            if(dis[n][m][1]!=1e8){
                if(ans==-1) {ans=dis[n][m][1]/l+(dis[n][m][1]%l==0?0:1) ;if(ans%2==0) ans++;}
                else{
                    int even=dis[n][m][1]/l+(dis[n][m][1]%l==0?0:1);
                    if(even%2==0) even++; // 这里是说 奇数的时候 如果算出来的轮数是偶数 则需要多加一轮 比如 d=11 l=r=3
                    ans=min(ans, even     );
                }
            }
        }
    }
    else{ // l！=r的时候 答案是d/r 向上取整 d为到终点的最短距离 (r至少为2)
        //对于那些正好d/r==0 的 我们显然只需要d/r伦
        // 对于那些d/r！=0的  设 num=d%r 因为每次减两步是没有影响的 所以在最后一轮总可以凑出num 
        int d=min(dis[n][m][0],dis[n][m][1]);
        if(d==1e8) ans=-1;
        else ans=d/r+(d%r==0?0:1); 
    }
    //cout<<dis[n][m][0]<<" "<<dis[n][m][1]<<" "<<endl;
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