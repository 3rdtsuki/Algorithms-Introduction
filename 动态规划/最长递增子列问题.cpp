/*
https://www.luogu.com.cn/problem/P1020

O(n^2)方法：
求最长递减子列
对每个元素i，找之前的更大元素j
而i是递增查找，因此找到i时i之前的sum已经确定了
所以只需要不断累加，求最大值即可

第二问实质是求最长递增子列
反过来即可

函数：
max_element(a,a+n)：返回数组中最大元素的地址，加*即可返回最大值
*/

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
const int maxn = 200005;
int a[maxn],down[maxn],up[maxn];
int main() {
	int n=0;
	while (cin >> a[n])n++;
	
	for (int i = 0; i < n; ++i) {
		down[i] = 1;
		for (int j = i - 1; j >= 0; --j) {
			if (a[j] >= a[i]) {
				down[i] = max(down[j] + 1, down[i]);
			}
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		up[i] = 1;
		for (int j = i + 1; j < n; ++j) {
			if (a[j] > a[i]) {
				up[i] = max(up[j] + 1, up[i]);
			}
		}
	}
	cout << *max_element(down, down + n) << endl << *max_element(up, up + n);
}
