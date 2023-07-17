#include<iostream>
#include<vector>
using namespace std;

bool safe(int &i, int &j, int m, int n)
{
    if(i<0 || i==m || j<0 || j==n)
    {
        return false;
    }
    return true;
}

bool wordBoggle(vector<vector<char>> &board, string &s, vector<vector<int>> &visit, int i, int j, int &index)
{
    if(!safe(i,j,board.size(),board[0].size()) || visit[i][j]!=0 || board[i][j]!=s[index])
    {
        return false;
    }
    if(index==s.length()-1)
    {
        return true;
    }
    visit[i][j]=1;
    index++;    
    bool flag = false;
    flag = wordBoggle(board,s,visit,i,j+1,index);
    flag = flag || wordBoggle(board,s,visit,i+1,j,index);
    flag = flag || wordBoggle(board,s,visit,i,j-1,index);
    flag = flag || wordBoggle(board,s,visit,i-1,j,index);
    flag = flag || wordBoggle(board,s,visit,i+1,j+1,index);
    flag = flag || wordBoggle(board,s,visit,i+1,j-1,index);
    flag = flag || wordBoggle(board,s,visit,i-1,j+1,index);
    flag = flag || wordBoggle(board,s,visit,i-1,j-1,index);
    visit[i][j]=0;
    index--;
    return flag;
}

int main()
{
    vector<string> dict =   {"GEEKS","FOR","QUIZ","GO"};
    vector<vector<char>> board = {{'G','I','Z'},{'U','E','K'},{'Q','S','E'}};
    int index = 0;
    vector<vector<int>> visit(board.size(),vector<int>(board[0].size(),0));
    vector<string> exist;
    for( string s: dict)
    {
        bool flag = false;
        for(int i=0;!flag && i<board.size();i++)
        {
            for(int j=0;!flag && j<board[0].size();j++)
            {
                if(wordBoggle(board,s,visit,i,j,index))
                {
                    cout<<s<<endl;
                    exist.push_back(s);
                    flag=true;
                }
            }

        }
    }

    return 0;
}
