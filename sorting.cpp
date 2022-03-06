#include <iostream>
#include <vector>
using namespace std;
void printVec(vector <int> &v )
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", ";
    }
    cout << endl;
}
class Sorting{
    public : 
    void inserationSort(vector <int> &arr){
        int n = arr.size();
        for(int i =0 ; i<n; i++){
            int temp = arr[i];
            int j =i;
            while(j>0 && arr[j-1]>temp){
                arr[j]=arr[j-1];
                j = j-1;
                arr[j]=temp;
            }
        }
    }
    vector <int> merge(vector <int> arr1, vector <int> arr2){
        int ptr1 = 0;
        int ptr2 = 0;
        vector <int> temp;
        while( ptr1 < arr1.size() && ptr2 < arr2.size()){
            if(arr1[ptr1]<=arr2[ptr2]){
               temp.push_back(arr1[ptr1]);
               ptr1++;
            }
            else {
                temp.push_back(arr2[ptr2]);
                ptr2++;
            }
        }
        
        while(ptr1 != arr1.size()){
            temp.push_back(arr1[ptr1]);
            ptr1++;
        }
        while(ptr2 != arr2.size()){
                temp.push_back(arr2[ptr2]);
                ptr2++;
        }
        return temp;
    }
    void mergeFun(vector <int> &v, int low,int mid, int high){
        int n1 = mid - low +1;
        int n2 = high - mid;
        vector <int> left;
        vector <int> right;
        for(int i = 0 ; i< n1 ; i++){
            left.push_back(v[i+low]);
        }
        for(int i = 0 ; i< n2; i++){
            right.push_back(v[i+mid+1]);
        }

        int ptr1 = 0 ;
        int ptr2 = 0;
        int i;
        for(i = low ; ptr1 < n1 && ptr2 < n2 ; i++){
            if(left[ptr1]<=right[ptr2]){
                v[i] = left[ptr1];
                ptr1++;
            }
            else{
                v[i] = right[ptr2];
                ptr2++;
            }
        }
        
        while(ptr1 < n1){
            v[i] = left[ptr1];
            ptr1++;
        }
        while(ptr2 < n2){
            v[i]= right[ptr2];
            ptr2++;
        }

    }
    void mergeSort(vector <int> &vec, int low , int high){
        if(low < high){
            int mid = low + (high-low)/2;
            mergeSort(vec,low,mid);
            mergeSort(vec,mid+1,high);
            mergeFun(vec,low,mid,high);
        }
    }
    void intersectionOfSortedArr(vector <int> arr1, vector <int>arr2){
        int ptr1 = 0;
        int ptr2 = 0;
        for(int i =0 ; i< min(arr1.size(),arr2.size()); i++){
            if(arr1[ptr1]<arr2[ptr2])
                ptr1++;
            else if(arr1[ptr1]>arr2[ptr2])
                ptr2++;
            else{
             cout << arr1[ptr1]<<", ";
             ptr1++;
             ptr2++;
            }
            
        }
    }
    void unionOfSortedArr(vector <int> arr1, vector <int> arr2){
        int ptr1 = 0; 
        int ptr2 = 0;
        while( ptr1 < arr1.size() && ptr2 < arr2.size() ){

            if(ptr1 > 0 && arr1[ptr1] == arr1[ptr1-1]){
                ptr1 ++;
                continue;
            }
            if(ptr2 > 0 && arr2[ptr2] == arr2[ptr2-1]){
                ptr2 ++;
                continue;
            }
            
            if( arr1[ptr1] < arr2[ptr2] ){
                 cout << arr1[ptr1] <<", "; 
                 ptr1++;
            }
            else if( arr1[ptr1] > arr2[ptr2] ){
                 cout << arr2[ptr2] << ", ";
                 ptr2++;
            }
            else{
                cout << arr1[ptr1] <<", ";
                ptr1 ++;
                ptr2 ++;
            }
        }
        while(ptr1 < arr1.size()){
            if(ptr1 > 0 && arr1[ptr1]!=arr1[ptr1-1]){
            cout << arr1[ptr1] <<", ";
            ptr1++;
            }
        }
        while(ptr2 < arr2.size()){
           if(ptr2 > 0 && arr2[ptr2]!=arr2[ptr2-1]){
            cout << arr2[ptr2] <<", ";
            ptr2++;
            }
        }
    }
};

int main(){
    Sorting s;
    vector <int> v1 ={3,2,5,6,1};
    // s.inserationSort(v1);
     vector <int> v2 ={2,3,6,8,9};
    // vector <int> temp = s.merge(v1,v2);
    // printVec(v1);
    // printVec(temp);
    
    // vector <int> vec ={10,20,40,20,30};
    // s.mergeFun(vec,0,2,4);
    // printVec(vec);
    
    s.mergeSort(v1,0,4);
    printVec(v1);
    printVec(v2);
    
    //s.intersectionOfSortedArr(v1,v2);
    s.unionOfSortedArr(v1,v2);
    return 0;
}