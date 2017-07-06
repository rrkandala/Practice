class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        
        int last = str.length() - 1;
        
        for(int i = 0; i < str.length() / 2; i++)
        {
            if(str[i] != str[last])
            {
                return false;
            }
            
            last --;
        }
        
        return true;
    }
};