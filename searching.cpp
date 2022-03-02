
#include <iostream>

using namespace std;
class Searching{
    public :
    int binarySearchIterative(int arr[], int n, int x){
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high- low)/2;
            if(arr[mid] == x)
            return mid;
            else if(arr[mid] > x){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return -1;
    }
    int binarySearchRescurive(int arr[],int low,int high, int x){
        
        if(low > high)
        return -1;
        
        int mid = low + (high - low)/2;
        
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]>x)
            binarySearchRescurive(arr,low,mid-1,x);
        else
            binarySearchRescurive(arr,mid+1,high,x);
            
    }
    int firstIdx(int arr[], int low ,int high, int x){
       if(low > high)
        return -1;

       int mid = low + (high - low)/2;
       
        if(arr[mid] > x)
             return firstIdx(arr,low,mid-1,x);

        else if(arr[mid] < x)
           return firstIdx(arr,mid+1,high,x);

        else{
            
            if( arr[0]== mid || arr[mid] != arr[mid-1])
                 return mid;
            
            else{
                return firstIdx(arr,low,mid-1,x);
            }
        }

    }
    
};

int main()
{
    Searching S1;
    int arr[] = {10,15,30,50,50};
    //cout << S1.binarySearchIterative(arr,4,50) << endl;
   // cout << S1.binarySearchRescurive(arr,0,4,50) << endl;
    cout << S1.firstIdx(arr,0,4,50) << endl;

    return 0;
}
