#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5+100;
const ll INF=1e17;
using namespace std;

int n,op,m;
ll ans[maxn];
ll val[maxn];
int bt(int x){return 1+(x-1)/m;}

struct Node{ int f,id; };        // f: 频次, id: 压缩后编号(小=原值小)
int b[maxn], cnt[maxn];

struct Compare{
    bool operator()(const Node&a,const Node&b) const{
        if(a.f!=b.f) return a.f>b.f;   // 频次降序
        else return a.id<b.id;         // 值(编号)升序
    }
};

void slove(){
    cin>>n;
    m=max(10,(int)sqrt(n));
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }

    // 坐标压缩：disc 升序去重，b[i] 为 1..M
    vector<ll> disc; disc.reserve(n);
    for(int i=1;i<=n;i++) disc.push_back(val[i]);
    sort(disc.begin(),disc.end());
    disc.erase(unique(disc.begin(),disc.end()),disc.end());
    auto getId = [&](ll x)->int{
        return int(lower_bound(disc.begin(),disc.end(),x)-disc.begin())+1;
    };
    for(int i=1;i<=n;i++) b[i]=getId(val[i]);

    vector<array<int,3>>q;
    q.reserve(n);
    for(int i=1;i<=n;i++){
        int l,r; cin>>l>>r;
        q.push_back({l,r,i});
    }
    // 莫队蛇形排序（按块号，再按 r 正反交替）
    sort(q.begin(),q.end(),[]( const array<int ,3>&a,const array<int,3>&b){
        int BA=bt(a[0]), BB=bt(b[0]);
        if(BA!=BB) return BA<BB;
        return (BA&1) ? (a[1]<b[1]) : (a[1]>b[1]);
    });

    // 维护众数：S 的 begin 即“最高频且值最小”
    set<Node,Compare> S;
    // 清空计数
    // （全局静态默认0；若多测请 memset(cnt,0,sizeof(int)*(disc.size()+3)); 并 S.clear();）
    int l=1,r=0;
    auto add=[&](int x){
        int id=b[x], f=cnt[id];
        if(f>0) S.erase(Node{f,id});
        cnt[id]=f+1;
        S.insert(Node{f+1,id});
    };
    auto del=[&](int x){
        int id=b[x], f=cnt[id];
        S.erase(Node{f,id});
        cnt[id]=f-1;
        if(cnt[id]>0) S.insert(Node{f-1,id});
    };

    for(int i=0;i<n;i++){
        int L=q[i][0],R=q[i][1];
        while(r<R) r++,add(r);
        while(l>L) l--,add(l);
        while(r>R) del(r),r--;
        while(l<L) del(l),l++;
        const Node top=*S.begin();
        ans[q[i][2]]=disc[top.id-1];   // 解压回原值
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<"\n";
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
