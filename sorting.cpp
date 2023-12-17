#include<iostream>
#include<algorithm>
using namespace std;
    int main(){
    int arr[] = {10, 5, 6, 3, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Original array : ";
    for (int i = 0; i < n; i++){
    std::cout<<arr[i]<<" ";
    }
    std::sort(arr , arr + n);

    cout<<"\nSorted array : ";
    for (int i = 0; i < n; i++)
    {
    std::cout<<arr[i]<<" ";
    }

    return 0;
}