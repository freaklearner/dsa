#include<iostream>
#include<vector>
#include<climits>
using namespace std;

bool checkSafe(vector<vector<int>> & grid, int i, int j)
{
    if(i==j && j==grid.size()-1)
    {
        return true;
    }
    if(i>=grid.size() || j>=grid.size() || grid[i][j]<=0)
    {
        return false;
    }
    return true;
}

void ratMaze(vector<vector<int>> &grid, int i, int j, int hop, vector<vector<int>> &visited,int &shortest, vector<vector<int>> &store)
{
    if(i==j && j==grid.size()-1)
    {
        visited[i][j]=1;
        if(hop<shortest)
        {    
            shortest=hop;
            store=visited;
        }
        visited[i][j]=0;
        return;
    }
    if(i>=grid.size() || j>=grid.size() || grid[i][j]<=0)
    {
        return;
    }
    visited[i][j]=1;
    for(int t=1;t<=grid[i][j];t++)
    {
        if(checkSafe(grid,i,j+t))
        {
            ratMaze(grid,i,j+t,hop+t,visited,shortest,store);
        }
        if(checkSafe(grid,i+t,j))
        {
            ratMaze(grid,i+t,j,hop+t,visited,shortest,store);
        }
    }
    visited[i][j]=0;
}

int main()
{
    vector<vector<int>> grid = {{2, 0, 2, 2,},{4, 3, 3, 2},{0, 1, 3, 2},{1, 4, 0, 4}};
    vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
    vector<vector<int>> store={{-1}};
    int shortest = INT_MAX;
    ratMaze(grid,0,0,0,visited,shortest,store);
    for(vector<int> row: store)
    {
        for(int col : row)
        {
            cout<<col<<" ";
        }
        cout<<endl;
    }
    cin.get();
    return 0;
}

/*
bool safe(int &i, int &j, vector<vector<int>> &matrix)
    {
        int n=matrix.size();
        if(i<0 || i>=n || j<0 || j>=n || matrix[i][j]==0)
        {
            return false;
        }
        return true;
    }
    bool helper(vector<vector<int>> &matrix, vector<vector<int>> &visit, int i, int j)
    {
        int n = matrix.size();
        if(i==j && j==n-1)
        {
            visit[i][j]=1;
            return true;
        }
        if(safe(i,j,matrix))
        {
            visit[i][j]=1;
            for(int t=1;t<=matrix[i][j];t++)
            {
                if(helper(matrix,visit,i,j+t))
                    return true;
                if(helper(matrix,visit,i+t,j))
                    return true;
            }
            visit[i][j]=0;
        }
        return false;
        
    }
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   // Code here
	   vector<vector<int>> visit(matrix.size(), vector<int>(matrix.size(),0));
	   if(helper(matrix,visit,0,0))
	   {
	       return visit;
	   }
	   else{
	       return {{-1}};
	   }
	   
	}
*/