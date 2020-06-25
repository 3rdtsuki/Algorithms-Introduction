### 经典的快排（注意交换细节）
https://www.luogu.com.cn/problem/P1177  
快排的精髓是以一个数为枢纽，比它大的元素放后面，小的放前面，通过和枢纽交换来实现  
例如：以a[mid]=2为枢纽的第一趟排序  
4 2 1 3 //a[j]=1  
4 1 2 3 //a[i]=4  
2 1 4 3  
1 2 4 3  
```cpp
#include <iostream>
using namespace std;
int a[100005];
void quicksort(int l,int r){
    if(l>=r)return;
    int i=l,j=r;
    int mid=(l+r)>>1;
    int key=a[mid];
    while(i<j){
        while(mid<j&&a[j]>=key){ //注意j>mid
            j--;
        }
        swap(a[j],a[mid]); //把小元素换到前面
        mid=j; //更新key所在的位置
        while(i<mid&&a[i]<=key){ //i<mid
            i++;
        }
        swap(a[i],a[mid]);
        mid=i;
    }
    quicksort(l,mid-1);
    quicksort(mid+1,r);
}
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
	    cin>>a[i];
	}
	quicksort(0,n-1);
	for(int i=0;i<n;++i){
	    cout<<a[i]<<' ';
	}
	return 0;
}
```
