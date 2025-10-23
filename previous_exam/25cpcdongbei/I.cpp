// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=2e6;
using namespace std;
int t,n;
int a[maxn];
ll ans;
int dp[maxn][30];
void init() {
	for (int j=1; j<=20; ++j)
		for (int i=1; i + (1 << j) - 1 <= n; ++i)
			dp[i][j] = __gcd(dp[i][j-1], dp[i+(1 << (j-1))][j-1]);
}
int query(int l, int r) {
	int k = log2(r - l + 1);
	return __gcd(dp[l][k], dp[r - (1 << k) + 1][k]);
}
void slove(){
	cin>>n;for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][0]=a[i];
    }
    init();
    for(int i=1;i<=n;i++){
        int num=a[i];
        int l=1,r=i-1;
        int lef,rig;
        while(l<=r){
            int mid=(l+r+1)/2;
            if(query(mid,i)<num  ) {
                r=mid-1;
            }
            else l=mid+1;
        }
        lef=l;
        l=i,r=n;
        while(l<=r){
            int mid=(l+r+1)/2;
            if(query(i,mid)<num) {
                r=mid-1;
            }
            else l=mid+1;
        }     rig=l-1;
        cout<<lef<<" "<<rig<<endl;
    //     if(lef==i-1 && a[lef]==a[i]){
    //         ans=ans+rig-i+1;
    //         continue;
    //     }
    //    // cout<<lef<<" "<<rig<<endl;
    //     if(rig==i){
    //         ans+=(i-lef+1);
    //         continue;
    //     }
    //     if(lef==i){
    //         ans+=(r-i+1);
    //         continue;
    //     }
        ans=ans+(i-lef+1)*1ll*(rig-i+1);
        //cout<<lef<<" "<<rig<<endl;
    }
    cout<<ans;
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