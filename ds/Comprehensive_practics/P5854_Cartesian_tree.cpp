// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// Cartesian_tree 首先数组下表 也就是pos 满足二叉搜索树的特质 这样中序遍历后 得到的就是原数组 这是显然的
// 其次 对于每个pos的val[pos] 要满足堆的性质 即每个点的孩子都要大于(小于)自己的数值
//所以：要么你就直接在右链的最顶部往上append 要么就是在右链中 把下面的右链全部搞为左子树 自己作为右链末端
//https://oi-wiki.org/ds/cartesian-tree/#c-%E5%AE%9E%E7%8E%B0
#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
const ll mod=1e9+7;
const int maxn=1e7+100;
using namespace std;
int t,a[maxn],n;
struct info
{
    int val; // 代表这个点的数值
    int lef=0,rig=0; // 分别代表lef 和rig的孩子结点
};
info seg[maxn];
stack<int >st;
void build(){ // 建立我们的笛卡尔树
    for(int i=1;i<=n;i++){
        int num=a[i],pre=0;
        while(!st.empty() && a[st.top()]>num ){
            pre=st.top();
            st.pop();
        }
        if(!st.empty()){
            seg[st.top()].rig=i;
        }
        seg[i].lef=pre;
        st.push(i);
    }
    return ;
}
void slove(){
    cin>>n;for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build();
    ll ansl=0,ansr=0;
    for(int i=1;i<=n;i++){
        ansl=ansl^((ll)i*(seg[i].lef+1));
        ansr=ansr^((ll)i*(seg[i].rig+1));
    }
    cout<<ansl<<" "<<ansr;
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