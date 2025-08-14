class Solution {
  public:
    
    void merge(vector<int>& arr,int l,int mid,int r){
        
        int left=l,right=mid+1;
        vector<int> temp;
        while(left<=mid and right<=r){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right<=r){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i=0;i<temp.size();i++){
            arr[l+i]=temp[i];
        }
        
    }
  
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r)return;
        
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        
        merge(arr,l,mid,r);
    }
};
