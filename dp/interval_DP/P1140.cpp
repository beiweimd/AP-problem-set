// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=2e3;
const ll INF=1e17;
using namespace std;
ll dp[maxn][maxn];// a的前i个串和b的前j个串之间最大相似度
string a,b;
int lena,lenb;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    std::map<char,int> idx {
        {'A', 0},
        {'C', 1},
        {'G', 2},
        {'T', 3},
        {'-', 4}
    };

    // 2) 定义一个 5x5 的矩阵，并用初始化列表填值
    //    对应行/列依次为 A, C, G, T, -
    std::vector<std::vector<int>> mat = {
        /* A */ {  5, -1, -2, -1, -3 },
        /* C */ { -1,  5, -3, -2, -4 },
        /* G */ { -2, -3,  5, -2, -2 },
        /* T */ { -1, -2, -2,  5, -1 },
        /* - */ { -3, -4, -2, -1,  0  }  // 最后一项用 0 或其他哨兵值代替 '*'
    };
    cin>>lena>>a>>lenb>>b;
    a=" "+a;b=" "+b;
    ll pre=0;
    for(int i=1;i<=lena;i++){
        pre+=mat[idx[a[i]]] [idx['-']];
        dp[i][0]=pre;
    }
    pre=0;
    for(int i=1;i<=lenb;i++){
        pre+=mat[idx[b[i]]] [idx['-']];
        dp[0][i]=pre;
    }
    for(int i=1;i<=lena;i++){
        for(int j=1;j<=lenb;j++){
            char la=a[i],lb=b[j];
            dp[i][j]=max( dp[i-1][j-1]+mat[idx[la]][idx[lb]], // 第一种两个直接匹配
                   max(dp[i][j-1]+mat[idx[lb]][idx['-']],
                dp[i-1][j]+mat[idx[la]][idx['-']])
            );
        }
    }
    cout<<dp[lena][lenb];
    return (0-0);
}