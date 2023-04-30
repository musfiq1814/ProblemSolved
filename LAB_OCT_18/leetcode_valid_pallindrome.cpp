#include<iostream>


using namespace std;


bool isPalindrome(string s) {
        
        
        int i,IntChar[s.size()],j=0;
        
        for(i=0;i<s.size();i++)
        {
            if( (s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) ){
                
                IntChar[j] = s[i];
            
                if(IntChar[j] >=97 && IntChar[j]<=122)
                {
                    IntChar[j] -= 32;
                }
                j++;
                
            }
        }
        
        int size2 = j;
        
        bool isPallindrome = true;
        
        
        for(i=0;i<size2/2;i++)
        {
            
            
            cout<<IntChar[i]<<"   "<<IntChar[size2-i-1]<<endl;
            
            
            if(IntChar[i] != IntChar[size2-i-1])
            {
                isPallindrome = false;
                break;
            };
        }
        
        
            
            
        return isPallindrome;
    }

int main()
{
    cout<<isPalindrome("0P")<<endl;
}
