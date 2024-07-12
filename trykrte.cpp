    //JAI SHREE RAM HAR HAR MAHADEV
    
    #pragma GCC optimize("Ofast")
    #pragma GCC target("avx,avx2,fma")
    #pragma GCC optimization("unroll-loops")
    #include<bits/stdc++.h>
    #define int long long int
    #define debug(arr)for(auto x:arr){cout<<x<<" ";}cout<<endl;
    #define all(arr)arr.begin(),arr.end()
    #define input(arr,n)for(int i=0; i<n; i++){cin>>arr[i];}
    #define pb push_back
const int  MOD = 1e9 + 7, MAX = 1e6 ;
    using namespace std;
    

    void primeFactors(int n,vector<int>&primes)
    {
        // Print the number of 2s that divide n
        while (n % 2 == 0)
        {
            
            primes.push_back(2);
            n = n/2;
        }
    
        // n must be odd at this point. So we can skip
        // one element (Note i = i +2)
        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            // While i divides n, print i and divide n
            while (n % i == 0)
            {
            
                primes.push_back(i);
                n = n/i;
            }
        }
    
        // This condition is to handle the case when n
        // is a prime number greater than 2
        if (n > 2){
            primes.push_back(n);
        }
            
    }
    void SieveOfEratosthenes(int n,vector<bool>&prime)
    {
        // Create a boolean array "prime[0..n]" and initialize
        // all entries it as true. A value in prime[i] will
        // finally be false if i is Not a prime, else true.
    
    
    
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
    
    }
    
    int sumOfDigits(int a)
    {
        int sum = 1;
        while (a)
        {
            sum *= a % 10;
            a /= 10;
        }
        return sum;
    }
    
    // Returns the maximum number
    // with maximum sum of digits.


        vector<int> topoSort(int V, vector<int> adj[],vector<int>&vis,vector<int>&indegree) 
        {
        
            queue<int>q;
            for(int i=1; i<=V;i++){
                if(indegree[i]==0 && vis[i]==1){
                    q.push(i);
                }
            }
            vector<int>ans;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                if(node==1){
                    break;
                }
                ans.push_back(node);
            
                for(auto x:adj[node]){
                    indegree[x]--;
                    if(indegree[x]==0 && vis[x]==1 ){
                        q.push(x);
                    }
                }
            }
            // code here
        return ans;
        }
    
 
    void modidfy(int n,vector<int>&primes){
        for(int i=1; i<=n; i++){
            primes[i]=i;
            }
            for(int i=2; i*i<=n; i++){
                if(primes[i]-i==0){
                    for(int j=i*i; j<=n; j+=i){
                        primes[j]=i;
                    }
                }
            }
        }

 
    int Gx;
    int Gy;

   
    
    // Function to generate prime factors and its power
 


    bool isvalid(long double mid,int ax,int ay,int bx,int by,int px,int py){
    long double distA=sqrt((ax*ax)+(ay*ay));
    long double distB=sqrt((bx*bx)+(by*by));
    long double distAP=sqrt((ax-px)*(ax-px)+(ay-py)*(ay-py));
        long double distBP=sqrt((bx-px)*(bx-px)+(by-py)*(by-py));

    long double disAB=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
    if(distAP<=mid && distA<=mid){

        
        
        return true;
    }
    else if(distB<=mid && distBP<=mid){
        
        return true;

    }
    else if(distA<=mid && distBP<=mid && disAB<=2.0*mid ){
        return true;
    }
    else if(distB<=mid && distAP<=mid && disAB<=2.0*mid){return true;}
    return false;
    }
 
    bool isPowerOfTwo(int n)
    {
        if (n == 0)
            return false;
    
        return (ceil(log2(n)) == floor(log2(n)));
    }
    int sumOfD(int x){
    int sum=0;
    while(x>0){
        sum+=(x%10);
        x=x/10;
    }
    return sum;
    }
    int powerr(int a,int b){int res = 1;while(b){if(b&1) res *= a;a *= a;
    b >>= 1;}return res;}
    string getSubSeq(string s, int n,set<int>&st)
    {
        string res = "";
        int cr = 0;
        while (cr < n) {
    
            // Get the max character from the string
            char mx = s[cr];
            for (int i = cr + 1; i < n; i++)
                mx = max(mx, s[i]);
            int lst = cr;
    
            // Use all the occurrences of the
            // current maximum character
            for (int i = cr; i < n; i++)
                if (s[i] == mx) {
                    res += s[i];
                    st.insert(i);
                    lst = i;
                }
    
            // Repeat the steps for the remaining string
            cr = lst + 1;
        }
        return res;
    }
 
    int floorSqrt(int x)
    {
        // Base cases
        if (x == 0 || x == 1)
            return x;
    
        // Starting from 1, try all numbers until
        // i*i is greater than or equal to x.
        int i = 1, result = 1;
        while (result <= x) {
            i++;
            result = i * i;
        }
        return i - 1;
    }
    


    bool isKthBitSet(int n, int k)
    {
        if (n & (1ll*1 << k)){
            return true;
        }
        
            return false;
    }
  
     int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
// Returns LCM of array elements
int findlcm(vector<int>arr, int n)
{
    // Initialize result
    int ans = arr[0];
 
    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
                (gcd(arr[i], ans)));
 
    return ans;
}


void SieveOfEratosthenes(vector<bool>&prime,vector<int>&ans)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    int n=prime.size();

 prime[1]=false;
 
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
           
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i<=n; i += p)
                prime[i] = false;
        }
    }
   for(int i=1; i<n; i++){
    if(prime[i]){
        ans.push_back(i);
    }

   }
 
    // Print all prime numbers

}
 
int64_t ceil_div(int64_t a, int64_t b) {
    return (a + b - 1) / b;
}
 


unsigned int onesComplement(unsigned int n)
{
    // Find number of bits in the given integer
    int number_of_bits = floor(log2(n)) + 1;
 
    // XOR the given integer with pow(2,number_of_bits-1)
    // and print the result
    return ((1 << number_of_bits) - 1) ^ n;
}

 

void computeLPSArray(string pat, int M, int lps[])
{
 
    // Length of the previous longest
    // prefix suffix
    int len = 0;
    int i = 1;
    lps[0] = 0; // lps[0] is always 0
 
    // The loop calculates lps[i] for
    // i = 1 to M-1
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
 
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];
 
                // Also, note that we do not
                // increment i here
            }
            else // if (len == 0)
            {
                lps[i] = len;
                i++;
            }
        }
    }
}
 
int KMPSearch(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();
 
    // Create lps[] that will hold the longest
    // prefix suffix values for pattern
    int lps[M];
    int j = 0; // index for pat[]
 
    // Preprocess the pattern (calculate lps[]
    // array)
    computeLPSArray(pat, M, lps);
 
    int i = 0; // index for txt[]
    int res = 0;
    int next_i = 0;
 
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
 
            // When we find pattern first time,
            // we iterate again to check if there
            // exists more pattern
            j = lps[j - 1];
            res++;
        }
 
        // Mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
 
            // Do not match lps[0..lps[j-1]]
            // characters, they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return res;
}


 


  
// Returns (a * b) % mod 
long long moduloMultiplication(long long a, long long b, 
                               long long mod) 
{ 
    long long res = 0; // Initialize result 
  
    // Update a if it is more than 
    // or equal to mod 
    a %= mod; 
  
    while (b) { 
        // If b is odd, add a with result 
        if (b & 1) 
            res = (res + a) % mod; 
  
        // Here we assume that doing 2*a 
        // doesn't cause overflow 
        a = (2 * a) % mod; 
  
        b >>= 1; // b = b / 2 
    } 
  
    return res; 
} 
int maxSubArraySum(vector<int>a){
    int size=a.size();
    int max_so_far = 0, max_ending_here = 0;
 
    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
//------------------------------SEGMENT TREE--------------------------------------------
//-------------------------------------------------------------------------------------------------------------------
void build(vector<int>&segTree,vector<int>&arr,int tidx,int start,int end){
    //base case
    
    if(start==end){
        segTree[tidx]=arr[start];
        return ;
    }
    int mid=start+(end-start)/2;
    build(segTree,arr,2*tidx,start,mid);
    build(segTree,arr,(2*tidx)+1,mid+1,end);
    segTree[tidx]=segTree[2*tidx]^segTree[(2*tidx)+1];


}
void update(vector<int>&segTree,int tidx,int start,int end,int l,int r,int val){
if(start==l && end==r){
    segTree[tidx]+=val*(r-l+1);
    return;
}
int mid=start+(end-start)/2;
if(l<=mid){
    update(segTree,2*tidx,start,mid,l,r,val);
}
else{
    update(segTree,(2*tidx)+1,mid+1,end,l,r,val);
}
segTree[tidx]=segTree[2*tidx]+segTree[(2*tidx)+1];


}
//Query
int query(vector<int>&segTree,int tidx,int start,int end,int l,int r){
    if(start>=l && end<=r){
        return segTree[tidx];
    }
    if(start>r || end<l){
        return 0;
        
    }
    int mid=start+(end-start)/2;

    int left_ans=query(segTree,2*tidx,start,mid,l,r);
    int right_ans=query(segTree,(2*tidx)+1,mid+1,end,l,r);
    return left_ans^right_ans;
}
//-------------------------------------------------------------------------------------------------------------------



// element of subarray of size K 


int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
int powerMOD(int a, int b)
{
    a %= MOD;
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
vector<bool> Primes(MAX, 1);
int fact[MAX + 1];
void fac()
{
    fact[0] = 1;
    for (int i = 1; i <= MAX; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
}
int inverse(int n) { return powerMOD(n, MOD - 2); } 
int ncr(int n, int r) { return (fact[n] * inverse(fact[r] * fact[n - r])) % MOD; }
int npr(int n, int r) { return fact[n] * inverse(fact[n - r]); }

int CountTrailingZeros(int n)
{
    // declare bitset of 64 bits
    bitset<64> bit;
 
    // set bitset with the value
    bit |= n;
 
    int zero = 0;
 
    for (int i = 0; i < 64; i++) {
        if (bit[i] == 0)
            zero++;
        // if '1' comes then break
        else
            break;
    }
 
    return zero;
}
 

int findlcmm(vector<int>&arr, int n)
{
    // Initialize result
    int  ans = arr[0];
 
    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
                (gcd(arr[i], ans)));
 
    return ans;
}

void reverse(vector<int>& arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to left rotate array elements by d positions
void leftRotate(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n; // To handle case when d >= n
    
    // Reverse the first d elements
    reverse(arr, 0, d - 1);
    // Reverse the remaining elements
    reverse(arr, d, n - 1);
    // Reverse the whole array
    reverse(arr, 0, n - 1);
}

string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
 
        // Calculate carry for next step
        carry = sum/10;
    }
 
    // Add remaining digits of larger number
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}
int sumOfDigitsString(string s){
    int sum=0;
    for(auto x:s){
        sum+=(x-'0');
    }
    return sum;
}

bool isOperator(char c)
{
    // Returns true if the character is an operator
    return c == '+' || c == '-' || c == '*' || c == '/'
           || c == '^';
}

// Function to get the precedence of an operator
int precedence(char op)
{
    // Returns the precedence of the operator
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Function to apply an operator to two operands
double applyOp(double a, double b, char op)
{
    // Applies the operator to the operands and returns the
    // result
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
        return pow(a, b);
    default:
        return 0;
    }
}

// Function to parse and evaluate a mathematical expression
double evaluateExpression(const string& expression)
{
    stack<char> operators; // Stack to hold operators
    stack<double> operands; // Stack to hold operands

    stringstream ss(expression); // String stream to parse
                                 // the expression

    string token;
    while (getline(
        ss, token,
        ' ')) { // Parse the expression token by token
        if (token.empty())
            continue; // Skip empty tokens
        if (isdigit(token[0])) { // If the token is a number
            double num;
            stringstream(token)
                >> num; // Convert the token to a number
            operands.push(num); // Push the number onto the
                                // operand stack
        }
        else if (isOperator(token[0])) { // If the token is
                                         // an operator
            char op = token[0];
            // While the operator stack is not empty and the
            // top operator has equal or higher precedence
            while (!operators.empty()
                   && precedence(operators.top())
                          >= precedence(op)) {
                // Pop two operands and one operator
                double b = operands.top();
                operands.pop();
                double a = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                // Apply the operator to the operands and
                // push the result onto the operand stack
                operands.push(applyOp(a, b, op));
            }
            // Push the current operator onto the operator
            // stack
            operators.push(op);
        }
        else if (token[0] == '(') { // If the token is an
                                    // opening parenthesis
            // Push it onto the operator stack
            operators.push('(');
        }
        else if (token[0] == ')') { // If the token is a
                                    // closing parenthesis
            // While the operator stack is not empty and the
            // top operator is not an opening parenthesis
            while (!operators.empty()
                   && operators.top() != '(') {
                // Pop two operands and one operator
                double b = operands.top();
                operands.pop();
                double a = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                // Apply the operator to the operands and
                // push the result onto the operand stack
                operands.push(applyOp(a, b, op));
            }
            // Pop the opening parenthesis
            operators.pop();
        }
    }

    // While the operator stack is not empty
    while (!operators.empty()) {
        // Pop two operands and one operator
        double b = operands.top();
        operands.pop();
        double a = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        // Apply the operator to the operands and push the
        // result onto the operand stack
        operands.push(applyOp(a, b, op));
    }

    // The result is at the top of the operand stack
    return operands.top();
}

int lcs(string X, string Y, int m, int n)
{

    // Initializing a matrix of size
    // (m+1)*(n+1)
    int L[m + 1][n + 1];

    // Following steps build L[m+1][n+1]
    // in bottom up fashion. Note that
    // L[i][j] contains length of LCS of
    // X[0..i-1] and Y[0..j-1]
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    // L[m][n] contains length of LCS
    // for X[0..n-1] and Y[0..m-1]
    return L[m][n];
}
bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.second==b.second){
        return a.first<b.first;
    }
return a.second<b.second;
}
vector<int>temp;
int f(int index,vector<int>&arr,vector<int>&dp){
    if(index>=arr.size()){
        return 0;
    }
  
  if(dp[index]!=-1){
    return dp[index];
  }
    int take=0;
    if(temp.size()==0 || (temp.size()>0 && gcd(temp.back(),arr[index])>1 && arr[index]>temp.back())){
        temp.pb(arr[index]);
        take=1+f(index+1,arr,dp);
        temp.pop_back();
    }
    int nottake=f(index+1,arr,dp);

    return dp[index]=max(take,nottake);
}
bool check(int mid,string s,vector<int>&pref,vector<int>&suff){
    int gzero=0;
    for(auto x:s){
        if(x=='0'){
            gzero++;
        }
    }

    for(int i=0; i<=mid; i++){
        int oneaage=i;
        int onepiche=mid-i;
        int zerokitneaagese=pref[oneaage];
        int zerokitnepichese=suff[onepiche];
        int total=zerokitneaagese+zerokitnepichese;
        int bache=gzero-total;
        if(bache<=mid){
            return true;
        }
    }
    
return false;
}
    signed main(){


    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    



        int t;
    cin>>t;

        int in=0;
    // calculate prefix bits
//        vector<vector<int>>bitt(2e5+5,vector<int>(32,0));

//    for(int i=1; i<=2e5; i++){
//     string s = bitset<32>(i).to_string();
//     vector<int>pref(32,0);
//     for(int j=0; j<32; j++){
//         if(s[j]=='1'){
//             pref[j]=1;
//         }
//         else{
//             pref[j]=0;
//         }
//     }
//     for(int j=0; j<32; j++){
//         bitt[i][j]=bitt[i-1][j]+pref[j];
//     }

//    }
// fac();
while(t--){
int n,m,k;
cin>>n>>m>>k;
string s(n+1,'#');
for(int i=1; i<=n; i++){
    cin>>s[i];
}
set<int>croc;
set<int>logs;
bool ff=true;
set<int>water;
for(int i=1; i<=n; i++){
    if(s[i]=='L'){
        logs.insert(i);
    }
    else if(s[i]=='C'){
        croc.insert(i);
    }
    else if(s[i]=='W'){
        water.insert(i);
        
            }
}
int curr=0;
while(curr<=n){
    // cout<<k<<" "<<curr<<endl;
   
    int index=-1;
    int index2=curr+1;

    if(curr==0){
        if(curr+m>=n+1){
            ff=true;
            break;
        }
        for(int j=curr+m; j>=index2; j--){
            if(s[j]=='L'){
                index=j;
                break;

            }

        }
        if(index==-1){
               for(int j=curr+m; j>=index2; j--){
            if(s[j]=='W'){
           
                index=j;
                break;

            }

        }
        }
        if(index==-1){
            ff=false;
            break;

        }
        curr=index;
        continue;
      
    }
 else if(s[curr]=='L'){
      if(curr+m>=n+1){
            
            ff=true;
            break;
        }
 for(int j=curr+m; j>=index2; j--){
            if(s[j]=='L'){
                index=j;
                break;

            }

 }
        if(index==-1){
         for(int j=curr+m; j>=index2; j--){
            if(s[j]=='W'){
                index=j;
                break;

            }

         }
        }
        if(index==-1){
            ff=false;
            break;

        }
        curr=index;
 }
 
        
    
    else if(s[curr]=='W'){
        // cout<<curr<<endl;
     if(curr==n){
        if(curr+k>=n+1){
            ff=true;

            break;
        }
     }
     auto it=logs.lower_bound(curr);
    //  cout<<*it<<endl;
   
     if(it==logs.end()){
      
        auto it=water.lower_bound(curr+1);
        if(it==water.end()){
            ff=false;
            break;
        }
        if(*it-curr>k){
          
ff=false;
break;

        }
     
        auto it2=croc.lower_bound(curr);
        // cout<<*it2<<endl;
        if(it2!=croc.end()&&*it2<*it){
            ff=false;
            break;
        }
        k-=(*it-curr);
        curr=*it;
         
     }
     else{
         auto it2=croc.lower_bound(curr);
        // cout<<*it2<<endl;
        if(it2!=croc.end()&&*it2<*it){
            ff=false;
            break;
        }
        k-=(*it-curr);
        curr=*it;
        if(*it-curr>k){
            ff=false;
            break;
        }
        else{
            k-=(*it-curr);
            curr=*it;


        }
     }

    }
    else{
        ff=false;
        break;
    }

}
if(ff){
    cout<<"YES"<<endl;

}
else{
    cout<<"NO"<<endl;
}
   in++;
   
   
    }










 
   



 
 

        }






 


        

    

    
    


// 3 2 6 4 5 12 7 8 9 10 11 1
    
    
        
        

        