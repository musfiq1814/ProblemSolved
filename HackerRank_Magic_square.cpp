#include<iostream>

using namespace std;

int main()
{
    int arr[4][4],i,j,sumd1,sumd2,sumr1,sumr2,sumr3,sumc1,sumc2,sumc3;

    cout<<"Enter matrix: ";

    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            cin>>arr[i][j];

            if(i==j){
                sumd1 += arr[i][j];
            }

            if( (i+j) == 4)
            {
                sumd2 += arr[i][j];
            }
        }
    }

    cout<<sumd1<<" "<<sumd2<<endl;

}