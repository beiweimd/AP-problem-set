// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-12;                 // 精度略放宽一点
const int maxn=3e5;
const ll INF=1e17;
using namespace std;

struct node{
    int l,r,id;
};

void slove(){
    int n; cin>>n;
    vector<node>a(n);
    vector<bool>is(n,true);
    for(int i=0;i<n;i++){
        cin>>a[i].l>>a[i].r; a[i].id=i;
    }

    // 按 l 降序，l 相等按 r 降序
    sort(a.begin(),a.end(),[](const node&lef,const node&rig){
        if(lef.l!=rig.l) return lef.l>rig.l;
        else return lef.r>rig.r;
    });

    // --- 1) 去支配 + 去重 ---
    // 扫一遍维护历史最大 r；r <= maxr 的点（被支配）直接剔除。
    // 对于完全相同的 (l,r) 只保留一份代表，并记录同组 id，计算完回填。
    vector<node> p;                 // 保留的代表点（严格 r 递增）
    vector<vector<int>> grp;        // 每个代表点对应的一组原始 id

    int maxr = -1;
    for(int i=0;i<n;i++){
        if(!p.empty() && a[i].l==p.back().l && a[i].r==p.back().r){
            grp.back().push_back(a[i].id);     // 完全相同，进同一组
            continue;
        }
        if(a[i].r<=maxr){                        // 被支配
            is[a[i].id]=false;
            continue;
        }
        p.push_back(a[i]);
        grp.push_back(vector<int>(1,a[i].id));
        maxr=a[i].r;
    }

    int len=p.size();

    // --- 2) 对每个代表点计算 s1,s2 ---
    for(int i=0;i<len;i++){
        db s1=0.0L, s2=0.0L, num=1.0L;

        // j<i：b_j < b_i，分母 1/b_j - 1/b_i > 0
        for(int j=0;j<i;j++){
            db den = num/(db)p[j].r - num/(db)p[i].r;
            if(den>eps){
                db val = (num/(db)p[i].l - num/(db)p[j].l) / den;
                if(val>s2) s2=val;
            }
        }
        // j>i：a_j < a_i，分母 1/a_j - 1/a_i > 0
        for(int j=i+1;j<len;j++){
            db den = num/(db)p[j].l - num/(db)p[i].l;
            if(den>eps){
                db val = (num/(db)p[i].r - num/(db)p[j].r) / den;
                if(val>s1) s1=val;
            }
        }

        // 充要条件：s1*s2 <= 1
        bool ok = (s1*s2 <= num + eps);
        if(!ok){
            for(int id: grp[i]) is[id]=false;
        }
        // ok 时，不改 is（初始为 true），并把同组的 id 全部保留
    }

    // --- 3) 输出 ---
    for(int i=0;i<n;i++) if(is[i]) cout<<i+1<<" ";
    // cout<<"\n"; // 需要换行就放开
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

// // ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// #include <bits/stdc++.h>
// typedef long long ll;
// typedef long double db;
// const ll mod=1e9+7;
// const db pi=acos(-1);
// const db eps=1e-10;
// const int maxn=3e5;
// const ll INF=1e17;
// using namespace std;
// struct node{
//     int l,r,id;
// };
// void slove(){
//     int n;cin>>n;
//     vector<node>a(n);
//     vector<bool>is(n,true);
//     for(int i=0;i<n;i++){
//         cin>>a[i].l>>a[i].r; a[i].id=i;
//     }
//     sort(a.begin(),a.end(),[](const node&lef,const node&rig){
//         if(lef.l!=rig.l) return lef.l>rig.l;
//         else return lef.r>rig.r;
//     }
//     );
//     for(int i=0;i<n-1;i++){
//         if(a[i].r>a[i+1].r or(a[i].r==a[i].r && a[i].l>a[i].l)) is[a[i+1].id ]=false; // 先剔除掉所有不可能的
//     }
//     //cout<<1<<endl;
//     vector<node>p;
//     for(int i=0;i<n;i++){
//         if(is[a[i].id]) p.push_back(a[i]);
//     } int len=p.size();
//     //cout<<len<<endl;
//     for(int i=0;i<len;i++){
//         //int flag=0;
//         db s1=0,s2=0,num=1;
//         if(i!=0 && p[i].l==p[i-1].l && p[i].r==p[i-1].r){
//             is[p[i].id]=is[p[i-1].id];
//             continue;
//         }
//         for(int j=0;j<len;j++){
//             //if(p[j].l==p[i].l && p[j].r==p[i].r) continue;
//             //flag=1;
//             if(j<i)s2=max(s2,(num/p[i].l-num/p[j].l)/(num/p[j].r-num/p[i].r));
//             if(j>i)s1=max(s1,(num/p[i].r-num/p[j].r)/(num/p[j].l-num/p[i].l)    );
//         }
//         //cout<<s1<<" "<<s2<<" ";
//         //if(!flag) continue; // 这种说明全部相同 那肯定是ok的
//         if(s1*s2<num-eps) continue;
//         is[p[i].id]=false;
//     }
//     for(int i=0;i<n;i++) if(is[i]) cout<<i+1<<" ";
// 	return;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int t=1;
//     //cin>>t;
//     while(t--){
// 		slove();
//     }
//     return (0-0);
// }