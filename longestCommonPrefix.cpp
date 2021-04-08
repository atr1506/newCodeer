class Solution {
public:
    /**
     * 
     * @param strs string字符串vector 
     * @return string字符串
     */
    string longestCommonPrefix(vector<string>& strs) {
        // write code here
       if(strs.size() == 0) return "";
       int length = strs[0].size();
       auto i=0;
       for(;i<length;i++)
       {
           char c = strs[0][i];
           for(auto str:strs)
           {
               if(i<str.length() && str[i] == c) continue;
               else return strs[0].substr(0,i);
           }         
       }
       return strs[0].substr(0,i);
    }
};