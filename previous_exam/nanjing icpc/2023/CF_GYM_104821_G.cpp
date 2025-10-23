#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=5e3+100;
const int M=1e4+10;
int n,m,k;
ll  ans,suf[maxn];
struct Compare{
    bool operator()(const pair<int,int>&a,const pair<int,int>&b ){
        return a.first>b.first;
    }
};
ll dp[maxn][M];
array<int,2>a[maxn];
void slove(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    priority_queue<pair<int,int>,vector< pair<int,int > > ,Compare>q;
    sort(a+1,a+1+n,[](const array<int,2>&b,const array<int,2> & c){
        return b[0]<c[0];
    }
    );
    for(int i=n;i>=1;i--){
        q.push({a[i][1],a[i][0]});
        ans+=a[i][1];
        while(q.size()>k){
            auto t=q.top();
            ans-=t.first;
            q.pop();
        }
        suf[i]=ans;
    }
    ans=0;
    for(int i=1;i<=n;i++){
        ll t=0;
        for(int j=m;j>=0;j--){
            dp[i][j]=dp[i-1][j];
            if(j>=a[i][0]) dp[i][j]=max(dp[i][j],dp[i-1][j-a[i][0]]+a[i][1]);
            t=max(dp[i][j],t);
        }
        ans=max(ans,t+suf[i+1]);
    }
    cout<<ans;
    return ;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;t=1;
    while(t--){
        slove();
    }
    return 0;
}