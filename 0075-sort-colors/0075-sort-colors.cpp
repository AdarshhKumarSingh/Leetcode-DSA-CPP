class Solution {
public:
    void sortColors(vector<int>& arr) {
        int j = 0;
        int zero = 0 , one = 0 , two = 0 ;

        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                zero++;
            }
            else if(arr[i]==1){
                one++;
            }
            else if(arr[i]==2){
                two++;
            }
        }

    for(int i = 0; i < zero; i++)
            arr[i] = 0;

        for(int i = zero; i < zero + one; i++)
            arr[i] = 1;

        for(int i = zero + one; i < arr.size(); i++)
            arr[i] = 2;
    }
    
};