#include<bits/stdc++.h>
using namespace std;
int findMax(int a[],int lo,int hi)
{
    if(lo>hi)
        return INT_MIN;
    if(lo==hi)
        return a[lo];
    int mid=(lo+hi)/2;
    int leftMax=findMax(a,lo,mid);
    int rightMax=findMax(a,mid+1,hi);
    return max(leftMax,rightMax);
}
int findMin(int a[],int lo,int hi)
{
    if(lo>hi)
        return INT_MAX;
    if(lo==hi)
        return a[lo];
    int mid=(lo+hi)/2;
    int leftMin=findMin(a,lo,mid);
    int rightMin=findMin(a,mid+1,hi);
    return min(leftMin,rightMin);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int choice;
    cout<<"Choose an option :"<<endl;
    cout<<"1.Find Maximum Element "<<endl;
    cout<<"2.Find Minimum Element "<<endl;
    cout<<"Enter your choice :";
    cin>>choice;
    switch(choice)
    {
case 1:
    {
        int MaxElement=findMax(arr,0,n-1);
        cout<<"The maximum element is ="<<MaxElement<<endl;
        break;
    }
case 2:
        {
            int MinElement=findMin(arr,0,n-1);
            cout<<"The minimum element is ="<<MinElement<<endl;
            break;

        }
default:
    cout<<"Invalid choice "<<endl;
    }
    return 0;

}
