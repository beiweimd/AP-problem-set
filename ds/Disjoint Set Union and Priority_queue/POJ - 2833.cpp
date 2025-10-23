#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

priority_queue<int > a;//大根堆
priority_queue<int ,vector<int> ,greater<int> > a1;//小根堆
int n,n1,n2,k,ll[21];
long long ans;
double ans1;

int main() {
    while(scanf("%d%d%d", &n1, &n2, &n) == 3 && n1 && n2 && n) {
        while (!a.empty()) a.pop();//初始化一定要记得
        while (!a1.empty()) a1.pop();//初始化一定要记得
        ans = ans1 = 0;//初始化一定要记得
        for(int i = 1;i <= n1 + n2; i++)
            scanf("%d",&ll[i]);
        sort(ll+1,ll+n1+n2+1);
        for(int i = 1;i <= n2; i++)
            a.push(ll[i]);
        for(int i = n2 + 1;i <= n2 + n1; i++)
            a1.push(ll[i]);
        for(int i = n1+n2+1;i <= n; i++) {
            scanf("%d",&k);
            if(k >= a1.top()) {
                    ans += a1.top();
                    a1.pop();
                    a1.push(k);
                    continue;
            }
            if(k <= a.top()) {
                    ans += a.top();
                    a.pop();
                    a.push(k);
                    continue;
            }
            ans += k;
        }
        ans1 = ans;
        printf("%.6f\n",ans1 / (n - n1 -n2));
    }
    return 0;
}