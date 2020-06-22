### 最大流问题Ford-Fulkerson算法：  

只要剩余图中存在从s到t的增广路径（bfs实现的FF算法称为Edmonds-Karp(EK)算法，并且找到的路径是最短的），就求瓶颈容量minflow，不断迭代，求出最终的maxflow  

但是时间复杂度为O(mC)，会被卡常

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
#define int long long
const int maxn = 205;
int map[maxn][maxn],pre[maxn];
int n,m,s,t,a,b;
int flag[maxn];
bool bfs(int start,int end){ //判断有无增广路径
	memset(flag,0,sizeof(flag)); //一定要初始化
	memset(pre,0,sizeof(pre)); 
	queue<int>q;
	q.push(start);
	flag[start]=1;
	pre[start]=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=1;i<=n;++i){
			if(map[now][i]>0&&flag[i]==0){
				flag[i]=1;
				pre[i]=now;
				if(i==end){
					return true;
				}
				q.push(i);
			}
		}
	}
	return false;
}

int ford_fulkerson(int start,int end){
	int maxflow=0;
	while(bfs(start,end)){ //只要存在增广路径就迭代
		int minflow=maxn;
		for(int i=end;i!=start;i=pre[i]){
			minflow=min(minflow,map[pre[i]][i]);
		}
		for(int i=end;i!=start;i=pre[i]){
			map[pre[i]][i]-=minflow;
			map[i][pre[i]]+=minflow;
		}
		maxflow+=minflow;
	
	}
	return maxflow;
}
signed main(){
    cin>>n>>m>>s>>t;
    int w;
    for(int i=0;i<m;++i){
        cin>>a>>b>>w;
		map[a][b]=w;
    }
    cout<<ford_fulkerson(s,t);
}
/*
4 5 4 3
4 2 30
4 3 20
2 3 20
2 1 30
1 3 40
output:
50
*/
```

