// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=5e5;
const int maxm=2e3;
using namespace std;
int t,n,q,m,op,x,y;
ll a[maxn];
ll sum[maxm][maxm];
vector<int >large,p[maxn];
void slove(){
	cin>>n>>q;
    m=(int)sqrt(n)+1;
    //m=500;
    for(int i=1;i<=q;i++){
        cin>>op>>x;
        if(op==1){
            cin>>y;
            if(p[x].size()<=m){
                for(int j=0;j<p[x].size();j++){
                    sum[p[x].size()][j]-=p[x][j];
                }
            }
            p[x].push_back(y);
            if(p[x].size()<=m){
                for(int j=0;j<p[x].size();j++){
                    sum[p[x].size()][j]+=p[x][j];
                }               
            }
            else{
                if(p[x].size()==m+1) large.push_back(x);
            }
        }
        else{
            ll ans=0;
            for(int j=1;j<=m;j++) ans+=sum[j][x%j];
            for(auto u:large){
                ans+=p[u][x%(int)p[u].size()];
            }
            cout<<ans<<"\n";
        }
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