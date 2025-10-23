#include<bits/stdc++.h>
using namespace std;
int n,m;
void slove(){
    cin>>m>>n;
    vector<array<int,2>>a;
    for(int i=1;i<=n;i++){
        int u,v;cin>>u>>v;
        a.push_back({u,v});
    }
    sort(a.begin(),a.end(),[](const array<int,2>&a,const array<int,2>&b){
        return a[0]<b[0];
    }
    );
    int pre=0;
    if(a[0][0]<a[0][1]){
        cout<<"No"<<"\n";return ;
    }
    pre=a[0][1];
    for(int i=1;i<n;i++){
        if(a[i][0]==a[i-1][0]){
            if(a[i][1]==a[i-1][1]) continue;
            else {
                cout<<"No"<<"\n";return ;
            }
        }
        int diff=a[i][0]-a[i-1][0];
        if(pre+diff!=a[i][1]) {
            if(a[i][1]>diff-1){
                cout<<"No"<<"\n";return ;
            }
        }
        pre=a[i][1];
    }
    cout<<"Yes"<<"\n";
    return ;
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