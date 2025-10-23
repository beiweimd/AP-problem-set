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
int n,k;
void slove(){
    cin>>n>>k;
    vector<int >a(n+1);
    vector<array<int,2> >ans(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    deque<int > q;
    for(int i=1;i<=n;i++){
        while(!q.empty() && a[i]<a[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
        while(q.front()<i-k+1) {q.pop_front();}
        if(i>=k){
           ans[i-k+1][0]=a[q.front()];
        }
    }
    q.clear();
    for(int i=1;i<=n;i++){
        while(!q.empty() && a[i]>a[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
        while(q.front()<i-k+1) {q.pop_front();}
        if(i>=k){
           ans[i-k+1][1]=a[q.front()];
        }
    }
    for(int i=1;i<=n-k+1;i++){
        cout<<ans[i][0]<<" ";
    }
    cout<<"\n";
    for(int i=1;i<=n-k+1;i++){
        cout<<ans[i][1]<<" ";
    }
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