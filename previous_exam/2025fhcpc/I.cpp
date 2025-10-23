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
//一个图至少有两个非割点 并且是一条链的情况
int n;char s;
void slove(){
    cin>>n;
    vector<int >a(n+1);
    int cnt=1;
    for(int i=2;i<n;i++){
        cin>>s;if(s=='1') a[i]=1;
        cnt=cnt+(a[i]==0);
    }
    if(cnt==1 or (cnt==2&& a[n-1]!=0) ){
        cout<<-1<<"\n";return ;
    }
    if(cnt==2){ // 一条链 并且两端分别是 n 和n-1
        cout<<n-1<<"\n";
        for(int i=n-1;i>1;i--) cout<<i<<" "<<i-1<<"\n";
        cout<<1<<" "<<n<<"\n";
    }
    else{ // 这个时候就是一个环加一个链
        cout<<n<<"\n";
        int pre=n;
        for(int i=2;i<n;i++){
            if(a[i]==1) {cout<<i<<" "<<pre<<"\n";pre=i;}//说明是割点 要在链上 
        }
        cout<<pre<<" "<<1<<"\n";
        pre=1; // 所有非割点的数量 加到环上
        cnt--;
        for(int i=2;i<n;i++){
            if(a[i]==0 && cnt==1) {cout<<i<<" "<<pre<<"\n";cout<<i<<" "<<1<<"\n";cnt--;}
            if(a[i]==0 && cnt>1) {cout<<i<<" "<<pre<<"\n"; pre=i;cnt--;}
        }
    }
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