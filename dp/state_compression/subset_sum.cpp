// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
using namespace std;
int n;
ll ans;
unsigned int A,B,C;
ll f[(1<<22)+10];
inline unsigned int rng61() {
    A ^= A << 16;
    A ^= A >> 5;
    A ^= A << 1;
    unsigned int t = A;
    A = B;
    B = C;
    C ^= t ^ A;
    return C;
}
void slove(){
    cin>>n>>A>>B>>C;
    for (int i = 0; i < (1 << n); i++)
        f[i] = rng61();
    for(int i=0;i<n;i++){ // 枚举n位
        for(int j=0;j<(1<<n);j++){
            if( j & (1<<i) ) f[j] += f [ j - ( 1<< i )  ]; // 如果这一位是1 按照前缀和求解
        }
    }  
    for (int i = 0; i < (1 << n); i++)
        ans^=f[i];
    cout<<ans;
	return;
}
int main(){
    slove();
    return 0;
}