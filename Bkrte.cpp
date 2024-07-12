#include<bits/stdc++.h>
#define int long long int
using namespace std;
vector<bool>SieveOfEratosthenes(int n)
{
    vector<bool>prime(n+1,true);

  
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
  
    // Print all prime numbers
  return prime;
}
signed main(){

int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<bool>prime=SieveOfEratosthenes(n);
    vector<int>arr(n);
   
   if(n==2){
    cout<<2<<" "<<1<<endl;
    continue;
   }
   // 2 5 1 4  3
 if(n==1){
    cout<<1<<endl;
    continue;
 }
 arr[0]=2;
 
 arr[n-1]=3;
 arr[n/2]=1;
 int c=4;
 int o=4;
 bool flag=true;
 for(int i=n-2; i>0; i--){
  if(i==n/2  && flag==true){
    continue;

  }
    arr[i]=o;
    o++;
 }
  
 for(auto x:arr){
    cout<<x<<" ";
 }
   
    
    cout<<endl;
}
}
