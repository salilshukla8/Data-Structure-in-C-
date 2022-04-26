#include<iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
    while(left<=right)
    {
        int mid=(left+right)/2;

        if(arr[mid]==x)
        {
            return mid;
        }

        else if(arr[mid]<x)
        {
            left=mid+1;
        }

        else
        {
            right=mid-1;
        }
    }

    return -1;
}

int main()
{
    int num;
    int myarr[10];
    int output;

    cout<<"Enter 10 elements of Array in ASCENDING Order"<<endl;

    for(int i=0;i<10;i++)
    {
        cin>>myarr[i];
    }

    cout<<"Enter the number that you want to search in the Array :"<<endl;
    cin>>num;

    output=binarySearch(myarr,0,9,num);

    if(output==-1)
    {
        cout<<"Number not Found in the Array"<<endl;
    }

    else
    {
        cout<<"Number is present in the Array at position: "<<output+1<<endl;
    }
    return 0;
}