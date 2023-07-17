#include<iostream>
#include<vector>
using namespace std;

int matrixNumber(int i,int j)
{
    int num = 0;
    if(i<3)
    {
        num=0;
    }
    else if(i<6)
    {
        num=3;
    }
    else{
        num=6;
    }
    return num+ j/3;
    
}

void initiateBoard(vector<vector<char>> &board, vector<vector<int>> &rowFreq, vector<vector<int>> &colFreq, vector<vector<int>> &matrixFreq)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]!='.')
            {
                int val = board[i][j]-'1';
                rowFreq[i][val]++;
                colFreq[j][val]++;
                int matrixNum = matrixNumber(i,j);
                matrixFreq[matrixNum][val]++;
            }
        }
    }
}

bool sudokuSolution(vector<vector<char>> &board, vector<vector<int>> &rowFreq, vector<vector<int>> &colFreq, vector<vector<int>> &matrixFreq,int i, int j)
{

    if(i==9)
    {
        for(vector<char> row : board)
        {
            for(char ch: row)
            {
                cout<<ch<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    if(j==9)
    {
        return sudokuSolution(board, rowFreq,colFreq, matrixFreq, i+1,0);
    }
    if(board[i][j]!='.')
    {
        return sudokuSolution(board, rowFreq,colFreq, matrixFreq, i,j+1);
    }
    int matrixNum = matrixNumber(i,j);
    for(int t=1;t<=9;t++)
    {
        if(rowFreq[i][t-1]==0 && colFreq[j][t-1]==0 && matrixFreq[matrixNum][t-1]==0 )
        {
            board[i][j]=t+'0';
            rowFreq[i][t-1]++;
            colFreq[j][t-1]++;
            matrixFreq[matrixNum][t-1]++;
            if(sudokuSolution(board,rowFreq,colFreq,matrixFreq,i,j+1))
            {
                return true;
            }
            board[i][j]='.';
            rowFreq[i][t-1]--;
            colFreq[j][t-1]--;
            matrixFreq[matrixNum][t-1]--;
        }

    }
    return false;
}

int main()
{
    vector<vector<char>> board={{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    vector<vector<int>> rowFreq(9,vector<int>(9,0));
    vector<vector<int>> colFreq(9,vector<int>(9,0));
    vector<vector<int>> matrixFreq(9,vector<int>(9,0));
    initiateBoard(board,rowFreq,colFreq,matrixFreq);
    sudokuSolution(board,rowFreq,colFreq,matrixFreq,0,0);
    //cout<<rowFreq;
    cin.get();
    return 0;
}
