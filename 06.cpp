#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int left,int mid,int right)
{
    int n1=mid-left+1;
    int n2=right-mid;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++)
    {
        L[i]=arr[left+i];
    }
    for(int j=0;j<n2;j++)
    {
        R[j]=arr[mid+1+j];
    }
    int i=0,j=0;
    int k=left;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while (i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int left,int right)
{
    if(left>=right)
        return;
    int mid=left+(right-left)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}
void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
        cout<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter the size of array :";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"The given array is :"<<endl;
    printArray(arr,n);
    mergeSort(arr,0,n-1);
    cout<<"The sorted array is :"<<endl;
    printArray(arr,n);
    return 0;
}
























