#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
struct Node
{
    int count;
    int value;
};

class Solution
{
public:

    int Position(Node *node,int left,int right)
    {
        Node temp;
        int mid=left+(right-left)/2;
        if(node[left].value>node[right].value)
        {
            temp=node[left];
            node[left]=node[right];
            node[right]=temp;
        }
        if(node[mid].value>node[right].value)
        {
            temp=node[mid];
            node[mid]=node[right];
            node[right]=temp;
        }
        if(node[left].value<node[mid].value)
        {
            temp=node[left];
            node[left]=node[mid];
            node[mid]=temp;
        }
        Node mid_value=node[left];
        while(left<right)
        {
            while(right>left&&node[right].value>=mid_value.value)
                right--;
            node[left]=node[right];
            while(left<right&&node[left].value<=mid_value.value)
                left++;
            node[right]=node[left];
        }
        node[left]=mid_value;
        return left;
    }

    void QuickSort(Node *node,int left,int right)
    {
        if(left<right)
        {
            int key=Position(node,left,right);
            QuickSort(node,left,key-1);
            QuickSort(node,key+1,right);
        }
    }

    int Find(Node *node,int left,int right,int temp)
    {
        int mid;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(node[mid].value==temp)
                return mid;
            else if(node[mid].value>temp)
                right=mid-1;
            else
                left=mid+1;
        }
        return 0;
    }

    vector<int> twoSum(vector<int> &numbers, int target)
    {
        Node node[numbers.size()];
        vector<int> res;
        int temp;
        int j;
        for(int i=0; i<numbers.size(); i++)
        {
            node[i].count=i+1;
            node[i].value=numbers[i];
        }
        QuickSort(node,0,numbers.size()-1);
        for(int i=0; i<numbers.size()-1; i++)
        {
            temp=target-node[i].value;
            j=Find(node,i+1,numbers.size()-1,temp);
            if(j!=0)
            {
                if(node[i].count<node[j].count)
                {
                    res.push_back(node[i].count);
                res.push_back(node[j].count);
                }
                else
                {
                    res.push_back(node[j].count);
                    res.push_back(node[i].count);
                }
                break;
            }

        }
        return res;
    }
};
*/

class Solution
{
public:

    vector<int> twoSum(vector<int> &numbers, int target)
    {
       vector<int> res;
       map<int,int> numbersMap;
       for(int i=0;i<numbers.size();i++)
       {
           if(numbersMap.count(numbers[i])==0)
            numbersMap.insert(pair<int,int> (numbers[i],i));
           if(numbersMap.count(target-numbers[i])!=0)
           {
                 int n=numbersMap[target-numbers[i]];
                 if(n<i)
                 {
                     res.push_back(n+1);
                     res.push_back(i+1);
                 }
                 if(i<n)
                 {
                     res.push_back(i+1);
                     res.push_back(n+1);
                 }
                 if(i!=n)
                 break;
           }

       }
        return res;
    }
};
int main()
{
    vector<int> numbers;
    numbers.push_back(-1);
    numbers.push_back(-2);
    numbers.push_back(-3);
    numbers.push_back(-4);
    numbers.push_back(-5);
    Solution s;
    vector<int> res=s.twoSum(numbers,-8);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<endl;

    return 0;
}
