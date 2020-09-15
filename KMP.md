#### KMP：查找字符串b在a中的位置

```cpp
#include <iostream>
#include <cstring>
using namespace std;
const int N=100;
int nxt[N];

void get_next(char *b){
    nxt[0]=-1;
    int i=0,j=-1;
	int lb=strlen(b);
    while(i<lb){
        if(j==-1||b[i]==b[j]){//初始状态是i=1,j=0，因为nxt[0]无意义
            i++;
            j++;
            nxt[i]=j;//如果各位都相同，不断累加
        }
        else{
            j=nxt[j];
        }
    }
}
int KMP(char *a,char *b){
    int i=0,j=0;//从0开始一个个比对
    int la=strlen(a),lb=strlen(b);
    while(i<la&&j<lb){//注意循环条件里面用strlen会有迷之错误
        if(j==-1||a[i]==b[j]){
            i++;
            j++;
        }
        else{
            j=nxt[j];//回溯
        }
    }
    if(j==lb){
        return i-j;
    }
    else{//如果始终找不到重叠片段,error
        return -1;
    }
}
int main(){
    char a[]={"abababca"},b[]={"bca"};
    get_next(b);
    cout<<"next array:";
    for(int i=0;i<strlen(b);++i){
        cout<<nxt[i]<<' ';
    }
    cout<<endl;
    cout<<KMP(a,b);
}
```

pmt[i]代表a[0:i]这段字符串的前后缀交集中元素的最大长度，注意b的x缀集不包含b本身

假设a[i]之前的一段和b[0:j-1]完全一致，当a[i]!=b[j]时，若pmt[j-1]=4，说明b[0:3]=b[j-4:j-1]，所以**将b[0:3]右移到b[j-4:j-1]的位置来**，再继续检查，实现时为j左移到b[4]处，即j=pmt[j-1]

计算pmt时引入next数组代替，令next[i]=pmt[i-1]，next[0]=-1

计算next数组时，采用和KMP一样的尝试对齐方法



时间复杂度为O(m+n)



##### 注意：

1.KMP的while循环条件里面用strlen会有迷之错误，本用例中会导致j=-1无法进入下一趟循环

2.next是cpp的关键字，所以最好用nxt代替



参考：

> 如何更好地理解和掌握 KMP 算法? - 海纳的回答 - 知乎 https://www.zhihu.com/question/21923021/answer/281346746
