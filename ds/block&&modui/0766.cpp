// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
const ll mod=1e9+7;
const ll maxm=1e3;
const int maxn=3e5;
ll a[maxn];
ll block[maxm][maxm]; //代表所有mod i等于j的数加了多少
using namespace std;
int t,n,q,op,x,y,d;
void slove(){
    cin>>n>>q;
    for(int i=1;i<=q;i++){
        cin>>op>>x;
        if(op==1){
            cin>>y>>d;
            if(x>=700){
                for(int j=y;j<=n;j+=x){
                    a[j]+=d;
                }
            }
            else{
                block[x][y]+=d;
            }
        }
        else{
            ll s=0;
            for(int j=1;j<700;j++){
                s+=block[j][x%j];
            }
            cout<<a[x]+s<<"\n";
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