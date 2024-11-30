#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int low,int high,int x)
{
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==x)
            return mid;
        if(arr[mid]<x)
            low=low+1;
        else
            high=high-1;
    }
    return -1;
}
int main()
{
    int n;
    cout<<"Enter the size of array =";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: "<<endl;
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int m;
    cout<<"Enter the searching elements :";
    cin>>m;
    int result=binarySearch(arr,0,n-1,m);
    if (result==-1)
        cout<<"Elements is not found in the array.."<<endl;
    else
        cout<<"The elements are in the index  "<<result<<endl;
    return 0;
}











