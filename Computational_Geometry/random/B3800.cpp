// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e6;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
using namespace std;
int t,n;
set<int >s;
ll a[maxn],b[maxn],c[maxn];
bool check(ll x){
    for(int i=1;i<=n;i++){
        if(x*x*x+a[i]*x*x+b[i]*x+c[i]==0) return false;
    }
    return true;
}
void slove(){
	cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=20000000;i++){
        ll num= rand() * 1ll * rand() % mod; // rand 在 Windows 系统中的值域为 0 至 32767
        if(check(num)){
            cout<<num;return ;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand((unsigned)time(0));
    t=1;
    while(t--){
		slove();
    }
    return 0;
}