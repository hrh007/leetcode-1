#include <iostream>
#include <vector>

using namespace std;

class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        ++sum;
        v.push_back(num);
        int i=sum-2;
        for(;i>=0;--i)
        {
            if(v[i]>num)
                v[i+1]=v[i];
            else
                break;
        }
        v[i+1]=num;
    }

    // Returns the median of current data stream
    double findMedian() {
        int temp=sum/2;
        double res;
        if(sum%2==0)
            res=(v[temp-1]+v[temp])/2;
        else
            res=v[temp];
        return res;
    }
    MedianFinder()
    {
        sum=0;
    }
private:
    vector<double> v;
    int sum;
};


int main()
{
    MedianFinder *temp=new MedianFinder();
    while(1)
    {
        double x;
        cin>>x;
        temp->addNum(x);
        cout<<temp->findMedian()<<endl;
    }
    return 0;
}
