// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=6e5;
const ll INF=1e17;
using namespace std;
int n;
void slove(){
    ll ans=0;
    cin>>n;
    vector<int > a(n+1);
    vector<int >qz(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        qz[i]=qz[i-1]+(a[i]==-1);
        //cout<<qz[i]<<" ";
    }
    for()
    cout<<ans<<"\n";
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