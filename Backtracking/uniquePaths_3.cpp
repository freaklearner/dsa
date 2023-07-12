#include<iostream>
#include<vector>
using namespace std;

bool safeStep(int i, int j, vector<vector<int>> &grid)
{
    if(i<0 || i==grid.size())
    {
        return false;
    }
    if(j<0 || j==grid[0].size())
    {
        return false;
    }
    if(grid[i][j]<0)
    {
        return false;
    }
    return true;
}

int paths(vector<vector<int>> &grid, int i,int j, int &count,vector<vector<int>> &visited)
{
    if(grid[i][j]==2 && count==0)
    {
        return 1;
    }
    visited[i][j]=1;
    count--;
    int sum=0;
    if(safeStep(i,j+1,grid) && visited[i][j+1]==0)
    {
        sum+=paths(grid,i,j+1,count,visited);
    }
    if(safeStep(i+1,j,grid) && visited[i+1][j]==0)
    {
        sum+=paths(grid,i+1,j,count,visited);
    }
    if(safeStep(i,j-1,grid) && visited[i][j-1]==0)
    {
        sum+=paths(grid,i,j-1,count,visited);
    }
    if(safeStep(i-1,j,grid)&& visited[i-1][j]==0)
    {
        sum+=paths(grid,i-1,j,count,visited);
    }
    visited[i][j]=0;
    count++;
    return sum;
}

int main()
{
    vector<vector<int>> grid = {{0,1},{2,0}};
    vector<vector<int>> visited(grid.size());
    int count=0, start_i,start_j;
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0; j<grid[0].size() ; j++)
        {
            if(grid[i][j]==0)
            {
                count++;;
            }
            else if(grid[i][j]==1)
            {
                count++;
                start_i=i;
                start_j=j;
            }
            visited[i].push_back(0);
        }
    }
    
    cout<<paths(grid,start_i,start_j,count,visited);
    cin.get();
    return 0;
}