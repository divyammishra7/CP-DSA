#include<bits/stdc++.h>
using namespace std;
int ans=0;
     void bfs(vector<vector<int>>&grid,vector<vector<bool>>&vis,pair<int,int>source,int &count){
         vis[source.first][source.second]=true;
         queue<pair<pair<int,int>,int>>q;
         q.push({{source.first,source.second},1});
         count++;
         int m=grid.size();
         int n=grid[0].size();
         while(!q.empty()){
             pair<pair<int,int>,int>ok=q.front();
             q.pop();
             int x=ok.first.first;
             int y=ok.first.second;
             int temp=ok.second;
           
            
         
            //  ans=max(ans,temp);
            //     if(x+1<m && !vis[x+1][y] && grid[x+1][y]==1){
            //      ans++;
                
                 

            //  }
            //  if(x-1>=0 && !vis[x-1][y] && grid[x-1][y]==1){
            //     ans++;
             
            //  }
            //   if(y+1<n && !vis[x][y+1] && grid[x][y+1]==1){
            //         ans++;
                 
                  
            //  }
            //   if(y-1>=0 && !vis[x][y-1] && grid[x][y-1]==1){
            //         ans++;
               
            //  }
            //  cout<<temp<<endl;
             if(x+1<m && !vis[x+1][y] && grid[x+1][y]==1){
                 
                 q.push({{x+1,y},ans+1});
                 
                 vis[x+1][y]=true;
                 count++;
                 
             }
                if(x-1>=0 && !vis[x-1][y] && grid[x-1][y]==1){
                
                 q.push({{x-1,y},ans+1});
                 count++;
                  vis[x-1][y]=true;
             }
                if(y+1<n && !vis[x][y+1] && grid[x][y+1]==1){
                    
                 q.push({{x,y+1},ans+1});
                 count++;
                  vis[x][y+1]=true;
                  
             }
                if(y-1>=0 && !vis[x][y-1] && grid[x][y-1]==1){
                
                 q.push({{x,y-1},ans+1});
                 count++;
                 
                  vis[x][y-1]=true;
             }
         }

     }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
   
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size();j++){
                if(vis[i][j]==false && grid[i][j]==1){
                         int count=0;
                    cout<<i<<" "<<j<<endl;
                    bfs(grid,vis,{i,j},count);
                    ans=max(ans,count);
                }

            }
        }
        return ans;

        
    }
signed main(){

vector<vector<int>>grid={{1,1,1},{1,1,0}};
cout<<maxAreaOfIsland(grid)<<endl;
}