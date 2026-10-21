class Solution {
public:
    inline const int minOperations(
        const string& __s
    ) const noexcept {
        char __min{CHAR_MAX};
        char __max{};
        char __prev{};
        char __is{1};
        int __maxC{};
        int __minC{};
        
        for( auto& __c : __s ) {
            if( __c < __min ) { __min = __c; __minC = 0; }
            if( __c > __max ) { __max = __c; __maxC = 0; }

            if( __c == __min ) ++__minC;
            if( __c == __max ) ++__maxC;

            __is &= ( __prev <= __c );
            __prev = __c;
 
        }
        
        if( __is ) return 0;
        else if( __s.length() == 2 ) return -1;
        else if(
            __s.front() == __min ||
            __s.back() == __max
        ) return 1;
        else if(
            __minC == 1 &&
            __maxC == 1 &&
            __s.back() == __min &&
            __s.front() == __max
        ) return 3;

        return 2;
        
    }
};