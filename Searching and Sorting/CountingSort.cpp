#include <iostream>
using namespace std;

void countingSort(int input_arr[],int size,int range)
{
    int count_arr[range];
    int output_arr[size];

    for(int i=0;i<range;i++)   //initialize all values to 0 in count array
    {
        count_arr[i]=0;
    }

    for(int i=0;i<size;i++)   //count each element in input array & place the count in count array
    {
        ++count_arr[input_arr[i]];
    }

    //cumulative count of count array to get the positions of elements
    //to be stored in output array
    for(int i=1;i<range;i++)
    {
        count_arr[i] = count_arr[i] + count_arr[i-1];
    }

    //placing input array elements to output array in sorted format according to ASC
    for(int i=0;i<size;i++)
    {
        output_arr[--count_arr[input_arr[i]]] = input_arr[i];
    }

    //placing output array elements to input array
    for(int i=0;i<size;i++)
    {
        input_arr[i] = output_arr[i];
    }
}

int main()
{
    int size=0;
    int range = 10;
    cout<<"Enter the size of the array: ";
    cin>>size;

    int myarr[size];

    cout << "Enter "<<size<<" integers in the range 0-9 in any order" << endl;

    for (int i = 0; i < size; i++)
    {
        cin >> myarr[i];
    }

    cout<<"Before Counting Sort"<<endl;

    for(int i=0;i<size;i++)
    {
        cout<<myarr[i]<<" ";
    }

    cout<<endl;

    countingSort(myarr,size,range);   //Calling Counting sort

    cout<<"After Counting Sort"<<endl;

    for(int i=0;i<size;i++)
    {
        cout<<myarr[i]<<" ";
    }

    return 0;
}