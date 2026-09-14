class Solution {
public:
    inline const int minDeletionSize(
        vector<string>& __ss
    ) const noexcept {
        int __res{};
        int __i{};

        while( __i < __ss.front().length() ) {
            char __prev{};
            
            for( auto& __s : __ss ) {
                if( __prev && __prev > __s[__i] ) { ++__res; break; }

                __prev = __s[__i];

            }
            
            ++__i;

        }

        return __res;
        
    }
};