#include <iostream>
#include <vector>
#include <cstdio>
#define eps 1e-7

using namespace std;


class Solution
{
    public:

        double Find(vector<int> &nums1,int left1,int right1,vector<int> &nums2 ,int left2,int right2,int k)
        {
            int sum1=right1-left1;
            int sum2=right2-left2;
            if(sum1<sum2)
            {
                if(k==1)
                {
                    if(right1==0)
                        return nums2[left2+k-1];
                    else
                    return nums1[left1]<nums2[left2]?nums1[left1]:nums2[left2];
                }
                else if(sum1==0)
                    return nums2[left2+k-1];
                else
                {
                    int point1=k/2;
                    if(sum1<point1)
                        point1=sum1;
                    int point2=k-point1;
                    if(nums1[left1+point1-1]==nums2[left2+point2-1])
                        return nums1[left1+point1-1];
                    else if(nums1[left1+point1-1]<nums2[left2+point2-1])
                        return Find(nums1,point1,right1,nums2,left2,point2,k-point1);
                    else
                        return Find(nums1,left1,point1,nums2,point2,right2,k-point2);
                }
            }
            else
            {
                if(k==1)
                {
                    if(right2==0)
                        return nums1[left1+k-1];
                    else
                        return nums1[left1]<nums2[left2]?nums1[left1]:nums2[left2];
                }
                else if(sum2==0)
                    return nums1[left1+k-1];
                else
                {
                    int point2=k/2;
                    if(sum2<point2)
                        point2=sum2;
                    int point1=k-point2;
                    if(nums1[left1+point1-1]==nums2[left2+point2-1])
                        return nums1[left1+point1-1];
                    else if(nums1[left1+point1-1]<nums2[left2+point2-1])
                        return Find(nums1,point1,right1,nums2,left2,point2,k-point1);
                    else
                        return Find(nums1,left1,point1,nums2,point2,right2,k-point2);
                }

            }
        }
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
        {
            int m=nums1.size();
            int n=nums2.size();
            if((m+n)%2==0)
            {
                double res1=Find(nums1,0,m,nums2,0,n,(m+n)/2+1);
                double res2=Find(nums1,0,m,nums2,0,n,(m+n)/2);
                double res=0.0+res1+res2;
                res=res/2;
                // cout<<"res1   "<<res1<<endl;
                //  cout<<"res2  "<<res2<<endl;
                //  printf("%lf\n",res);
                return res;
            }
            else
                return Find(nums1,0,m,nums2,0,n,(m+n)/2+1);
        }
/*public :
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        const int size_1 = nums1.size();
        const int size_2 = nums2.size();
        int k = (size_1 + size_2) / 2;
        int res1 = Kth(nums1.begin(), size_1, nums2.begin(), size_2, k+1);
        if ((size_1 + size_2) % 2 == 0)
        {
            int res2 = Kth(nums1.begin(), size_1, nums2.begin(), size_2, k);
            return ( (double) res1 + res2) / 2.0;
        }
        return res1;
    }
private:
    typedef vector<int>::iterator Iter;

    int  Kth(Iter start1, int size_1, Iter start2, int size_2, int kth)
    {
        if (size_1 > size_2) return Kth(start2 , size_2, start1, size_1, kth);
        if (size_1 == 0) return *(start2 + kth - 1);
        if (kth == 1) return min(*start1, *start2);

        int index_1 = min(size_1, kth / 2);
        int index_2 = kth - index_1;
        if (*(start1 + index_1 - 1) > *(start2 + index_2 - 1))
            return Kth(start1, size_1 ,start2 + index_2, size_2 - index_2, kth - index_2);
        return Kth(start1 + index_1, size_1 - index_1, start2, index_2, kth - index_1);
    }*/
};
int main()
{
   vector<int> test;
    int a;
    cin>>a;
    test.push_back(a);
    // test.push_back(4);
    vector<int> test2;
    int b;
    cin>>b;
    test2.push_back(b);
    //  test2.push_back(2);
    // test2.push_back(3);
    //  test2.push_back(5);
    Solution s;
   // cout<<s.findMedianSortedArrays(test,test2)<<endl;
    printf("%f\n",s.findMedianSortedArrays(test,test2));
    //cout<<"12 3    "<<s.findMedianSortedArrays(test,test2)<<endl;
    return 0;
}
