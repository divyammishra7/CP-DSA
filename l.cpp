#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int k;
		cin>>k;

		vector<int>arr(n);
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		bool flag=false;
		for(auto x:arr){
			if(x==k){
				flag=true;
				break;
			}
		}
		if(flag){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	   




	}
	return 0;
}
