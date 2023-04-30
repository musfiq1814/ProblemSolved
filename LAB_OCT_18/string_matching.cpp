#include<iostream>

using namespace std;


int main()
{

    string a,b;
    int i;
    bool isSame = true;

    cout<<"Enter 1st string : ";
    cin>>a;
    cout<<"Enter 2nd string : ";
    cin>>b;


    if(a.length()!=b.length())
    {
        isSame = false;
    }
    else
    {
        for(i=0;i<a.length();i++)
        {
            if(a[i]!=b[i])
            {
                isSame = false;
                break;
            }
        }


    }

    if(isSame==true)
    {
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not same"<<endl;
    }






}