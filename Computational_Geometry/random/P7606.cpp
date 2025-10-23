// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const int N=101;
const int M=35;
using namespace std;
int t,n,mod,posl,posp;
#define m(x,y) ((x-y+mod)%mod) 
int  a[105][15]; // f[i][l][g][j][k]
bitset<M> f[2][N][N][M];//代表第i个数 走到了 (j,k)这个点 两个数值分别为l g
void slove(){
    cin>>n>>mod;
    int sq=sqrt(n)+2;
    f[0][0][0][sq ][sq]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=12;j++){
            cin>>a[i][j];
        }
    }
    random_shuffle(a+1,a+1+n);
    cin>>posl>>posp;
    for(int i=1;i<=n;i++){
        for(int l=0;l<mod;l++){
            for(int p=0;p<mod;p++){
                for(int k=0;k<=sq<<1;k++){
                    f[i&1][l][p][k].reset();
                    f[i&1][l][p][k]|=f[(i&1)^1][m(l,a[i][1])][m(p,a[i][2])][k]<<1;
                    f[i&1][l][p][k]|=f[(i&1)^1][m(l,a[i][3])][m(p,a[i][4])][k+1];
                    f[i&1][l][p][k]|=f[(i&1)^1][m(l,a[i][5])][m(p,a[i][6])][k+1]>>1;
                    f[i&1][l][p][k]|=f[(i&1)^1][m(l,a[i][7])][m(p,a[i][8])][k]>>1;
                    f[i&1][l][p][k]|=f[(i&1)^1][m(l,a[i][9])][m(p,a[i][10])][k-1];
                    f[i&1][l][p][k]|=f[(i&1)^1][m(l,a[i][11])][m(p,a[i][12])][k-1]<<1;
                }
            }
        }
    }
    if(f[n&1][posl][posp][sq][sq]) cout<<"Chaotic Evil";
    else cout<<"Not a true problem setter";
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    slove();
    return 0;
}