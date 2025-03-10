# include <iostream>
using namespace std;

const int N=1100;
int a[N][N];
int b[N][N];
int c[N][N];

int main(){
    
    int n,q;
    cin>>n>>q;
    int res=0;
    while(q--){
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y]++;
        b[x][z]++;
        c[y][z]++;
        if(a[x][y]>=n) res++;
        if(b[x][z]>=n) res++;
        if(c[y][z]>=n) res++;
        cout<<res<<'\n';
    }
    
    return 0;
}
