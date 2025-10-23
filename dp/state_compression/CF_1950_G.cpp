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
int n,ans;
int mp[30][30];
string c[30][3];
bool dp[3][1<<16][16];// 目前选了那些点的集合 并且开头 或者结尾都是什么
int count(int n) {
    int count = 0;
    unsigned int x = static_cast<unsigned int>(n); // 防止负数右移陷阱
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}
vector<int >e[65540];
void slove(){
    for(int i=0;i<(1<<n);i++) e[i].clear();
    ans=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            mp[i][j]=0;
        }
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            dp[0][i][j]=dp[1][i][j]=false;
        }
    }
    cin>>n;
    ans=0;
    map<string,vector<int > >a,b;
    for(int i=1;i<=n;i++){
        string s1,s2;cin>>s1>>s2;
        a[s1].push_back(i-1);
        b[s2].push_back(i-1);
        c[i][0]=s1;
        c[i][1]=s2;
    }
    for(int i=1;i<=n;i++){
        string t=c[i][0];
        int len=a[t].size();
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if(i==j) continue;
                mp[a[t][i]][a[t][j]]=1;
            }
        }
        t=c[i][1];
        len=b[t].size();
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if(i==j) continue;
                mp[b[t][i]][b[t][j]]=1;
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<mp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    for(int i=0;i<(1<<n);i++){
        int c;
        for(int j=0;j<n;j++){
            c=0;
            if(((1<<j)&i))  continue;
            for(int k=0;k<n;k++){
                if(!((1<<k)&i))  continue;
                if(mp[j][j]) c++;
            }
            if(c>=2) e[i].push_back(j);
        }
    }
    for(int i=0;i<n;i++){
        dp[0][(1<<i)][i]=dp[1][(1<<i)][i]=true;
    }
    for(int i=1;i<(1<<n);i++){
        if(count(i)==1) continue;
        for(int j=0;j<n;j++){ // 枚举新放入的一个数 作为左边
            if(!((1<<j)&i)) continue;
            int pre=(i^(1<<j));
            for(int k=0;k<n;k++){
                if(!(pre&(1<<k)) ) continue;
                if(mp[j][k]) {dp[0][i][j]|=dp[0][pre][k];}
            }
        }
        for(int j=0;j<n;j++){ // 枚举新放入的一个数 放到右边
            if(!((1<<j)&i)) continue;
            int pre=(i^(1<<j));
            for(int k=0;k<n;k++){
                if(!(pre&(1<<k)) ) continue;
                if(mp[j][k]) {dp[1][i][j]|=dp[1][pre][k];}
            }
        }
        if(count(i)==2) continue;
        for(int j=0;j<n;j++){
            if(!((1<<j)&i)) continue;
            for(auto u:e[i]){
                dp[0][i|(1<<u)][j]|=dp[0][i][j];
                dp[1][i|(1<<u)][j]|=dp[1][i][j];
            }
        }
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(dp[0][i][j] or dp[1][i][j]){
                ans=max(ans,count(i));
            }
        }
    }
    cout<<n-ans<<"\n";
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