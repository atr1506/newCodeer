class Solution {
public:
    /**
     * 验证IP地址
     * @param IP string字符串 一个IP地址字符串
     * @return string字符串
     */
    string solve(string IP) {
        // write code here
        if(IP.find('.')!= string::npos)
        {
            auto subStrBegin = IP.begin();
            auto countDot = 0;
            for(auto it = IP.begin();it!=IP.end();it++)
            {
                 if( *it == '.')
                 {
                     string subst(subStrBegin,it);
                     if(subst.empty())   return "Neither";
                     if(subst[0] == '0') return "Neither";
                     if(stoi(subst) >255 ) return "Neither";
                     subStrBegin = it+1;
                     countDot++;
                 }
             }
            return "IPv4";
          
        }
        else if(IP.find(':')!= string::npos)
        {
            auto subStrBegin = IP.begin();
            auto countDot = 0;
            for(auto it = IP.begin();it!=IP.end();it++)
            {
                 if( *it == ':')
                 {
                     string subst(subStrBegin,it);
                     if(subst.empty())   return "Neither";
                     if(subst.length() > 4) return "Neither";
                     subStrBegin = it+1;
                     countDot++;
                 }
             }
            return "IPv6";
        }
        else
        {
            return "Neither";
        }
    }
};