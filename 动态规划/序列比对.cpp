/*
对于长度相同的2个字符串A和B，其距离定义为相应位置字符距离
之和。2个非空格字符的距离是它们的ASCII码之差的绝对值。空格
与空格的距离为0；空格与其它字符的距离为一定值k。 
在一般情况下，字符串A和B的长度不一定相同。字符串A的扩展是
在A中插入若干空格字符所产生的字符串。在字符串A 和B 的所有
长度相同的扩展中，有一对距离最小的扩展，该距离称为字符串A
和B的扩展距离。 
对于给定的字符串A和B，试设计一个算法，计算其扩展距离。
*/
#include "pch.h"
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define ll long long
#define MAXN 1000
void alignment(string a,string b,int delta){	//最基础的方法，空间复杂度为O(mn) 
	int m=a.length(),n=b.length();
	a=' '+a;
	b=' '+b; 
	int dp[20][20];
	for(int i=0;i<=m;++i){
		dp[i][0]=delta*i;
	}
	for(int j=0;j<=n;++j){
		dp[0][j]=delta*j;
	}
	for(int j=1;j<=n;++j){
		for(int i=1;i<=m;++i){
			int alpha=abs(int(b[j])-int(a[i]));
			dp[i][j]=min(alpha+dp[i-1][j-1],min(dp[i-1][j]+delta,dp[i][j-1]+delta));
		}
	}
	cout<<dp[m][n];
}
int main(){
	string a,b;
	int delta;
	cin>>a>>b>>delta;
	alignment(a,b,delta);
}
/*
cmc 
snmn 
2
output:10
*/
