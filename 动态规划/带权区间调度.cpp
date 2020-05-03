/*
input：n个事件开始时间、结束时间、权重
output：最大不相容集合，使得权重最大
*/
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <set>
#include<cmath>
#include<typeinfo>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define ll long long
#define MAXN 1000

struct work{
	int start,end,value,id;
	work(){}
	work(int s,int e,int v):start(s),end(e),value(v){}
};
bool cmpx(work a,work b){
	return a.start<b.start;
}
bool cmpy(work a,work b){
	return a.end<b.end;
}

int n;
work *x=new work[MAXN],*y=new work[MAXN];
int *p=new int[MAXN];
int *dp=new int[MAXN];


void print_solution(int i){
	if(i==0)return;
	else if(dp[p[i]]+y[i].value>dp[i-1]){
		cout<<"need"<<y[i].id<<endl;
		print_solution(p[i]);	//如果i属于最优解，接下来直接去找p[i] 
	}
	else print_solution(i-1);
}

int main(){
	cin>>n;
	for(int i=1;i<=n;++i){//因为后面要将第一个work的p设为0，所以最好从1开始编号，否则p[0]=-1.无法代入dp里 
		int start,end,value;
		cin>>start>>end>>value;
		work a(start,end,value);
		y[i]=a;
	}
	
	sort(y+1,y+n+1,cmpy); 
	
	for(int i=0;i<=n;++i){
		y[i].id=i;	//用序列y来给id编号，便于dp部分操作 
		x[i]=y[i];
		p[i]=0;
	}
	sort(x+1,x+n+1,cmpx);
	
	int j=1;
	for(int i=1;i<=n;++i){
		while(y[j].end<=x[i].start){	//因为x是按开始时间排序，所以要用到的是x.start
						//如果x[i].start>=y[j].end，那么y[j]可能是p[x[i]] 
						//因为还不确定x[i]就是p[y[j]]，所以用一个while循环求出最终结果 
			p[x[i+1].id]=p[x[i].id]=y[j].id;//***只要x1<x2，那么p[x2]>=p[x1]，所以p[x2]初始化为p[x1]，避免出现p[x2]踏空的情况 
			j++; //继续找更靠后的y[j] 
		}
	}
	cout<<"p:"<<endl;
	for(int i=1;i<=n;++i){
		cout<<"p["<<i<<"]="<<p[i]<<endl;
	}
	
	dp[0]=0;
	for(int i=1;i<=n;++i){
		dp[i]=max(dp[p[i]]+y[i].value,dp[i-1]);	//状态转移方程：要么加入事件j，要么不加入
	}
	cout<<"最大和："<<dp[n]<<endl;
	cout<<"dp:"<<endl;
	for(int i=1;i<=n;++i)cout<<"dp["<<i<<"]="<<dp[i]<<endl;
	cout<<"print_solution:"<<endl;
	print_solution(n);
}

/*
6
0 4 2
1 6 4
5 7 4
2 9 7
8 10 2
8 11 1
*/
/*output:
p:
p[1]=0
p[2]=0
p[3]=1
p[4]=0
p[5]=3
p[6]=3
最大和：8
dp:
dp[1]=2
dp[2]=4
dp[3]=6
dp[4]=7
dp[5]=8
dp[6]=8
print_solution:
need5
need3
need1
*/
