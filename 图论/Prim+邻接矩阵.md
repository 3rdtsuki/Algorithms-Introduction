```cpp
#include"pch.h"
#include<iostream> 
#include<vector>
#include<algorithm>
#include<cstdio>
#include<stack> 
#include<queue>
#include<map>
#include<ctime>
using namespace std;
struct edge {
	int left, right, value;
	edge(){}
	edge(int l, int r, int v) :left(l), right(r), value(v) {
	}
	friend bool operator<(const edge &e1, const edge &e2) {
		//为了让优先队列存储我们自己设计的类，必须重载小于号
		//注意：给优先队列重载大小于号时，参数必须是const T&/T，不能仅仅&T，
		//这是优先队列出于安全的考虑
		return e1.value > e2.value;//要弹出最小值，需要将大于号重载为小于号
	}
} e[20][20];
int n, m, a, b;
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int temp;
		cin >> a >> b >> temp; 
		e[b][a].value = e[a][b].value = temp;
		e[b][a].left = e[a][b].right = b;
		e[b][a].right = e[a][b].left = a;
	}
	int *dis = new int[n];//dis是点到集合的距离
	for (int i = 1; i <= n; ++i) {
		dis[i] = 888;
	}
	dis[0] = 0;


	bool *flag = new bool[n+1];
	priority_queue<edge>prq;
	int ans = 0;

	int u = 1;
	flag[u] = 1;
	for (int neighbor = 1; neighbor <= n; ++neighbor) {//把初始点相连的边都放入小根堆
		if (e[u][neighbor].value == 0)continue;
		prq.push(e[u][neighbor]);
	}
	cout << endl;


	while (!prq.empty()) {
		edge less_value_edge = prq.top();
		if (flag[less_value_edge.left] & flag[less_value_edge.right] == 1) {//防止成环
			prq.pop();
			continue;
		}
		cout <<less_value_edge.left<<' '<<less_value_edge.right<<' '<< less_value_edge.value<<endl;
		ans += less_value_edge.value;
		prq.pop();
		u = flag[less_value_edge.left] == 1 ? less_value_edge.right : less_value_edge.left;//u是当前集合外的顶点，要将它放入集合中
		flag[u] = 1;
		for (int neighbor = 1; neighbor<=n; ++neighbor) {
			if (flag[neighbor] == 1)continue;
			if (e[u][neighbor].value == 0)continue;
			dis[neighbor] = e[u][neighbor].value;
			edge new_e(u, neighbor, dis[neighbor]);
			prq.push(new_e);//这里加入最小堆时是可以冗余的，
				//因为原来的肯定不是最小，肯定不会被pop出来，再加上flag的限制就ok
		}
	}
	cout << ans;
}
/*
6
10
1 2 6
1 3 1
1 4 5
2 3 5
2 5 3
3 5 6
3 4 5
3 6 4
4 6 2
5 6 6
*/
//output:15
```
