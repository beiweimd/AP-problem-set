// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-12;
const int maxn=2e3;
using namespace std;
int t,n;
db a[maxn][maxn];
int eq(double w,double h)
{
    return (fabs(w-h)<1e-9);
}
void Gauss(void)
{
    int line=1;
    for (int i=1;i<=n;i++){
	    int id=line;
	    for (int j=line+1;j<=n;j++)
	        if (fabs(a[j][i])>fabs(a[id][i])) id=j;
	    if (eq(a[id][i],0)) continue;//如果要系数化为1的未知数系数为0，就跳过。
	    swap(a[line],a[id]);
	    for (int j=1;j<=n;j++){
	        if (j==line) continue;
	        double mul=a[j][i]/a[line][i];
	        for (int k=i;k<=n+1;k++)
	            a[j][k]-=a[line][k]*mul;
	    }
	line++;
    }
    if (line<=n)//消元没消完，一定是无解或无穷多解。
    {
	while (line<=n)
	    if (!eq(a[line++][n+1],0))//无解。
		{
		    printf("-1");
		    exit(0);
		}
	printf("0");//无穷多解。
	exit(0);
    }
}
void slove(){
    cin>>n;
	for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1;j++)cin>>a[i][j];
    }
    Gauss();
    for (int i=1;i<=n;i++){
	    double res=a[i][n+1]/a[i][i];
	    if (eq(res,0)) res=0;
	    printf("x%d=%.2lf\n",i,res);
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