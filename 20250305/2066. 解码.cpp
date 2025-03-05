# include <iostream>
using namespace std;
int main(){
    
    string s;
    cin>>s;
    
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            int t=s[i]-'0';
            for(int j=0;j<t-1;j++) cout<<s[i-1];
        }
        else cout<<s[i];
    }
    
    return 0;
}
