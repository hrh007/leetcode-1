class Solution {
public:
    string convertToTitle(int n) {
        char temp[100];
        char result[100];
        int i=0;
        int j=0;
        while(n!=0)
        {
            if(n%26==0)
                {
                    temp[i++]='Z';
                     n=n/26-1;
                }
            else
               {
                   temp[i++]=n%26+64;
                    n=n/26;

               }
        }
        i--;
       while(i>=0)
            result[j++]=temp[i--];
            result[j]='\0';
      return result;
    }
};
