### 链表存储图（邻接表）  

数据结构的关键是每次把新的点插到head和head->firstarc之间，而不是插到尾部，那样时间复杂度和代码量都会很大（需要一个now指针往后找）

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
const int maxn = 2005;
int n,m,a,b,w;

struct edgenode{	//边节点，顾名思义是头结点后面的节点，需要num作为索引
    int num;
    edgenode *next;
};
struct headnode{	//头结点，只有一个属性firstarc，代表它的next，索引就是数组下标
    edgenode *firstarc;
};

headnode *h=new headnode[n+1];	//事先准备好n个头结点
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        h[i].firstarc=NULL;	//初始化next=NULL
    }
    for(int i=1;i<=m;++i){
        cin>>a>>b>>w;
        edgenode *e=new edgenode;
        e->num=b;
        e->next=h[a].firstarc;	
        //very important! 每次把新的点插到head和head->firstarc之间！！！ 
        //这里不用考虑第一次插入的情况，因为e->next自动指向NULL了
        h[a].firstarc=e;	//把h[a].firstarc指向新节点
    }
    /*
    //输出方法1，用while
    for(int i=1;i<=n;++i){
    	edgenode *p=h[i].firstarc;
	    cout<<i;
	    while(p){
	    	cout<<"->"<<p->num;
	    	p=p->next;
    	}
    	cout<<endl;
    }
    */ 
    //输出方法2，用for
    edgenode *p;
    for(int i=1;i<=n;++i){
    	cout<<i;
        for(p=h[i].firstarc;p;p=p->next){
            cout<<"->"<<p->num;
        }
        cout<<endl;
    }
}
/*
4 5
4 2 30
4 3 20
2 3 20
2 1 30
1 3 40

output:
1->3
2->1->3
3
4->3->2
*/
```

### dfs(start,end)：输出从start到end的所有路径  

```cpp
bool flag[200];//记录是否访问过
int path[200];//路径
int cnt=0;//非常重要的计数器
 
void dfs(int start,int end){
	path[cnt]=start;//一开始就加入start，方便输出
	if(start==end){
		for(int i=0;i<=cnt;++i){
			cout<<path[i]<<" ";
		}
		cout<<endl;
		return;
	}
	for(edgenode *p=h[start].firstarc;p;p=p->next){
		if(flag[p->num]==0){
			flag[p->num]=1;
			cnt++;	
			dfs(p->num,end);
			cnt--;	//回溯时将这一趟的计数器递减为分叉点时的值 
			flag[p->num]=0;//回溯，输出多种情况
		}
	}
}
```

计数器cnt非常有用，本题从4到3有三种方案：

```
4 3
4 2 1 3
4 2 3
```

如果每次都将path输出后清空，就会出现一种bug： 

```
4 3
2 1 3
3
```

这是因为每次全部清空，2 1 3之前的4 和 3之前的4 2没有保留（从4和2开始分叉形成树，树根没有保留）  

解决方法是回溯的时候将之前循环内的树枝贡献的计数减回去
