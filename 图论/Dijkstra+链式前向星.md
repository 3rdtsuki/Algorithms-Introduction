题目：https://www.luogu.com.cn/problem/P4779 
数组实现邻接表参见：https://www.cnblogs.com/zsh2016/p/5760126.html 

## 题目描述

给定一个n个点，m条有向边的带非负权图，请你计算从s出发，到每个点的距离。

```cpp
#include<iostream>
#include<queue>
#include<cstdio>
#define ll long long
#define M 200005
#define N 2147483647
using namespace std;
int n,m,s;
ll dis[M],
	head[M],//head[i]代表顶点i所连其中一条边的编号 
	flag[M],
	pre[M];//pre记录路径
struct edge{
    int l,r,v,
	next;//e[i].next代表第i条边前面的一条边 
}e[M];
struct node{
    int d,//node和集合的距离
	now;//node编号 
    bool operator<(const node &x)const {
        return d>x.d;
    }
}p;
priority_queue<node>q;
void bfs(){
    q.push((node){0,s});
    while(!q.empty()){
        p=q.top();//得到最近的点 
        q.pop();
        int t=p.now; 
        if(flag[t]==1)continue;
        flag[t]=1;
        for(int i=head[t];i;i=e[i].next){
            int x=e[i].r;
            if(dis[x]>dis[t]+e[i].v){
                dis[x]=dis[t]+e[i].v;
                pre[x]=t; 
                q.push((node){dis[x],x});
            }
        }
    }
}
int main(){
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        dis[i]=N;
    }
    dis[s]=0;
    int cnt=0;
    for(int i=1;i<=m;i++){
        int l,r,v;
        cin>>l>>r>>v;
        e[++cnt].r=r;//给边编号 
        e[cnt].v=v;
        e[cnt].next=head[l];//一旦新来一条边，把原来l在head中保存的边挪到e.next中 
        head[l]=cnt;//用新的边来代替挪走的head，最终head就是节点l链表的表头 
    }
    bfs();
    for(int i=1;i<=n;i++)cout<<dis[i]<<' ';
	cout<<endl<<"path:"<<endl; //输出路径，因为dijkstra是贪心算法，所以每一步都是最优解 
    for(int i=1;i<=n;i++)cout<<pre[i]<<' ';
}
/*
input:
4 6 1
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4

output:
0 2 4 3
path:
0 1 2 2
*/
```

