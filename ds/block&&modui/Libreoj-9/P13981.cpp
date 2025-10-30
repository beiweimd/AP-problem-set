#include <bits/stdc++.h>
typedef long long ll;
const int maxn=3e5+100;
using namespace std;
int n,m,op,l,r,c,p;
ll val[maxn];
int belong[maxn];
int bt(int x) {return (x-1)/m+1;}
vector<int >e[maxn];
int len[maxn];
void updata(){
    l--;//题目给的是前 我们这个-一下 搞成在后面比较好搞
    int pos=1;
    while(len[pos]<l){a
        l-=len[pos];
        pos++;
    }
    e[pos].insert(e[pos].begin()+l,r);
    len[pos]++;
    return ;
}
ll query(){
    int pos=1;
    while(len[pos]<c){
        c-=len[pos];
        pos++;
    }
    return e[pos][c-1];
}
int main() {
    cin>>n;
    m=max(10,(int)sqrt(n));
    for(int i=1;i<=n;i++){
        cin>>val[i];
        belong[i]=bt(i);
        e[belong[i]].push_back(val[i]);
        len[belong[i]]++;
    }
    //v.insert(v.begin() + pos, x);
    //插入x到当做pos下标
    for(int i=1;i<=n;i++){
        cin>>op;
        if(op==1) {
            cin>>c;
            cout<<query()<<"\n";
        }
        else {
            cin>>l>>r;
            updata();
        }
    }
    return 0;
}
