//经典的二维线性dp，f[i][j]代表到字符串a第i位和字符串b第j位为止的最优解，对于增删改三种操作取最小值，注意初始化f[0][j]=j！
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int f[2005][2005];
int main(){
    string a,b;
    cin>>a>>b;
    int m=a.length(),n=b.length();
    a=' '+a;
    b=' '+b;
    for(int i=1;i<=m;++i){  //初始化
        f[i][0]=i;
    }
    for(int j=1;j<=n;++j){
        f[0][j]=j;
    }
    
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(a[i]!=b[j]){
                f[i][j]=min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1])+1;//add,delete,change
            }
            else{
                f[i][j]=f[i-1][j-1];
            }
        }
    }
    cout<<f[m][n];
}
