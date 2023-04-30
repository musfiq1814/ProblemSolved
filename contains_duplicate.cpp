


#include<iostream>
#include<string>


using namespace std;

int main()
{
      string s;

    getline(cin,s);

    long long i,j;


    
    int arr[s.length()+1],index=0;

    for(i = 8;i<s.length()-1;i+=2)
    {
        //cout<<s[i]<<" ";
        arr[index] = int(s[i])-48;
        index++;
    }


    bool isDistinct = true;


    for(i=0;i<index;i++)
    {
        for(j=i+1;j<index;j++)
        {
            if(arr[i]==arr[j])
            {
                isDistinct = false;
                break;
            }
        }
    }


    cout<<isDistinct<<endl;



}