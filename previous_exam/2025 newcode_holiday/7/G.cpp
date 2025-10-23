#include <bits/stdc++.h>
using namespace std;
int n;
void slove(){
    cin>>n;
    vector < int > ans;
    vector<int>p(n+1,0);
    for(int i=2;i<=n;i++)
    {
        if(!p[i]) p[i]=i;
        for(int j=i*2;j<=n;j+=i)
        {
            if(!p[j]) p[j]=i;// 记住每个数最小的额质因子
        }
    }
    for(int i=2;i<=n;i++){
        int num=i;
        map<int,int>mp;
        while(num>1){
            mp[p[num]]++;
            num/=p[num];
        }
        int cnt=0;
        for(auto it:mp) cnt+=it.second;
        if(cnt&1) ans.push_back(i);
    }
    for(int i=0;i<n/2;i++) cout<<ans[i]<<" ";
    cout<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        slove();
    }
    return 0;
}