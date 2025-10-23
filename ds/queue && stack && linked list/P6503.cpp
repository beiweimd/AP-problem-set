// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
const int MAXN = 300000 + 5;      // 按需调大
const int LOG   = 20;             // 能覆盖 n ≤ 2^20 ≈ 1e6
using namespace std;
int a[MAXN];                      // 原序列（1-based）
int mx[MAXN][LOG + 1];            // 最大值下标 ST
int mn[MAXN][LOG + 1];            // 最小值下标 ST
int n;                             // 全局长度
ll ans;
/*----------------  预处理  ----------------*/
void init() {
    /* 长度 1（j = 0）直接存下标本身 */
    for (int i = 1; i <= n; ++i)
        mx[i][0] = mn[i][0] = i;

    /* j > 0：利用两段合并 */
    for (int j = 1; j <= LOG; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            int mid = i + (1 << (j - 1));

            /* 最大值表 */
            int L = mx[i][j - 1];
            int R = mx[mid][j - 1];
            mx[i][j] = (a[L] >= a[R] ? L : R);   // 并列取左

            /* 最小值表 */
            L = mn[i][j - 1];
            R = mn[mid][j - 1];
            mn[i][j] = (a[L] <= a[R] ? L : R);   // 并列取左
        }
}

/*----------------  查询 O(1)  ----------------*/
inline int queryMaxIdx(int l, int r) {
    int k = (int)log2(r - l + 1);
    int x = mx[l][k];
    int y = mx[r - (1 << k) + 1][k];
    return (a[x] >= a[y] ? x : y);
}

inline int queryMinIdx(int l, int r) {
    int k = (int)log2(r - l + 1);
    int x = mn[l][k];
    int y = mn[r - (1 << k) + 1][k];
    return (a[x] <= a[y] ? x : y);
}
// class ST{
//     int n,k;
//     vector<int > a,lg2;
//     vector<vector<int > > stmi, stmx;
// public:
//     ST():n(0),k(0){}
//     explicit ST(const vector<int> &arr){build(arr);}
//     void build(const vector<int >&arr){
//         a=arr; n=(int)a.size();

//         k=1;
//         while( (1<<k)<=n) k++;

//         lg2.assign(n+1,0);
//         for(int i=1;i<=n;i++) lg2[i]=lg2[i>>1]+1;
        
//         stmi.assign(n,vector<int >(k));
//         stmx.assign(n,vector<int >(k));
        
//         for(int i=0;i<n;i++) stmi[i][0]=stmx[i][0]=i;
        
//         for(int j=1;j<k;j++){
//             int len=(1<<j); int half=(len>>1);
//             for(int i=0;i+len<n+1;i++){
//                 int mid=i+half;
//                 int lmin=stmi[i][j-1];
//                 int rmin=stmi[mid][j+1];
//                 stmi[i][j]=(a[lmin]<=a[rmin]?lmin:rmin);

//                 int lmax=stmx[i][j-1];
//                 int rmax=stmx[mid][j+1];
//                 stmx[i][j]=(a[lmax]>=a[rmax]?lmax:rmax);
//             }
//         }
//     }
//     int queryMinIdx(int l, int r) const {
//         int k = lg2[r - l + 1];
//         int left = stmi[l][k];
//         int right = stmi[r - (1 << k) + 1][k];
//         return (a[left] <= a[right] ? left : right);
//     }
//     int queryMaxIdx(int l, int r) const {
//         int k = lg2[r - l + 1];
//         int left = stmx[l][k];
//         int right = stmx[r - (1 << k) + 1][k];
//         return (a[left] >= a[right] ? left : right);
//     }
// };
void dfs(int l, int r){
    if(l>r) return ;
    if(l==r) {
        ans+=a[l];
        return ;
    }
    int k=queryMaxIdx(l,r);
    ans=ans+a[k]*1ll*(r-k+1)*(k-l+1);
    dfs(l,k-1);
    dfs(k+1,r);
    return ;
}
void dfs2(int l, int r){
    if(l>r) return ;
    if(l==r) {
        ans-=a[l];
        return ;
    }
    int k=queryMinIdx(l,r);
    ans=ans-a[k]*1ll*(r-k+1)*(k-l+1);
    dfs2(l,k-1);
    dfs2(k+1,r);
    return ;
}
void slove(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    init();
    dfs(1,n);
    dfs2(1,n);
    cout<<ans;
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