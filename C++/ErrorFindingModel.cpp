#include<iostream>
#include<cstdio>
using namespace std;

int Repeating(int arr[],int n)
{
    int repeating;
    bool found = false;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                repeating = arr[i];
                found = true;
                break;
            }
        }
        if(found)
            break;

    }
    return repeating;
}

int main()
{
    int n,min,temp;
    cin>>n;
    int a[n];
    
    for (int l=0;l<n;l++)
        cin>>a[l];
    
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for (int j=i+1;j<n;j++)
            if(a[min]>a[j])
                min=j;
            
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
    
    int r = Repeating(a,n); 
    int missing;
    for(int i=1;i<n+1;i++)
    {
        bool flag=false;
        for(int j=0;j<n;j++)
        {
            if(a[j]==i)
                flag = true;
        }
        if(!flag)
        {
            missing = i;
            break;
        }
    }
    cout<<r<<endl;
    cout<<missing;
}

