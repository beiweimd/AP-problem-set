#include <cstdio>
typedef long long ll;
typedef long double db;
const ll mod = 1e9 + 7;
const db eps = 1e-10;
const int maxn = 3e5 + 10;  // 避免越界，多开一点
const ll INF = 1e17;
using namespace std;

int n, m;
int f[maxn * 2];  // 双倍空间：1~n为自身，n+1~2n为敌人

// 路径压缩查找
int getf(int v) {
    if (f[v] == v) return v;
    return f[v] = getf(f[v]);  // 简化写法
}

// 合并两个集合
void merge(int v, int u) {
    int t1 = getf(v);
    int t2 = getf(u);
    if (t1 != t2) {
        f[t2] = t1;
    }
}

void solve() {
    scanf("%d%d", &n, &m);  // 用scanf读入
    // 初始化并查集：1~n为自身，n+1~2n为敌人
    for (int i = 1; i <= 2 * n; i++) {
        f[i] = i;
    }
    while (m--) {
        char op[2];  // 用字符数组避免scanf读char的问题
        int a, b;
        scanf("%s%d%d", op, &a, &b);  // 读入操作符和两个数
        
        if (op[0] == 'A') {
            // 判断关系
            if (getf(a) == getf(b)) {
                printf("In the same gang.\n");  // 用printf输出
            } else if (getf(a) == getf(b + n)) {
                printf("In different gangs.\n");
            } else {
                printf("Not sure yet.\n");
            }
        } else {
            // 合并：a和b是敌人
            merge(a, b + n);
            merge(a + n, b);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);  // 读入测试组数
    while (t--) {
        solve();
    }
    return 0;
}
