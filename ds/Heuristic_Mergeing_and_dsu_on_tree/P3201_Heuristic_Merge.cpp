// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=2e5;
const int maxm=2e6;
using namespace std;
int t,n,m,ans; // ans代表我们有多少段
int a[maxn];
vector<int >pos[maxm];
void slove(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]].push_back(i);
    }
    for(int i=1;i<=n+1;i++){
        if(a[i]!=a[i-1]) ans++;
    }
    // 这里我们把a[0]和a[n+1]设置为0 会多算一段 比如全部是颜色1我们答案是2
    for(int i=1;i<=m;i++){
        int op;cin>>op;
        if(op==2){
            cout<<ans-1<<"\n";
        }
        else{
            int x,y;cin>>x>>y;//这里两个颜色合并是等价的 所以我们交换 小的合并到大的里面去
            if(x==y) continue;//特判相同的情况 合并会很诡异
            if(pos[x].size()>pos[y].size()  ) swap(pos[x],pos[y]);
            if(pos[y].size()==0) continue;//两个集合都是空的 
            auto add=[&](int u,int c){
                ans-=(a[u]!=a[u-1])+(a[u]!=a[u+1]);
                a[u]=c;
                ans+=(a[u]!=a[u-1])+(a[u]!=a[u+1]);
            };
            int c=a[pos[y][0]];//找到要合并的集合的颜色
            for(auto u:pos[x]){
                add(u,c);
                pos[y].push_back(u);
            }
            pos[x].clear();//一定要清空
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