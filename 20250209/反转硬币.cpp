# include <iostream>
# include <cstring>
using namespace std;

const int N=101;
char target[N],init[N];

void turn(int u){//控制翻转 
	if(init[u]=='*'){
		init[u]='o';
	}
	else init[u]='*';
	
}

int main(){
	
	cin>>init;//读入初始状态 
	cin>>target;//读入目标状态 
	
	int step=0;
	for(int i=0;i<strlen(target);i++){//遍历初始数组和目标数组 
		if(init[i]!=target[i]){//状态不一致 
			step++;//要进行操作，步数加一 
			turn(i),turn(i+1);//进行翻转操作 
		}
	}
	
	cout<<step;
	
	return 0;
}
