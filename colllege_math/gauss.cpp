// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=2e3;
using namespace std;
int t,n;
db a[maxn][maxn];
bool gauss(){//我们学的是高斯消元 高斯约旦效果差不多
    for(int i=1;i<=n;i++){//枚举所有列(既是行 也是列)
        int r=i;
        for(int k=i;k<=n;k++){
            if(fabs(a[k][i])>eps){
                r=k;break;
            }
        }
        if(r!=i) swap(a[i],a[r]);
        if(fabs(a[i][i])<eps) return 0;//无解或者说是无穷解
        for(int j=n+1;j>=i;j--)
            a[i][j]/=a[i][i];//这一步是把i行的头元素转为为1 那剩下的要除一个系数
        for(int k=i+1;k<=n;k++){
            for(int j=n+1;j>=i;j--){
                a[k][j]-=a[k][i]*a[i][j];
                // 这里 k是你要处理的行
                // j是你要处理的列
                // 那么显然就是要第i列的元素都为0 
                //因为第i列的头元素已经成1了 所以减去的系数是a[k][i] 在乘上这一列的系数
                //这一步 归根结底就是全部变0
            }
        }
    }
    for(int i=n-1;i>=1;i--){//这一步就是回代
        for(int j=i+1;j<=n;j++){
            a[i][n+1]-=a[i][j]*a[j][n+1];
        }
    }
    return 1;
}
void slove(){
    cin>>n;
	for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1;j++)cin>>a[i][j];
    }
    if(gauss()) {
        for(int i=1;i<=n;i++) cout<<fixed<<setprecision(2)<<a[i][n+1]<<"\n";
    }
    else cout<<"No Solution";
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