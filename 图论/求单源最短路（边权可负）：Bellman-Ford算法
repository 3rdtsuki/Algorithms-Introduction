### 求单源最短路（边权可负）：Bellman-Ford算法

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
const int maxn = 2005;
int dis[maxn];
int n,m,s;
struct edge{
	int a,b,w;	
}e[maxn];
signed main(){
    cin>>n>>m>>s;
    for(int i=1;i<=n;++i){
    	dis[i]=maxn;
    }
    dis[s]=0;
    for(int i=1;i<=m;++i){
        cin>>e[i].a>>e[i].b>>e[i].w;
    }
    for(int i=1;i<=n-1;++i){ //最短路肯定小于n条边，更新n-1次 
    	for(int j=1;j<=m;++j){
    		dis[e[j].b]=min(dis[e[j].b],dis[e[j].a]+e[j].w); //bellman-ford
    	}
    }
    for(int i=1;i<=n;++i)
		cout<<dis[i]<<' '; 
}
/*
4 6 1
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4
output:
0 2 4 3
*/ 
```

