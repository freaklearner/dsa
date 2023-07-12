#include<iostream>
#include<vector>
using namespace std;

bool checkSafe(vector<vector<int>> &grid, int i, int j)
{
    if(i<0 || i==grid.size())
    {
        return false;
    }
    if(j<0 || j==grid.size())
    {
        return false;
    }
    if(grid[i][j]!=1)
    {
        return false;
    }
    return true;
}

void maze(int &n,vector<vector<int>> &grid,int i, int j, vector<char> &store, vector<vector<int>> &visited)
{
    if(i==j && j==n-1)
    {
        for(char ch : store)
        {
            cout<<ch;
        }
        cout<<endl;
        return;
    }
    visited[i][j]=1;
    if(checkSafe(grid,i+1,j) && visited[i+1][j]==0)
    {
        store.push_back('D');
        maze(n,grid,i+1,j,store, visited);
        store.pop_back();
    }
    if(checkSafe(grid,i,j-1) && visited[i][j-1]==0)
    {
        store.push_back('L');
        maze(n,grid,i,j-1,store, visited);
        store.pop_back();
    }
    if(checkSafe(grid,i,j+1) && visited[i][j+1]==0)
    {
        store.push_back('R');
        maze(n,grid,i,j+1,store,visited);
        store.pop_back();
    }
    if(checkSafe(grid,i-1,j) && visited[i-1][j]==0)
    {
        store.push_back('U');
        maze(n,grid,i-1,j,store, visited);
        store.pop_back();
    }
    visited[i][j]=0;
    
}

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        cout<<"Inside T: "<<t<<endl;
        int n;
        cin>>n;
        vector<vector<int>> grid;
        vector<vector<int>> visited;
        grid.resize(n);
        visited.resize(n);
        for(int i=0;i<n;i++)
        {
            grid[i].resize(n);
            visited[i].resize(n);
            for(int j=0;j<n;j++)
            {
                cin>>grid[i][j];
                visited[i][j]=0;
            }
        }
        vector<char> store;
        maze(n,grid,0,0,store,visited);
        t--;
    }
    
    cin.get();
    return 0;
}