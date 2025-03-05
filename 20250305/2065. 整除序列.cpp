# include <iostream>
using namespace std;
const int N=1e18+10;
long long n;
int main(){
    
    cin>>n;
    for(long long i=n;i>=1;i/=2) cout<<i<<" ";
    
    return 0;
}
