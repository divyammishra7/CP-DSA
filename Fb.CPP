#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include<bits/stdc++.h>

#define int long long int
using namespace std;
 
#define inf 2e18
#define ll int
 const int M=1e9+7;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define DIV                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
const ll mod = 1e9 + 7;
const int MOD=1e9+7;
 
vector<ll> sieve(int n)
{
    int *arr = new int[n + 1]();
    vector<ll> vect;
    for (int i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.push_back(i);
            for (int j = 2 * i; j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}
 
 int inverse(int i){
    if(i==1) return 1;
    return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}
 
ll mod_mul(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}
 
ll mod_add(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a + b) % mod) + mod) % mod;
}
 
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }
 
ll pwr(ll a, ll b)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
bool isPrime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0)  return false;
    }
    return true;
}
bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
 
}
 
 
bool cmp1(pair<int,int>a,pair<int,int>b){
    return a.first<b.first;
}
 int sumXOR(vector<int>arr, int n)
{
     int sum = 0;
    for (int i = 0; i < 32; i++)
    {
        //  Count of zeros and ones
        int zc = 0, oc = 0;
         
        // Individual sum at each bit position
         int idsum = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] % 2 == 0)
                zc++;
            else
                oc++;
            arr[j] /= 2;
        }
         
        // calculating individual bit sum
        idsum = oc * zc * (1 << i);
 
        // final sum   
        sum += idsum;
    }
    return sum;
}
// int give(vector<int>arr){
//     int n=arr.size();
//     int count=0;
//     bool flag=false;
//     int ans=0;
//     for(int i=0; i<n; i++){
//         if(arr[i]==1){
//             flag=true;
//         }
//         else if(flag && arr[i]==0){
//             ans++;
//         }
//     }
//     return ans;
// }
vector<int>get(int K,vector<vector<int>>q,int M){
    vector<int>count(M);
     for (int i = 0; i < K; ++i) {
 
        int l = q[i][0], r = q[i][1] + 1;
 
        // Making it to 0-indexing
        l--;
        r--;
 
        // Prefix sum array concept is used
        // to obtain the count array
        count[l]++;
 
        if (r < M)
            count[r]--;
    }
 
    // Iterating over the count array
    // to get the final array
    for (int i = 1; i < M; ++i) {
        count[i] += count[i - 1];
    }
 return count;
}
const int val=1e6+3;
int  MODpower(int x, int put)
{
	int s=1;
	while (put>0)
	{
		s*=2;
		s%=val;
		put--;
	}
	return s;
}
bool cmpD(pair<int,int>a,pair<int,int>b){
 
            return a.second<b.second;
}
 
int f(vector<int>arr,int i,int j,int index){
    if(i>j){
        return 0;
    }
    int first=0;
    int second=0;
    if(index%2==0){
    first=arr[i]+f(arr,i+1,j,index+1);
     second=arr[j]+f(arr,i,j-1,index+1);
    }
    else {
   if(arr[j]>arr[i]){
    return 0+f(arr,i,j-1,index+1);
   }
   else{
    if(arr[i]>arr[j]){
        return 0+f(arr,i+1,j,index+1);
    }
   }
    }
    return max(first,second);
 
}
int last(int low,int high,vector<int>arr,int k){
    int ans=-1;
    while(low<=high){
 
        int mid=low+(high-low)/2;
        if(arr[mid]<=k){
            ans=mid;
            low=mid+1;
            
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
 
// bool f(vector<int>arr,int target,int index,vector<int>temp){
//     if(target==0){
//     ans=temp;
//     return true;
//     }
//     if(index==0){
     
//           if(target%arr[0]==0){
//            int y=target/arr[0];
//            for(int i=0; i<y; i++){
//             temp.push_back(arr[0]);
//            }
//             ans=temp;
//             return true;
//           }
        
        
//         return false;
//     }
//     bool nottake=f(arr,target,index-1,temp);
//     bool take= false;
//     if(target>=arr[index]){
//         temp.push_back(arr[index]);
//         take=f(arr,target-arr[index],index,temp);
    
 
//     }
//     return take|nottake;
// }
 
 
bool check(string s,string temp,string dup,int index){
    if(dup==temp){
        return true;
    }
    if(index==0){
           if(dup==temp){
        return true;
    }
    dup+=s[0];
    if(dup==temp){
        return true;
    }
    return false;
 
    }
    bool nottake=check(s,temp,dup,index-1);
    bool take=check(s,temp,dup+s[index],index-1);
    return take|nottake;
}
 
void give(vector<vector<char>>v,int index,string temp,string s,int m,bool &flag){
    if(temp.length()==m){
       
        if(check(s,temp,"",s.length()-1)==false){
            flag=true;
            
            
        }
        return;
    }
    if(index==v.size()){
        return;
    }
   if(temp.length()>m){
    return;
   }
    
    vector<char>to=v[index];
    for(int i=to[0]-'0'; i<=to[1]-'0'; i++){
 
 
 char ch=i+'0';
 
 
 if(temp.length()<m){
   
         temp+=ch;
         cout<<temp<<endl;
      
        give(v,index+1,temp,s,m,flag);
        temp.pop_back();
        give(v,index+1,temp,s,m,flag);
 }
    }
 
 
}
 
void solve(vector<int> a,int n, int k, int index, int sum,int maxsum,int &ans)
{
    // K=1 is the base Case
    if (k == 1) {
        maxsum = max(maxsum, sum);
        sum = 0;
        for (int i = index; i < n; i++) {
            sum += a[i];
        }
        // we update maxsum
        maxsum = max(maxsum, sum);
        // the answer is stored in ans
        ans = min(ans, maxsum);
        return;
    }
    sum = 0;
    // using for loop to divide the array into K-subarray
    for (int i = index; i < n; i++) {
        sum += a[i];
        // for each subarray we calculate sum ans update
        // maxsum
        maxsum = max(maxsum, sum);
        // calling function again
        solve(a, n, k - 1, i + 1, sum, maxsum,ans);
    }
}
// bool checkP(int power,int k,int n){
//     int low=2;
//     int high=;
//     bool flag1=false;
//     while(low<=high){
//         int mid=low+(high-low)/2;
//         int x=pow(k,mid);
        
        
//         if(x==power){
//             cout<<k<<" "<<mid<<endl;
//             cout<<x<<endl;
//             flag1=true;
//             break;
//         }
//         else if(x<power){
 
//             low=mid+1;
//         }
//         else{
//             high=mid-1;
//         }
//     }
//     return flag1==true;
// }
bool cmpdiv(pair<int,int>a,pair<int,int>b){
    if(a.first!=b.first){
        return a.first<b.first;
    }
    return a.second>b.second;
}
map<long, long> Fx;
map<long,long>Fy;
long fx(long n) {
	if (Fx.count(n)) return Fx[n];
	long k=n/2;
	// if (n%2==0) { // n=2*k
	// 	return Fx[n] = (fx(k)*fx(k) + fx(k-1)*fx(k-1)) % M;
	// } else { // n=2*k+1
	// 	return Fx[n] = (fx(k)*fx(k+1) + fx(k-1)*fx(k)) % M;
	// }
      return Fx[n]=fx(n-1)+fx(n-2);
}
long fy(long n) {
	if (Fy.count(n)) return Fy[n];
	long k=n/2;
	// if (n%2==0) { // n=2*k
	// 	return Fy[n] = (fy(k)*fy(k) + fy(k-1)*fy(k-1)) % M;
	// } else { // n=2*k+1
	// 	return Fy[n] = (fy(k)*fy(k+1) + fy(k-1)*fy(k)) % M;
	// }
    return Fy[n]=fy(n-1)+fy(n-2);
}

int findNthNumber(int A, int B, int N)
{
    if(N==0){
        return A;
    }
    if(N==1){
        return B;
    }
 
    // To store the current element which
    // is the sum of previous two
    // elements of the series
    int sum = 0;
 
    // This loop will terminate when
    // the Nth element is found
    for (int i = 2; i <= N; i++) {
        sum = A + B;
 
        A = B;
 
        B = sum;
    }
 
    // Return the Nth element
    return sum;
}
 

signed main() {
    DIV;
    int t;
    
    
 cin>>t;
    while(t--){
cout<<""

  
}
     
  }
