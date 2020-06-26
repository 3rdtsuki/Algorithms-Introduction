### Kruskal最小生成树

并查集：开始将father[i]均设为i，一旦加入一条边father[b]=a，通过find函数寻找祖先

https://www.luogu.com.cn/problem/P3366

```cpp
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 200005;
int father[maxn];
struct edge{
    int a,b,v;
}e[maxn];
bool cmp(edge x,edge y){
    return x.v<y.v;
}
int find(int x){ //求祖先
    if(x!=father[x]){
        father[x]=find(father[x]);
    }
    return father[x];
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>e[i].a>>e[i].b>>e[i].v;
    }
    sort(e,e+m,cmp);
    for(int i=0;i<n;++i){
        father[i]=i;
    }
    int sum=0,cnt=0;
    for(int i=0;i<m;++i){
        int xx=find(e[i].a);
        int yy=find(e[i].b);
        if(xx==yy)continue;
        father[yy]=xx;
        sum+=e[i].v;
        cnt++;
    }
    if(cnt!=n-1)cout<<"orz"; //达不到n-1条边（非连通图）
    else cout<<sum;
}
```

