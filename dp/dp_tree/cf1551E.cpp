// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e2;
using namespace std;
int t,n,k,u,v,deep[maxn];
ll ans;
vector<int >e[maxn];
int dp[maxn][maxn]; // 代表i这个子树 深度为j的点有多少个
void init(){
    for(int i=1;i<=n;i++){
        e[i].clear();
        for(int j=0;j<=n;j++) dp[i][j]=0;
    }
}
void dfs(int x,int fa){
    deep[x]=deep[fa]+1;
    dp[x][0]=1;
    int cnt=0;
    for(auto u:e[x]){
        if(u==fa) continue;
        dfs(u,x);
        cnt++;
        for(int i=1;i<=n;i++){
            dp[x][i]+=dp[u][i-1];
        }
    }
    if(cnt<k) return ;
    for(int i=0;i<=n;i++){
        cnt=0;
        ll sum=1;
        for(auto u:e[x]){
            if(u!=fa &&dp[u][i]!=0){
                cnt++;
                sum*=dp[u][i];
            }
        }
        if(cnt>=k) ans+=sum;
        ans%=mod;
    }
    return ;
}
void slove(){
    init();
    cin>>n>>k;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        e[u].push_back(v);
        swap(u,v);
        e[u].push_back(v);
    }
    ans=0ll;
    if(k==1){
        cout<<n<<"\n";return ;
    }
    if(k==2){
        cout<<n*(n-1)/2<<"\n";
        return ;
    }
    for(int i=1;i<=n;i++){
        dfs(i,0);
        //cout<<ans<<endl;
    }
    cout<<(ans+mod)%mod<<"\n";
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    //t=1;
    while(t--){
		slove();
    }
    return 0;
}