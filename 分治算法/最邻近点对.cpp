/*这道题是输入n个坐标，找到其中最近的两点距离（的平方）
最烦的就是映射的部分，先把点集按y排序，再把排序的编号结果y_rank对应上所有点，这里用id来标明起始每个点的序号
注意一开始先不按x排序，通过vx[vy[i].id].y_rank=i加上y_rank属性，然后再按照x排序
另外，自己写的cmp函数必须是全局的*/
//#include "pch.h"
#include <iostream>
#include <cstdio>
#include <set>
#include <cmath>
#include <typeinfo>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define ll long long
#define MAXN 1000
struct point{
	double x,y;
	int id;//总编号 
	int y_rank;//分别按照x和y排序的编号 
	point(double x,double y,int id):x(x),y(y),id(id){
		y_rank=0;
	}
	
	static void print(vector<point>v){
		cout<<"打印数组：\n";
		for(int i=0;i<v.size();++i){
			cout<<v[i].x<<' '<<v[i].y<<endl;
		}
	}
}; 
vector<point>vx,vy;//如果函数参数带vector就会超时，所以还是设为全局变量 
bool cmpx(point p1,point p2){
	return p1.x<p2.x;
}
bool cmpy(point p1,point p2){
	return p1.y<p2.y;
}
double get_distance(point p1,point p2){
	return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

double min_distance(int begin,int end){
	int len=end-begin+1;//划分块的长度 
	if(len==1)return MAXN;//需要避免这种情况 
	else if(len==2){		//最重要的就是边界条件，len=2时到底 
		point p1=vx[begin],p2=vx[end];
		//cout<<begin<<','<<end<<','<<get_distance(p1,p2)<<endl;
		return get_distance(p1,p2);
	}
	else{
		int mid=(begin+end)>>1;
		double mid_axis=(vx[mid].x+vx[mid+1].x)/2;//设置中轴线是中间两个点x的平均值 
		double delta=min(min_distance(begin,mid),min_distance(mid,end));
		//注意这里右边一定要从mid开始，否则会忽略横坐标为mid的点！！！ 
		vector<int>gap;//存储窄缝中的点按y排序的序号 
		for(int i=begin;i<=end;++i){//寻找在2delta区间内的点 
			if(vx[i].x>=mid_axis-delta&&vx[i].x<=mid_axis+delta){//如果在窄缝中 
				gap.push_back(vx[i].y_rank);//加入vy中的序号
				
			}
			else if(vx[i].x>mid_axis+delta)break;//去掉后半部分多余，省点时间 
		}
		sort(gap.begin(),gap.end());
		double minn=delta;
		for(int i=0;i<gap.size();++i){
			for(int j=i+1;j<=i+7&&j<gap.size();++j){
				minn=min(minn,get_distance(vy[gap[i]],vy[gap[j]]));
			}
		}
		//cout<<begin<<','<<end<<','<<minn<<endl;
		return minn;
	}
}
int main(){
	int n;
	cin>>n;
	double x,y;
	for(int i=0;i<n;++i){
		scanf("%lf%lf",&x,&y);
		point p(x,y,i);
		vx.push_back(p);
		vy.push_back(p);
	}
	sort(vy.begin(),vy.end(),cmpy);
	for(int i=0;i<n;++i){
		vx[vy[i].id].y_rank=i;//在vx中找到vy中的点，编号为y_rank 
	}
	sort(vx.begin(),vx.end(),cmpx);//注意最后再排序x，否则编号就乱了 
	double d=min_distance(0,n-1);
	printf("%.2lf",d);
}

/*
15
9.83 -81.96
-88.29 44.76
21.97 -81.49
2.44 -1.83
-89.17 63.58
20 -49.92
-81.21 -48.01
-33.28 -49.09
-54.05 12.88
-64.85 -53.12
12.07 64.91
-72.9 -21.57
12.93 -92.71
-27.71 -0.19
73.17 32.17
output:125.17
*/
