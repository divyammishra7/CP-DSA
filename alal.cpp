#include<bits/stdc++.h>
using namespace std;

   int f(vector<int>&nums,int index,int target){
    
    if(index==nums.size()-1){
        return 0;
    }
    int ans=-2;
    for(int i=index+1; i<nums.size(); i++){
        if(abs(nums[i]-nums[index])<=target){
            ans=max(ans,1+f(nums,i,target));
        }

    }
    return ans;

}
int countSubstrings(string binaryString, int x) {
    int count = 0;
    int onesCount = 0;
    int n = binaryString.length();

    int left = 0;
    int right = 0;

    while (right < n) {
        if (binaryString[right] == '1') {
            onesCount++;
        }

        
        while (onesCount >= x) {      count += n - right;

            if (binaryString[left] == '1') {
                onesCount--;
            }

            left++;
        }

        right++;
    }

    return count;
}


int main(){
    vector<int>nums;
    nums.push_back(1);
cout<<countSubstrings("111011",4);
    return 0;
}