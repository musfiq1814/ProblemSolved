#include<iostream>
using namespace std;



int main()
{
    int nums1[] = {1,3},nums2[] = {2,4};
    double median;

    int m = 2,n = 2;
    
    int i=0,j=0,k=0,l;

    int merge[m+n];


    while(i<m && j<n)
    {
        if(nums1[i]<nums2[j])
        {  
            merge[k] = nums1[i];
            i++;
            
        }
        else
        {
            merge[k] = nums2[j];
            j++;
            
        }

        k++;

    };

    //cout<<i<<" "<<j<<" "<<endl;


    //k--;

    while(i<m)
    {
        merge[k] = nums1[i];
        i++;
        k++;
    }
        
    while(j<n)
    {
        merge[k] = nums2[j];
        j++;
        k++;
    }


    
   if( (m+n) %2==1)
    {
        median = merge[(m+n)/2];
        
    }
    else
    {
        
        median = (merge[(m+n)/2] + merge[ ((m+n)/2)-1 ] )/2.0;
       
    }
        
        
    cout<<median<<endl;
    











}