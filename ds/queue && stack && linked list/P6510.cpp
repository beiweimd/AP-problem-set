// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
int n,ans,a[maxn],s1[maxn],p1; // s1是维护每个点左边第一个大于等于自己的点 
int s2[maxn],p2;// s2维护的是[1,i]的最小值 那么这个时候就是单调递增了 
void slove(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    // 思路是  假设右端点是B 我们用一个单调递减的栈找到B点左边第一个大于等于他的点 记为X
    // 那么只要找到从X+1到B之间最小的一个数 这个数就是A  这里可以维护单调递增栈 然后在栈内二分
    for(int i=1;i<=n;i++){
        while(p1!=0 && a[i]>a[s1[p1]] ) p1--; // 这里维护单调递减是因为：对于我们新加入的点 所有小于自己的点是没有意思的 直接弹出即可 那么栈顶的元素就是X
        while(p2!=0 && a[i]<=a[s2[p2]] ) p2--; // 这里等于也删除 是因为 [A,B]中间不能有等于A的数 也就是最小值相同只取最右边的情况
        int k=upper_bound(s2+1,s2+p2+1,s1[p1])-s2;
        if(k!=p2+1) ans=max(ans,i-s2[k]+1);
        s1[++p1]=i;
        s2[++p2]=i;
    }
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