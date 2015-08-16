#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution
{


public:
    int judge(vector<vector<char> >& board,string word,int row,int colum,int pos,int len,int rows,int colums,vector<vector<int> > &num)
    {
        if(word[pos]==board[row][colum])
        {
            num[row][colum]=1;
            if(row-1>=0&&num[row-1][colum]==0)
            {
                if(judge(board,word,row-1,colum,pos+1,len,rows,colums,num)==1)
                {
                    num[row][colum]=0;
                    return 1;
                }
            }
            if(row+1<rows&&num[row+1][colum]==0)
            {
                if(judge(board,word,row+1,colum,pos+1,len,rows,colums,num)==1)
                {
                    num[row][colum]=0;
                    return 1;
                }
            }
            if(colum-1>=0&&num[row][colum-1]==0)
            {
                if(judge(board,word,row,colum-1,pos+1,len,rows,colums,num)==1)
                {
                    num[row][colum]=0;
                    return 1;
                }
            }
            if(colum+1<colums&&num[row][colum+1]==0)
            {
                if(judge(board,word,row,colum+1,pos+1,len,rows,colums,num)==1)
                {
                    num[row][colum]=0;
                    return 1;
                }
            }
            if(pos==len-1)
                return 1;
            else
                {
                     num[row][colum]=0;
                    return 0;
                }

        }
        else
            return 0;
    }

    bool exist(vector<vector<char> >& board, string word)
    {

        int len=word.size();
        int rows=board.size();
        int colums=board[0].size();
        vector<vector<int> >num;
        vector<int> temp;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<colums; j++)
            {
                temp.push_back(0);
            }
            num.push_back(temp);
            temp.clear();
        }
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<colums; j++)
            {
                int x=judge(board,word,i,j,0,len,rows,colums,num);
                if(x==1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};


int main()
{
    vector<vector<char> >test;
    vector<char> temp;
    temp.push_back('C');
    temp.push_back('A');
    temp.push_back('A');
   // temp.push_back('E');
    test.push_back(temp);
    temp.clear();
    temp.push_back('A');
    temp.push_back('A');
    temp.push_back('A');
  //  temp.push_back('S');
    test.push_back(temp);
    temp.clear();
    temp.push_back('B');
    temp.push_back('C');
    temp.push_back('D');
 //   temp.push_back('E');
    test.push_back(temp);
    temp.clear();
    string word="AAAAADB";
    Solution s;
    cout<<s.exist(test,word)<<endl;

    return 0;
}
