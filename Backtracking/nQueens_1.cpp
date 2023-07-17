#include<iostream>
#include<vector>
using namespace std;

bool checkPlace(int i, int j, vector<string> &board)
{
    for(int t=i;t>=0;t--)
    {
        if(board[t][j]=='Q')
        {
            return false;
        }
    }
    for(int t=i,k=j-1;t>=0 && k>=0;t--,k--)
    {
        if(board[t][k]=='Q')
        {
            return false;
        }
    }
    for(int t=i,k=j+1;t>=0&&k<board.size();t--,k++)
    {
        if(board[t][k]=='Q')
        {
            return false;
        }
    }
    return true;
}
void placeQueens(vector<string> & board, int i,vector<vector<string>> &store)
{
    if(i==board.size())
    {
        store.push_back(board);
        return;
    }
    for(int j=0;j<board.size();j++)
    {
        if(checkPlace(i-1,j,board))
        {
            board[i][j] = 'Q';
            placeQueens(board,i+1,store);
            board[i][j]='.';
        }
    }
}

int main()
{
    int n=4;
    vector<string> board(n,string(n,'.'));
    vector<vector<string>> store;
    placeQueens(board,0,store);
    for(vector<string> ans: store)
    {
        for(string row: ans)
        {
            cout<<row<<" ,";
        }
        cout<<endl;
    }
    cin.get();
    return 0;
}