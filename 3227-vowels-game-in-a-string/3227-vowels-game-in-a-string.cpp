class Solution {
public:
    inline const bool doesAliceWin(
        const string& __s
    ) const noexcept {
        int __res{};

        for( auto& __c : __s )
            if(
                __c == 'a' ||
                __c == 'e' ||
                __c == 'i' ||
                __c == 'o' ||
                __c == 'u'
            ) ++__res;

        return __res; 
        
    }
};