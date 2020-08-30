class Solution1 {
public:
    string ReverseSentence(string str) {
        auto size = str.size();
        if(size == 0) return "";
        int mark=0;
        str += ' ';
        for(int i = 0; i < size+1; ++i){
            if(str[i] == ' '){
                ReverseWord(str, mark, i-1);
                mark = i+1;
            }
        }
        str = str.substr(0, size);
        ReverseWord(str, 0, size-1);
        return str;
    }
    void ReverseWord (string &str, int l, int r){
        while(l < r){
            swap(str[l], str[r]);
            ++l;
            --r;
        }
    }
};


class MySolution {
public:
   void reverseStr(string &str,int start, int end)
   {
       int length = end - start + 1;
       if(length < 2) return ;
       while(start < end)
       {
           char tmpChar = str[start];
           str[start] = str[end];
           str[end] = tmpChar;
           start++;
           end--;
       }    
   }
        
    string ReverseSentence(string str) {
        
        reverseStr(str,0,str.length()-1);
        int length = str.length();
        int pos = 0;
        int end = 0;
        int start = 0;
        while(pos < length)
        {
            if(str[pos] == ' ')
            {
                end = pos;
                reverseStr(str,start,end-1);
                start = end + 1;
            }
            else if(pos == length -1)
            {
                reverseStr(str,start,pos);
            }                      
            pos++;           
        }
        return str;
    }
};