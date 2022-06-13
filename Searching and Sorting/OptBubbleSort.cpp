#include<iostream>
using namespace std;

void optimizedbubbleSort(int arr[])
{
    int rounds = 0;
    for(int i=0 ; i<5; i++)
    {
        rounds++;
        bool flag = false;
        for(int j=0 ; j<5-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                flag = true;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(flag==false)
        {
            break;
        }
    }
    cout<<"No of rounds : "<<rounds;
}

int main()
{
    int myarr[5];

    cout<<"Enter 5 integers in any order"<<endl;

    for(int i=0;i<5;i++)
    {
        cin>>myarr[i];
    }

    cout<<"Before Sorting : ";

    for(int i=0;i<5;i++)
    {
        cout<<myarr[i]<<" ";
    }

    cout<<endl;

    optimizedbubbleSort(myarr);

    cout<<endl;

    cout<<"After Sorting : ";

    for(int i=0;i<5;i++)
    {
        cout<<myarr[i]<<" ";
    }
}