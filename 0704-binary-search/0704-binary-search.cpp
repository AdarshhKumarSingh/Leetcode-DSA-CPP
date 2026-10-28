class Solution {
public:

    int binary(int low,int high,int target,vector<int>&arr){
        if(low>high){
            return -1;
        }

        int mid = (low+high)/2;

        if(arr[mid]>target){
            return binary(low,mid-1,target,arr);
        }else if(arr[mid]<target){
            return binary(mid+1,high,target,arr);
        }else{
            return mid;
        }
    }


    int search(vector<int>& arr, int target){
        int n=arr.size();
        return binary(0,n-1,target,arr);
    }


    // int search(vector<int>& arr, int target) {
    //     int n=arr.size();
    //     int low = 0 , high = n-1;

    //     while(low<=high){
    //         int mid = (low+high)/2;

    //         if(arr[mid]>target){
    //            high = mid-1;
    //         }
    //         else if(arr[mid]<target){
    //             low = mid+1;
    //         }
    //         else if(arr[mid]==target){
    //             return mid;
    //         }
    //     }
    //     return -1;
        
    // }
};