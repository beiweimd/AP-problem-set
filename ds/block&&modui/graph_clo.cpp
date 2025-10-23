// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
const ll mod=1e9+7;
const int maxn=3e5;
const int maxm=2e3;
using namespace std;
int t,n,m,q,u,v,op,x;
vector<int> e[maxn];
vector<int > bige[maxn];
int an[maxn];
int clo[maxn]; // 代表每个点的颜色 0是白色
void slove(){
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        for(auto u:e[x]){
            if(e[u].size()>700){
                bige[x].push_back(u);
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>op>>x;
        if(op==1){
            clo[x]^=1;
            for(auto u:bige[x]){
                if(clo) an[u]++;
                else an[u]--;
            }
        }
        else{
            if(e[x].size()>700){
                cout<<an[x]<<"\n";
            }
            else{
                int s=0;
                for(auto u:e[x]) if(clo[u]) s++;
                cout<<s<<"\n";
            }
        }
    }
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
    return 0;
}