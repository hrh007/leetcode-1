#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:

    string numberToWords(int num)
    {
        if(num==0)
            return "Zero";
        string res="";
        int temp;
        int i=0;
        int x=0;
        int count=0;
        stack<string> s;
        while(num)
        {
            temp=num%1000;
            if(temp&&i!=0)
            s.push(dw[i]);
            if(temp&&temp%100==0)
            {
                s.push("Hundred");
                s.push(trans1(temp/100));
            }
            else if(temp&&temp%100<=10)
            {
                s.push(trans1(temp%100));

                if(temp/100)
                {
                    s.push("Hundred");
                    s.push(trans1(temp/100));
                }
            }
            else if(temp&&temp%100<20)
            {
                s.push(trans2(temp%100));
                if(temp/100)
                {
                    s.push("Hundred");
                    s.push(trans1(temp/100));
                }
            }
            else if(temp)
            {
                if(temp%10)
                    s.push(trans1(temp%10));
                temp=temp/10;
                s.push(trans3(temp%10));
                temp=temp/10;
                if(temp)
                {
                    s.push("Hundred");
                    s.push(trans1(temp));
                }
            }
            num=num/1000;
            ++i;
        }
        res=stackToString(s);
        return res;

    }
private :
    string dw[4]= {"","Thousand","Million","Billion"};
    string trans1(int x)
    {
        switch(x)
        {
        case 1:
            return "One";
        case 2:
            return "Two";
        case 3:
            return "Three";
        case 4:
            return "Four";
        case 5:
            return "Five";
        case 6:
            return "Six";
        case 7:
            return "Seven";
        case 8:
            return "Eight";
        case 9:
            return "Nine";
        case 10:
            return "Ten";
        }
    }

    string trans2(int x)
    {
        switch(x)
        {
        case 11:
            return "Eleven";
        case 12:
            return "Twelve";
        case 13:
            return "Thirteen";
        case 14:
            return "Fourteen";
        case 15:
            return "Fifteen";
        case 16:
            return "Sixteen";
        case 17:
            return "Seventeen";
        case 18:
            return "Eighteen";
        case 19:
            return "Nineteen";
        }
    }

    string trans3(int x)
    {
        switch(x)
        {
        case 2:
            return "Twenty";
        case 3:
            return "Thirty";
        case 4:
            return "Forty";
        case 5:
            return "Fifty";
        case 6:
            return "Sixty";
        case 7:
            return "Seventy";
        case 8:
            return "Eighty";
        case 9:
            return "Ninety";
        }
    }
    string stackToString(stack<string> &s)
    {
        string res="";
         if(s.empty())
            return res;
        res+=s.top();
        s.pop();
        while(!s.empty())
        {
            res+=" ";
            res+=s.top();
            s.pop();
        }
        return res;
    }
};

int main()
{
    int x=1000000;
    Solution s;
  //  for(int i=0;i<123;i++)
    cout<<s.numberToWords(x)<<"123"<<endl;
    return 0;
}
