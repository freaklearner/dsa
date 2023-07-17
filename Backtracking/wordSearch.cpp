#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool checkSafe(int i, int j,int m,int n)
{
    if(i<0 || i>=m)
    {
        return false;
    }
    if(j<0 || j>=n)
    {
        return false;
    }
    return true;
}

bool wordSearch(vector<vector<char>> &grid, string &word, int i, int j, int index,vector<vector<int>>visit)
{
    if(grid[i][j]!=word[index])
    {
        return false;
    }
    if(index==word.length()-1)
    {
        return true;
    }
    visit[i][j] = 1;
    bool flag = false;
    if(checkSafe(i,j+1, grid.size(), grid[0].size()) && visit[i][j+1]==0)
    {
        flag = flag || wordSearch(grid,word,i,j+1,index+1,visit);
    }
    if(!flag && checkSafe(i+1,j, grid.size(), grid[0].size()) && visit[i+1][j]==0)
    {
        flag = flag || wordSearch(grid,word,i+1,j,index+1,visit);
    }
    if(!flag && checkSafe(i,j-1, grid.size(), grid[0].size()) && visit[i][j-1]==0)
    {
        flag = flag || wordSearch(grid,word,i,j-1,index+1,visit);
    }
    if(!flag && checkSafe(i-1,j, grid.size(), grid[0].size()) && visit[i-1][j]==0)
    {
        flag = flag || wordSearch(grid,word,i-1,j,index+1,visit);
    }
    visit[i][j]=0;
    return flag;
}

int main()
{
    vector<vector<char>> board = {{'a'}};
    string word="a";
    vector<vector<int>> visit(board.size(),vector<int>(board[0].size(),0));
    bool flag = false;
    for(int i=0;!flag && i<board.size() ;i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            if(board[i][j]==word[0])
            {
                if(wordSearch(board,word,i,j,0,visit))
                {
                    cout<<"exist";
                    flag = true;
                    break;
                }

            }
        }
    }
    cin.get();    
    return 0;
}
