#include <iostream>
using namespace std;

int getMax(int arr[],int size)
{
    int max = arr[0];
    for(int i=1;i<size;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
}

void countingSort(int arr[],int size,int div)
{
    int range=10;
    int count_array[range] = {0};
    int output[size];

    for(int i=0;i<size;i++)
    {
        count_array[(arr[i]/div)%10]++;
    }

    for(int i=1;i<range;i++)
    {
        count_array[i] = count_array[i] + count_array[i-1];
    }

    for(int i=size-1;i>=0;i--)
    {
        output[count_array[(arr[i]/div)%10]-1] = arr[i];
        count_array[(arr[i]/div)%10]--;
    }

    for(int i=0;i<size;i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(int arr[],int size)
{
    int m = getMax(arr,size);
    for(int div=1;m/div>0;div*=10)
    {
        countingSort(arr,size,div);
    }
}

int main()
{
    int size=0;
    cout<<"Enter the size of the array: ";
    cin>>size;

    int myarr[size];

    cout << "Enter "<<size<<" integers in any order" << endl;

    for (int i = 0; i < size; i++)
    {
        cin >> myarr[i];
    }

    cout<<"Before Radix Sort"<<endl;

    for(int i=0;i<size;i++)
    {
        cout<<myarr[i]<<" ";
    }

    cout<<endl;

    radixSort(myarr,size);   //Calling Radix sort

    cout<<"After Radix Sort"<<endl;

    for(int i=0;i<size;i++)
    {
        cout<<myarr[i]<<" ";
    }
    return 0;
}