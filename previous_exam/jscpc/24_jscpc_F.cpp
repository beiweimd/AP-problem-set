// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
using namespace std;
int t,n,k;
db a[maxn],pre[maxn];
void slove(){
	cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    cout<<fixed<<setprecision(6);
    for(int i=1;i<=n-k+1;i++){
        db num=pre[i+k-1]-pre[i-1];
        num/=k;
        if(num<1024+eps ){
            cout<<num<<" KiBps"<<"\n";
        }
        else {
            cout<<num/1024<<" MiBps"<<"\n";
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
    return (0-0);
}