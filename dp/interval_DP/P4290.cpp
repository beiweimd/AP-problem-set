// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=300;
const ll INF=1e17;
using namespace std;
string s;
int a[maxn],n;
map<char,int >has;
char fhas[maxn];
int mp[maxn][maxn][maxn];
int dp[maxn][maxn][5]; // W, I, N, G 只有这四个字母 
// dp[i][j][5] 代表将i j这段区间还原成 w i n g 四个字母是否可行 所以是一个三维的
void slove(){
    has['W']=1; has['I']=2;has['N']=3;has['G']=4;
    fhas[1]='W'; fhas[2]='I';fhas[3]='N';fhas[4]='G';
    for(int i=1;i<=4;i++){
        cin>>a[i];
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=a[i];j++){
            cin>>s;
            mp[i][has[s[0]]][has[s[1]]]=1;
        }
    }
    cin>>s;
    n=s.length();
    s=" "+s;
    for(int i=1;i<=n;i++){
        dp[i][i][has[s[i]]]=1;
    }
    //8e6 * 16 *16
    for(int  len=1;len<=n;len++){ // 长度
        for(int i=1;i+len<=n;i++){// 起点
            int j=i+len;          //终点
            for(int k=i;k<j;k++){  //[l,k] [k+1,j] 两边分别断为一个
                for(int l=1;l<=4;l++){ // 枚举左边合并的是什么
                    for(int r=1;r<=4;r++){ // 右边合并的是什么
                        if(dp[i][k][l]==1 && dp[k+1][j][r]==1 ){
                            char s1=fhas[l];
                            char s2=fhas[r];
                            for(int p=1;p<=4;p++){ // 枚举左右最终能合成什么 因为有可能相同的两个数可以替换掉不止一个字母
                                if(mp[p][has[s1]][has[s2 ]]==1) dp[i][j][p]=1;
                            }
                        }
                    }
                }
            }
        }
    }
    int flag=0;
    for(int i=1;i<=4;i++){
        if(dp[1][n][i]==1){
            cout<<fhas[i];
            flag=1;
        }
    }
    if(!flag) cout<<"The name is wrong!";
    // 给你一个字符串 每次选相邻的两个进行还原 还原成一个字母 
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