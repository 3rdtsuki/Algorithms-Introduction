//1813055 ’‘ ÈÈ™ 
#include<iostream> 
#include<vector>
#include<cstdio>
#include<stack> 
#include<queue>
#include<map>
#include<ctime>
int a[40][40],b[40][40];
int rb[40][40];//rank a[i]=x -> a[x]=i
int pa[40],pb[40];//now the partner of man i is pa[i]
int fa[40],fb[40];//flag 0=free 1=grouped
int n;
using namespace std;
void printl(int aa[][40]){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;++j){
			cout<<aa[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	} 
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>b[i][j];
			rb[i][b[i][j]]=j;
		}
	} 

	int cnt=n;
	int m=1;
	int w=1;//w represents the w th woman of the man's rank
	while(cnt>0){
		if(fa[m]==1){
			++m;//filter one by one
			continue;
		}
		if(fb[a[m][w]]==0){//the woman is a[m][w]
			fb[a[m][w]]=1;
			fa[m]=1;
			pb[a[m][w]]=m;
			--cnt;
			m=1;
			w=1;
		}
		else{
			if(rb[a[m][w]][m]<rb[a[m][w]][pb[a[m][w]]]){//if m's rank is higher
				fa[pb[a[m][w]]]=0;
				pb[a[m][w]]=m;
				fa[m]=1;
				m=1;
				w=1;
			}
			else{
				++w;//if a[m][w] refused m,then m will go to a[m][++w]
			}
		}
	}
	
	for(int i=1;i<=n;++i){
		cout<<i<<"-----"<<pb[i]<<endl;
		pa[pb[i]]=i;
	}
	for(int i=1;i<=n;++i){
		cout<<pa[i]<<" ";
	}
}
/*
5 
2 1 4 5 3 
4 2 1 3 5
2 5 3 4 1 
1 4 3 2 5
2 4 1 5 3
5 1 2 4 3 
3 2 4 1 5
2 3 4 5 1
1 5 4 3 2
4 2 5 3 1
output:
1 3 2 5 4 
*/

