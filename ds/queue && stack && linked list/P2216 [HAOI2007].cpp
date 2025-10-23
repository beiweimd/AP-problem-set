// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
int a,b,n;
int mp[1100][1100];
void slove(){
    int ans=1e9+1;
	cin>>a>>b>>n;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++) cin>>mp[i][j];
    }
    deque<int >mx,mi;
    for(int i=1;i+n-1<=a;i++){ // 枚举x轴的位置
        int pos=n; // 维护Y轴的位置
        for(int l=)
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