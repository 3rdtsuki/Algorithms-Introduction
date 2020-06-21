//本题的三种做法：dp，分治，贪心
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
const int maxn = 200005;
int a[maxn],dp[maxn];
int n;
int fenzhi(int *a,int left,int right){
	//分治的想法是，对于一个数组，从mid开始向两边延伸，不断取最大值 
	if(right==left){
		if(a[left]>=0) 
			return a[left];
		else return 0;
	}
	
	int mid=(left+right)>>1;
	int maxleft=fenzhi(a,left,mid),maxright=fenzhi(a,mid+1,right);
	//分别计算左右两边的最优解 
	
	int sumleft=0,sumright=0;
	//每次延伸的记录 
	int maxnleft=0,maxnright=0;
	//记录sumleft和sumright的最大值 
	for(int i=mid;i>=left;--i){
		sumleft+=a[i];
		maxnleft=max(maxnleft,sumleft);
	}
	for(int i=mid+1;i<=right;++i){
		sumright+=a[i];
		maxnright=max(maxnright,sumright);
	}
	return max(maxnleft+maxnright,max(maxleft,maxright));
	//最优解只有三种可能：仅左边，从mid左右延伸，仅右边，取最大值 
	
}
int greedy(int *a){//贪心，其实与dp差不多
	int now=0,maxn=0;
	for(int i=0;i<n;i++){
		now+=a[i];
		maxn=max(maxn,now);
		if(now<0)now=0;
	}
	return maxn;
}
int main() {
	cin >> n;
	bool allnega=1;//如果输入全部为负，根据题意非空，必须输出最大的负数 
	int maxnega=-maxn;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		dp[i]=max(dp[i-1]+a[i],a[i]);
		//状态转移方程：要么连上前面，要么重新开始 
		//dp[i-1]+a[i]相当于前缀和，这是本题的关键，
		//只要前缀和为正，就一直加下去，直到为负，再从零开始计算前缀和 
		if(a[i]>=0)allnega=0;
		if(allnega==1)maxnega=max(maxnega,a[i]);
	}
	if(allnega==1){
		cout<<maxnega;
		return 0;
	}
	//cout<<*max_element(dp+1,dp+n+1);
	cout<<fenzhi(a,1,n+1); 
}
/*
for example:
4 -1 3
dp[1]=4;
dp[2]=max(4-1,1)=3;
dp[3]=max(3+3,3)=6;
*/ 
