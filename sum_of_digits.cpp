


#include<iostream>

using namespace std;


int digits(int num)
{
    int i = 0,sum =0;
    while(num!=0)
    {
        sum += num%10; 
        num = num/10;
        i++;
    }
    return sum;
}

int main()
{
    int n;
    cin>>n;

    cout<<digits(n)<<endl;




}
