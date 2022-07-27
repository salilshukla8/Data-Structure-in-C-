#include <iostream>
using namespace std;

//merge function
void merge(int arr[],int l,int m,int r,int size)
{
    int i=l;  //pointing to first sub array
    int j=m+1; //pointing to second sub array
    int k=l;   //pointing to temp array

    int temp[size];  //temporary array

    while(i<=m && j<=r)
    {
        if(arr[i]<=arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }

        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i<=m)       //copying all elements from left sub-array as it is 
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j<=r)      //copying all elements from right-subarray as it is 
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(int p=l;p<=r;p++)   //putting sorted elements of temp to original array
    {
        arr[p] = temp[p];
    }
}

//merge sort function
void mergeSort(int arr[], int l, int r, int size)
{
    if(l<r)
    {
        int m = (l+r)/2;
        mergeSort(arr,l,m,size);
        mergeSort(arr,m+1,r,size);
        merge(arr,l,m,r,size);
    }
}

int main()
{
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int myarr[size];

    cout << "Enter "<<size<<" integers in any order" << endl;

    for (int i = 0; i < size; i++)
    {
        cin >> myarr[i];
    }

    cout<<"Before Merge Sort : ";

    for(int i=0;i<size;i++)
    {
        cout<<myarr[i]<<" ";
    }

    cout<<endl;

    mergeSort(myarr,0,(size-1),size);   //calling merge Sort function

    cout<<"After Merge Sort : ";

    for(int i=0;i<size;i++)
    {
        cout<<myarr[i]<<" ";
    }


}