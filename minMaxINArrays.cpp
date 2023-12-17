#include<iostream>
#include<algorithm>

int main(){
    int arr[] = {10, 5, 6, 3, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int min_element = *std::min_element(arr , arr+n);
    std::cout<<"Minimum element is = "<<min_element<<std::endl;
    int max_element = *std::max_element(arr , arr+n);
    std::cout<<"Maximum element is = "<<max_element<<std::endl;
    return 0;
}