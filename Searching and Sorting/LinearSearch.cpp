#include<iostream>
using namespace std;

void linearSearch(int a[],int n,int s)
{
    int temp=-1;
    for(int i=0;i<s;i++)
    {
        if(a[i]==n)
        {
            cout<<"Element found at position :"<<i+1<<endl;
            temp=0;
            break;
        }
    }

    if(temp==-1)
    {
        cout<<"Element not Found"<<endl;
    }
}

int main()
{
    cout<<"Enter the size of the array"<<endl;
    int size;
    cin>>size;
    int arr[size];
    cout<<"Enter "<<size<<" elements of the Array"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter an element to search"<<endl;
    int num;
    cin>>num;

    linearSearch(arr,num,size);

    return 0;
}