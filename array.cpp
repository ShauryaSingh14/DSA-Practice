
#include <iostream>
#include <climits>
using namespace std;
void printArr(int arr[], int n){
    for(int i =0 ; i<n ;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
class Array{
   public : 
   void deleteFun(int arr[], int n, int m){
       int j;
       for(int i = 0 ; i< n ; i++){
           if(arr[i]==m){
               j = i;
               break;
           }
       }
       for(int i =j; i < n ; i++){
           arr[i]= arr[i+1];
       }
       arr[n-1]=0;
   }
   int largestElement(int arr[], int n){
       int idx = 0;
       for(int i =1; i< n ;i++){
           if(arr[i]>arr[idx])
               idx = i;
       }
       return idx;
   }
   int secondLargestElement(int arr[], int n){
      int idx = 0;
       for(int i =1; i< n ;i++){
           if(arr[i]>arr[idx])
               idx = i;
       }
       int res =-1;
      for(int i = 0 ; i< n ; i++){
          if(arr[i]!=arr[idx]){
              if(res == -1)
              res =i;
              
              if(arr[i]>arr[res])
              res =i;
          }
      }
      return res;
   }
   int efficientSecondL(int arr[], int n){
       int idx =0;
       int res =-1;
       for(int i =0; i< n ; i++){
           if(arr[i]>arr[idx]){
               res = idx;
               idx = i;
           }
           else if(arr[i]!=arr[idx]){
               if(res == -1 || arr[i]> arr[res])
               res = i;
           }
       }
       return res;
   }
   bool checkSortA(int arr[], int n){
       for(int i =0, j=n-1; i<j ; i++, j--){
           if(arr[i]>arr[j])
           return false;
       }
       return true;
   }
   void reverseArr(int arr[], int n){
       for(int i = 0 , j =n-1 ; i<j;i++,j--){
           int temp = arr[i];
           arr[i] = arr[j];
           arr[j] = temp;
       }
   }
   void removeDul(int arr[], int n){
      int res = 1;
      for(int i =0; i< n ; i++){
          if(arr[i]!=arr[res-1]){
              arr[res]=arr[i];
              res++;
          }
      }
   }
   void removeZeros(int arr[], int n){
       int res = 0;
       for(int i =0; i< n ; i++){
           if(arr[i]!=0){
               swap(arr[i],arr[res]);
               res++;
           }
       }
   }
   void lRotate(int arr[], int n){
          int temp = arr[0];
          for(int i = 0 ; i < n-1; i++ ){
              arr[i]=arr[i+1];
          }
          arr[n-1]=temp;
   }
   void nlRotateNative(int arr[], int n, int d){
       int temp[d];
       for(int i =0; i<d;i++){
           temp[i] = arr[i];
       }
       for(int i = d; i<n ; i++){
           arr[i-d]=arr[i];
       }
       for(int i=d; i<n ; i++){
           arr[i]=temp[i-d];
       }
   }
   void nlRotateEfficient(int arr[], int n , int d){
       int low = 0;        // revserse Function on arr from 0 to d-1
       int high = d-1;
       while(high > low ){
           swap(arr[low],arr[high]);
           low ++;
           high --;
       }
       low = d;
       high = n -1;
       while(high > low ){ // revserse Function on arr from d to n-1
           swap(arr[low],arr[high]);
           high --;
           low++;
       }
       low = 0;
       high = n-1;
       while(high > low ){ // revserse Function on arr from 0 to n-1
           swap(arr[low],arr[high]);
           high --;
           low++;
       }
   }
   void leaderNative(int arr[], int n){
       for(int i =0; i<=n-1 ; i++){
           bool flag = true;
           for(int j =i+1; j<=n-1; j++){
               if(arr[i] <= arr[j]){
                   flag = false;
                   break;
               }
           }
           if(flag)
           cout << arr[i];
       }
   }
   
   void leaderEfficient(int arr[], int n){
       int currLeader = n-1;
       cout << currLeader << " ";
       for(int i =n-2; i>0; i--){
           if(currLeader<arr[i]){
               currLeader = arr[i];
               cout << arr[i] << " ";
           }
       }
   }
   int maxDiff(int arr[], int n){
       int max = arr[0];
       int min = arr[1];
       
       for(int i =0; i< n ; i++){
           if(arr[i]>max)
           max = arr[i];
           if(arr[i]<min)
           min = arr[i];
       }
       return max - min;
   }
   void feq(int arr[], int n){
       int i =0;
       while(i < n){
           int count = 0; 
           int j;
           for(j =i; arr[i]==arr[j]; j++)
               count++;
        cout << arr[i] << " " << count << endl;
        i = i +j+1;
       }
   }
};

int main()
{
    Array a;
    int arr[] = {0,2,10,4,8,5};
    
   /* a.deleteFun(arr,6,3);
    printArr(arr,6);
    
    cout << a.largestElement(arr,6) << endl;
    
    cout << a.secondLargestElement(arr,6) << endl;
    
    cout << a.efficientSecondL(arr,6)<< endl;
    
    cout << a.checkSortA(arr,6) << endl;
    
    a.reverseArr(arr,6);
    printArr(arr,6);
    
    a.removeDul(arr,6);
    printArr(arr,6);
    
    a.removeZeros(arr,6);
    printArr(arr,6);
    
    a.lRotate(arr,6);
    printArr(arr,6);
    
    a.nlRotateNative(arr,6,3);
    printArr(arr,6);
    
    a.nlRotateEfficient(arr,6,3);
    printArr(arr,6);
    a.leaderNative(arr,6);
    
    cout << a.maxDiff(arr,6);
    */
    a.feq(arr,6);
    return 0;
}
