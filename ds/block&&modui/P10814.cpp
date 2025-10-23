// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
//本题是一道简单的扫描线
#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
const ll mod=1e9+7;
const int maxn=3e6;
using namespace std;
int t,n,m,l,r,num;
int c[maxn];
int lowbit(int x) {return x&(-x);}
vector<array<int,4>>p;
void modify(int x,int d){
    for(;x<=n;x+=lowbit(x)) c[x]+=d;
}
int query(int x){
    int s=0;
    for(;x>0;x-=lowbit(x)) s+=c[x];
    return s;
}
struct info
{
    int x;
    int y;
};
int ans[maxn];
info val[maxn];
bool cmp(info a,info b){
    if(a.y!=b.y) return a.y<b.y; //显然 小的在前面更新
    return a.x<b.x;  // 同一水平线的 先更新左边的
}
void slove(){
	cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num;
        val[i]=info{i,num}; // 数组可以抽象为平面的数点
    }
    sort(val+1,val+1+n,cmp);
    for(int i=1;i<=m;i++){
        cin>>l>>r>>num;
        p.push_back({l,r,num,i});
    }
    //维护一条从x=0往上扫的横线 然后查询的点按照从小到大进行排序 在扫的过程中不断更新 已有的点的数值
    sort(p.begin(),p.end(),[](const array<int,4>&a,const array<int ,4>&b){
        if(a[2]!=b[2]) return a[2]<b[2];
        else return a[1]>b[1];
    }
    );
    int pos=1; // 代表的是 我们原始的点对更新到了哪个点
    int posq=0; //代表的是 我们目前查到了第几个点
    while(posq<m){
        //原始点对要在扫描线的下方 并且
        while(pos<=n && val[pos].y<p[posq][2] or(val[pos].y==p[posq][2] && val[pos].x<=p[posq][1]) ){
            modify(val[pos].x,1);
            pos++;
        }  
        ans[p[posq][3]]=query(p[posq][1])-query(p[posq][0]-1);
        posq++;
    }
    for(int i=1;i<=m;i++){
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