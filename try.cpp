#include<bits/stdc++.h>
using namespace std;
string func(string a,string b){
if(a.length()>b.length()){
    return func(b,a);
}
    string res="";

    bool carry=false;
    int i=0;  
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    for(i=0; i<min(a.length(),b.length()); i++){
        int first=a[i]-'0';
        int sec=b[i]-'0';
        // cout<<first<<" "<<sec<<endl;

        int x=first+sec;
 
        if(carry){
            x+=1;
            carry=false;
        }
        if(x<=9){
            char ch=x+'0';
            res.push_back(ch);
        }
        else{
            char ch=(x%10)+'0';
            res.push_back(ch);
            carry=true;
        }
        // cout<<res<<endl;

    }
    while(i<b.length()){
        int x=b[i]-'0';
        if(carry){
            x+=1;
            carry=false;
        }
        if(x<=9){
            char ch=x+'0';
             res.push_back(ch);
        }
        else{
            char ch=(x%10)+'0';
            res.push_back(ch);
            carry=true;
        }
        i++;
    }
    if(carry==true){
        res.push_back('1');
    }
    reverse(res.begin(),res.end());
    return res;

}
int main(){
    cout<<func("24578","144589");
    //985441
    //87542
    return 0;
}