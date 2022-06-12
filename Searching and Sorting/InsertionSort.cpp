#include<iostream>
using namespace std;

void insertionSort(int arr[])
{
    int j=0;
    int key=0;

    for(int i=1; i<5; i++)
    {
        key = arr[i];   //picking the next element
        j = i-1;

        while(j>=0 && arr[j]>key)            //shifting the element to make place for key value
        {
            arr[j+1] = arr[j];
            j = j-1;
        }

        arr[j+1] = key;   //inserting key at vacant position
    }
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

    insertionSort(myarr);

    cout<<"After Sorting : ";

    for(int i=0;i<5;i++)
    {
        cout<<myarr[i]<<" ";
    }
}