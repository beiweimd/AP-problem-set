// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
//本题是一道简单的扫描线
#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
const ll mod=1e9+7;
const int maxn=3e5;
using namespace std;
int t,n,m,l,r,num,q,x,y;
int c[maxn],ans[maxn];
int lowbit(int x) {return x&(-x);}
void modify(int x,int d){
    for(;x<=m;x+=lowbit(x)) c[x]+=d;
}
int query(int x){
    int s=0;
    for(;x>0;x-=lowbit(x)) s+=c[x];
    return s;
}
vector<array<int,4>>event; // 扫描线的事件
void slove(){
	cin>>n>>q;
    vector<int >vx;
    for(int i=1;i<=n;i++){ // Y轴是移动的scan_line x轴需要使用树状数组维护 所以对x轴进行离散化处理
        cin>>x>>y;
        vx.push_back(x);
        event.push_back({y,0,x,i}); // 分别代表你的纵坐标 事件情况 横坐标和id
    }
    for(int i=1;i<=q;i++){
        int x_1,x_2,y_1,y_2;
        cin>>x_1>>x_2>>y_1>>y_2;
        event.push_back({y_2,2,x_2,i } ); // 四个参数同理
        event.push_back({y_1-1,2,x_1-1,i } ); // 四个参数同理
        event.push_back({y_2,1,x_1-1,i } ); // 四个参数同理
        event.push_back({y_1-1,1,x_2,i } ); // 四个参数同理
    }
    sort(event.begin(),event.end());
    sort(vx.begin(),vx.end());
    vx.erase(unique(vx.begin(),vx.end()),vx.end()); // 离散化处理
    m=vx.size();
    for(int i=0;i<event.size();i++){
        if(event[i][1]==0){ // 如果是原本的点 直接记录答案
            int pos=lower_bound(vx.begin(),vx.end(),event[i][2])-vx.begin()+1 ;// 因为树状数组是从1开始 的 更新一下
            modify(pos,1);
        }else{
            int pos=upper_bound(vx.begin(),vx.end(),event[i][2])-vx.begin(); // 这里找到第一个大于的 然后大于后面的就是要的答案 -1 +1抵消
            int tmp=query(pos);
            if(event[i][1]==1) ans[event[i][3]]-=tmp;
            else ans[event[i][3]]+=tmp;
        }
    }
    for(int i=1;i<=q;i++){
        cout<<ans[i]<<"\n";
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