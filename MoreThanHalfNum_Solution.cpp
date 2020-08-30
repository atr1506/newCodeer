class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) 
    {
        if(numbers.empty()) return 0;
        int  count = 0;
        int  moreThanHalfNum = 0;
        for(auto num:numbers)
        {
            if(count == 0)
            {
                moreThanHalfNum = num;
                count++;
            }
            else
            {
                if(num == moreThanHalfNum) count++;
                else count--;     
            }           
        }
        
        if(count > 0)
        {
            auto cnt = 0;
            for(auto num:numbers)
             {
                 if(moreThanHalfNum == num)
                 {
                     cnt++;
                 }
             }
            if(cnt > numbers.size()/2)  return moreThanHalfNum;
            else return 0;
        }
        else    return 0;
    }
};