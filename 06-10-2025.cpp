class Solution {
  public:
  
    void solve(vector<int> arr,vector<string> numberPad,int index,vector<string>& ans,string prefix){
        //base case
        if(index==arr.size()){
            ans.push_back(prefix);
         //   cout<<prefix<<endl;
            return;
        }
        int padValue = arr[index];
        if(padValue<2){
             solve(arr,numberPad,index+1,ans,prefix);
        }
        
        //recursive case
        
        for(auto ch : numberPad[padValue]){
            prefix.push_back(ch);
           // cout<<prefix<<endl;
            solve(arr,numberPad,index+1,ans,prefix);
            prefix.pop_back();
        }
        
    }
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        vector<string> ans;
        
        vector<string> numberPad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(arr,numberPad,0,ans,"");
        return ans;
        
    }
};
