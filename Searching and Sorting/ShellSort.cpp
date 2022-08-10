#include <iostream>
using namespace std;

void ShellSort(int arr[], int n)
{
    for(int gap=n/2; gap>0; gap/=2)
    {
        for(int j=gap; j<n; j++)
        {
            int temp = arr[j];
            int i=0;

            for(i=j; (i>=gap && arr[i-gap]>temp); i-=gap)
            {
                arr[i] = arr[i-gap];
            }

            arr[i] = temp;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int myarr[n];

    cout << "Enter "<<n<<" integers in any order" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> myarr[i];
    }

    cout<<endl<<endl;

    cout<<"Before Shell Sort"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<myarr[i]<<" ";
    }

    cout<<endl<<endl;;

    ShellSort(myarr,n);   //Shell Sort Called here (Using Bubble Sort tech)

    cout<<"After Shell Sort"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<myarr[i]<<" ";
    }
    return 0;
}