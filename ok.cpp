#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main(){
     ios::sync_with_stdio(false);
	cin.tie(NULL);
       int t;
    
    t=1;
 
    while(t--){
  string s;
  int n=s.length();
  int start=0;
  int back=0;
  map<char,int>mp;
  int ans=0;
  while(back<n){
    if(mp.find(s[back])!=mp.end()){
           int len=back-start;
           ans+=((len+1)*len)/2;
        start=mp[s[back]]+1;
        mp.clear();
     
    }
    else{
        mp.insert({s[back],back});
        
    }
    back++;
  }
 int len=back-start;
           ans+=((len+1)*len)/2;
           cout<<ans<<endl;
}
}