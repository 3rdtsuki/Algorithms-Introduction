### bfs输出两点间所有路径

显然要用一个队列，套模板即可  

输出的路径是由短到长的（本题默认边权为1，所以就是节点个数从小到大）

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
const int maxn = 2005;
int n,m,a,b,w;
int map[maxn][maxn];
int flag[maxn];
int pre[maxn];
void bfs(int start,int end){
	queue<int>q;
	q.push(start);
	flag[start]=1;
	pre[start]=0;
    
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=1;i<=n;++i){
			if(map[now][i]&&flag[i]==0){
				flag[i]=1;
				pre[i]=now;//pre记录路径
				if(i==end){
					int p=end;
					stack<int>s;//栈反向输出
					while(pre[p]){
						s.push(p);
						p=pre[p];
					}
					s.push(start);
					while(!s.empty()){
						cout<<s.top()<<' ';
						s.pop();
					}
					cout<<endl;
                    //如果这里加上return;就是只输出最短路径
				}
				q.push(i);
				flag[i]=0;//类似dfs的回溯，将标记改回0
			}
		}
	}
}
int main(){
	cin>>n>>m;
    for(int i=1;i<=m;++i){
        cin>>a>>b>>w;
        map[a][b]=w;
    }
    bfs(4,3);
}
/*
4 5
4 2 30
4 3 20
2 3 20
2 1 30
1 3 40
output:
4 3
4 2 3
4 2 1 3
*/
```

