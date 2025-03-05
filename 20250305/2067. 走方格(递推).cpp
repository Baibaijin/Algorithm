# include <iostream>
using namespace std;
const int N=35;
int a[N][N];
int n,m;
int res=0;
//bool st[N][N];
void action(int x,int y){

    if(x>n||y>m) return;
    
    if(x==n&&y==m){
        res++;
    }
    
    if(!((x+1)%2==0 && y%2==0)){
        action(x+1,y);
    }

    if(!((y+1)%2==0 && x%2==0)){
        action(x,y+1);
    }
    
}

int main(){
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    
    action(1,1);
    
    cout<<res;
    
    return 0;
}
