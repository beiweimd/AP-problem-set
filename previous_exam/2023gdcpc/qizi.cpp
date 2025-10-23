#include <iostream>
#include<cmath>
#include<vector>
#include<map>
#include<iomanip>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const int maxn=5e6;
const db pi=acos(-1);
const db eps=1e-12;
using namespace std;
int a[110][110];
int t,n,m,k,ans;
int dx[4]={0,0,2,-2};
int dy[4]={2,-2,0,0};
void dfs(int num){
    ans=min(ans,num);
    // if(num==1){
    //     return ;
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==1){
                for(int k=0;k<4;k++){
                    int tx=i+dx[k];
                    int ty=j+dy[k];
                    if( tx>=1 && tx<=n && ty>=1 && ty<=m && a[tx][ty]==0){
                        if(a[ (i+tx)/2 ][(j+ty)/2]==1){
                            a[i][j]=0;
                            a[tx][ty]=1;
                            a[ (i+tx)/2 ][(j+ty)/2]=0;
                            dfs(num-1);
                            a[i][j]=1;
                            a[tx][ty]=0;
                            a[ (i+tx)/2 ][(j+ty)/2]=1;
                        }
                    }
                }
            }
        }
    }
    return ;
}
void slove(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=0;
        }
    }
	cin>>n>>m>>k;
    ans=k;
    for(int i=1;i<=k;i++){
        int x,y;cin>>x>>y;
        a[x][y]=1;
    }
    dfs(k);
    if(k==1) {
        cout<<1<<"\n";return ;
    }
    cout<<ans<<"\n";
	return ;
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