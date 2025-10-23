#include <bits/stdc++.h>
typedef long long ll;
const int maxn=3e5;
using namespace std;
int n;
vector<pair<int,int > >e[maxn];
ll ans[maxn];
ll max_=1e9+1,low_=0;
void dfs(int x,ll pre,int fa,int xishu){
    //cout<<pre<<" "<<xishu<<endl;
    if(max_<=low_+1){
        return ;
    }
    if(xishu==-1){
        if(pre<0) { // -x-pre>0 直接无解
            max_=0,low_=1e9;
            return ;
        }
        else{  // -x+pre>0 x<pre
            max_=min(pre,max_);
        }
    }
    else{
        if(pre>0) { // x+pre>0 对答案没有影响

        }
        else{  //x-pre>0
            low_=max(pre*-1,low_);
        }
    }
    //cout<<"**"<<low_<<" "<<max_<<endl;
    for(auto [u,val]:e[x]){
        if(u==fa) continue;
        dfs(u,val-pre,x,xishu*-1);
    }
    return ;
}
void check(int x,ll pre,int fa ){
    ans[x]=pre;
    for(auto [to,val]:e[x]){
        if(to==fa) continue;
        check(to,val-pre,x);
    }
    return ;
}
void solve() {
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v; ll w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        swap(u,v);
        e[u].push_back({v,w});
    }
    for(auto [to,val]:e[1]){
        dfs(to,val,1,-1);
    }
    if(low_+1>=max_ ){
        cout<<"NO";return ;
    }
    cout<<"YES"<<"\n";
    ans[1]=low_+1;
    check(1,ans[1],0);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    while (_--) {
        solve();
    }
    return 0;
}