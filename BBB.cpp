#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%2==0){
            cout<<-1<<endl;
            continue;
        }
        else{
            vector<int>ans;
            
            int x=3;
            int num=0;
            if(x==n){
                cout<<1<<endl;
                cout<<2<<endl;
            }
            else{
              while(n>1 &&num<40){
               int y=(n+1)/2;
               int x=(n-1)/2;
               if(y%2==0){
                ans.push_back(2);
                
                n=x;
               }
               else if(x%2==0){
                ans.push_back(1);
                n=y;
               }
               num++;
              }
              if(n!=1){
                cout<<-1<<endl;
                continue;


              }
              reverse(ans.begin(),ans.end());
              cout<<ans.size()<<endl;
              for(auto y:ans){
                //11
                //5
                //2
                //1
                //1 3 5 11
                cout<<y<<" ";
              }
              cout<<endl;
        }
    

 
      }
    }
}
