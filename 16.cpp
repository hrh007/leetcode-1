#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    int Position(vector<int> &num,int left,int right)
    {
        int mid=left+(right-left)/2;
        int temp;
        if(num[right]<num[left])
        {
            temp=num[right];
            num[right]=num[left];
            num[left]=temp;
        }
        if(num[right]<num[mid])
        {
            temp=num[right];
            num[right]=num[mid];
            num[mid]=temp;
        }
        if(num[mid]>num[left])
        {
            temp=num[mid];
            num[mid]=num[left];
            num[left]=temp;
        }
        int mid_value=num[left];
        while(left<right)
        {
            while(left<right&&num[right]>=mid_value)
                right--;
            num[left]=num[right];
            while(left<right&&num[left]<=mid_value)
                left++;
            num[right]=num[left];
        }
        num[left]=mid_value;
        return left;
    }
    void QuickSort(vector<int> &num,int left,int right)
    {
        int key;
        if(left<right)
        {
            key=Position(num,left,right);
            QuickSort(num,left,key-1);
            QuickSort(num,key+1,right);
        }
    }

    int Find(vector<int> &num,int left,int right,int target)
    {


    }
    int Transform(int x)
    {
        if(x<0)
            return -x;
        else
            return x;
    }
    int threeSumClosest(vector<int> &num, int target)
    {
        QuickSort(num,0,num.size()-1);
        int count=0;
        int sum;
        int res=num[0]+num[num.size()/2]+num[num.size()-1];
        if(res==target)
            return res;
        for(int i=0;i<num.size();i++)
        {
            int j=i+1;
            int k=num.size()-1;
            while(j<k)
            {
                sum=num[i]+num[j]+num[k];
                if(Transform(res-target)>Transform(sum-target))
                    res=sum;
                if(res==target)
                return res;
               if(num[j]+num[k]<target-num[i])
                j++;
               else
                k--;
            }
        }
        return res;

    }
};

int main()
{
    vector<int> num;
    num.push_back(-4);
    num.push_back(-1);
    num.push_back(0);
    num.push_back(2);
    num.push_back(2);
    num.push_back(6);
    Solution s;
     for(int i=-6;i<=11;i++)
     {
    int res=s.threeSumClosest(num,i);
    cout<<i<<"   "<<res<<endl;
      }
    return 0;
}
/*
class Solution
{
public:

    int Position(vector<int> &num,int left,int right)
    {
        int mid=left+(right-left)/2;
        int temp;
        if(num[right]<num[left])
        {
            temp=num[right];
            num[right]=num[left];
            num[left]=temp;
        }
        if(num[right]<num[mid])
        {
            temp=num[right];
            num[right]=num[mid];
            num[mid]=temp;
        }
        if(num[mid]>num[left])
        {
            temp=num[mid];
            num[mid]=num[left];
            num[left]=temp;
        }
        int mid_value=num[left];
        while(left<right)
        {
            while(left<right&&num[right]>=mid_value)
                right--;
            num[left]=num[right];
            while(left<right&&num[left]<=mid_value)
                left++;
            num[right]=num[left];
        }
        num[left]=mid_value;
        return left;
    }
    void QuickSort(vector<int> &num,int left,int right)
    {
        int key;
        if(left<right)
        {
            key=Position(num,left,right);
            QuickSort(num,left,key-1);
            QuickSort(num,key+1,right);
        }
    }

    int Transform(int x)
    {
        if(x<0)
            return -x;
        else
            return x;
    }

    int Find(vector<int> &num,int left,int right,int target)
    {
        int mid;
        while(left<right)
        {
            mid=(left+right)/2;
            if(num[mid]==target)
                return mid;
            else if(num[mid]<target)
                left=mid+1;
            else
                right=mid-1;
        }
        return left;
    }
    int threeSumClosest(vector<int> &num, int target)
    {
        QuickSort(num,0,num.size()-1);
        int temp=Find(num,0,num.size()-1,target);
        int min;
        if(temp==0)
        {
            return num[0]+num[1]+num[2];
        }
        else if(temp==num.size()-1)
        {
            if(num[temp]==target)
                return num[num.size()-1]+num[num.size()-2]+num[num.size()-3];
            else
            {
                min=Transform(num[num.size()-1]-target)+Transform(num[num.size()-2]-target)+Transform(num[num.size()-3]-target);
                if(Transform(num[num.size()-2]-target)+Transform(num[num.size()-3]-target)+Transform(num[num.size()-4]-target)<min&&num.size()-4>=0)
                    return num[num.size()-2]+num[num.size()-3]+num[num.size()-4];
                else
                    return num[num.size()-1]+num[num.size()-2]+num[num.size()-3];
            }
        }
        else
        {
            min=Transform(num[temp]-target)+Transform(num[temp-1]-target)+Transform(num[temp+1]-target);
            if(temp-2>=0&&Transform(num[temp]-target)+Transform(num[temp-1]-target)+Transform(num[temp-2]-target)<min)
            {
                min=Transform(num[temp]-target)+Transform(num[temp-1]-target)+Transform(num[temp-2]-target);
                if(temp+2<=num.size()-1&&Transform(num[temp]-target)+Transform(num[temp+1]-target)+Transform(num[temp+2]-target)<min)
                    return num[temp]+num[temp+1]+num[temp+2];
                else
                    return num[temp]+num[temp-1]+num[temp-2];
            }
            if(temp+2<=num.size()-1&&Transform(num[temp]-target)+Transform(num[temp+1]-target)+Transform(num[temp+2]-target)<min)
                {
                    return num[temp]+num[temp+1]+num[temp+2];
                }
            return num[temp-1]+num[temp]+num[temp+1];
        }
    }
};
*/
