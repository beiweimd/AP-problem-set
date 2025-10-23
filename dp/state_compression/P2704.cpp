// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p;
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
int n,m,a[200][20],ans;
vector<int >e[105];
bool check(int x){
    if(  (x&(x<<1))or (x&(x<<2) ) or (x&(x>>1)) or (x&(x>>2))) return true;
    return false;
}
int countOnes(int n) {
    int count = 0;
    while (n) {
        n &= n - 1;  // 消去最右边的一个1
        count++;
    }
    return count;
}
int w[110][2000];
int dp[110][110][110]; //代表第i行  i行放置了j i-1行放置了k的  最大放置跑车数量
void slove(){
	cin>>n>>m;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=m;j++){
            char s;cin>>s;
            if(s=='P') a[i][j]=1;
            cnt=cnt*2+a[i][j];
        }
        int sum=0;
        for(int j=0;j<(1<<m);j++){
            if(check(j)) continue;// 因为状态里面每个点左右2个不能有点 进一步压缩状态
            if( (j&cnt)==j) e[i].push_back(j),w[i][j]=sum,sum++; // 先预处理出每个点可能得情况 这里是考虑炮兵能放的点
            //sum++;
        }
        //cout<<cnt<<" "<<sum<<endl;
    }
    for(auto u:e[1]) {dp[1][w[1][u]][0]=countOnes(u);ans=max(dp[1][w[1][u]][0],ans);}
    for(auto sec:e[2]){
        int i=w[2][sec];
        for(auto fir:e[1]){
            if( sec&fir) continue;
            int t=countOnes(sec);
            int j=w[1][fir];
            dp[2][i][j]=max(dp[2][i][j],t+dp[1][j][0]);
            ans=max(dp[2][i][j],ans);
        }
    }
    for (int i=3;i<=n;i++){
        for (auto jm : e[i]){        
            for (auto km : e[i-1]){    
                // 可把与 p 无关的判断和预处理提前做
                if (jm & km) continue;
                int t = countOnes(jm);
                int ji = w[i][jm];
                int ki = w[i-1][km];

                for (auto pm : e[i-2]){ // pm: mask of row i-2
                    if (km & pm) continue;
                    if (jm & pm) continue;
                    int pi = w[i-2][pm];
                    dp[i][ji][ki] = max(dp[i][ji][ki], dp[i-1][ki][pi] + t);
                    ans = max(ans, dp[i][ji][ki]);
                }
            }
        }
    }
    cout<<ans;
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
		slove();
    }
    return (0-0);
}