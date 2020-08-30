class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) 
{
        if(numbers == NULL || length == 0 ) return false;
        map<int,int> numMap;
        for(int i=0;i<length;i++)
        {
            numMap[numbers[i]]++;
        }
        
        for(auto num:numMap)
        {
            if(num.second > 1) 
            {
                *duplication = num.first;
                return true;
            }                     
        }
        return false;
}
}；