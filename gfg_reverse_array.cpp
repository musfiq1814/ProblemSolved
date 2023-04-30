

#include<iostream>


using namespace std;


void ReverseArray()
{
    int n,i;
    cin>>n;
    int arr[n],temp[n];


    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    for(i=1;i<=n;i++)
    {
        temp[n-i+1] = arr[i];
    }

    for(i=1;i<=n;i++)
    {
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}


int main()
{   
    int t,i;
    cin>>t;
    for(i=1;i<=t;i++){
        ReverseArray();
    }
}
