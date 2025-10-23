// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
const ll mod=1e9+7;
const int maxn=1e5;
using namespace std;
int t,n;
int a[maxn];
int ans[maxn];
void slove(){
    cin>>n;
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    for(int i=2;i<=n;i++){
        int num;cin>>num;
        num=i-1-num; // 前面有多少头牛大于自己
       // cout<<i<<" "<<num<<endl;
        for(int j=i;j>i-num;j--){
            swap(a[j],a[j-1]);
        }
    }
    for(int i=1;i<=n;i++){
       // cout<<a[i]<<"\n";
        ans[a[i]]=i;
    }
    for(int i=1;i<=n;i++ ) cout<<ans[i]<<"\n";
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