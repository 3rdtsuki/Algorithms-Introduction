#include <iostream> 
#include <vector> 
#include <queue>
using namespace std;
struct classroom{
    int num;
    float last_time;
    vector<int>lesson;
    classroom(){
        num=0;
        last_time=0;
    }
    classroom(int num,float last_time):num(num),last_time(last_time){
        
    }
    bool operator<(const classroom &c)const{
        return last_time>c.last_time;
    }
};
int main(){
	int n=10;
	float s[10]={9,9,9,11,11,13,13,14,15,15};
	float f[10]={10.5,12.5,10.5,12.5,14,14.5,14.5,16.5,16.5,16.5};
	priority_queue<classroom>q;
	classroom c(1,9);
	q.push(c);
	int cnt=1;
	
	for(int i=0;i<n;++i){
	    classroom earlist=q.top();
	    if(earlist.last_time<=s[i]){
	        q.pop();
	        earlist.last_time=f[i];
	        earlist.lesson.push_back(i);
	        q.push(earlist);
	    }
	    else{//最早的教室不空闲，加一间教室
	        classroom c(++cnt,f[i]);
	        c.lesson.push_back(i);
	        q.push(c);
	    }
	}
	cout<<cnt<<endl;
	while(!q.empty()){
	    classroom c=q.top();
	    q.pop();
	    cout<<c.num<<":";
	    for(int i=0;i<c.lesson.size();++i){
	        cout<<(char)(97+c.lesson[i])<<' ';
	    }
	    cout<<endl;
	}
}
/*
3
3:c e h 
2:b f i 
1:a d g j 
*/
