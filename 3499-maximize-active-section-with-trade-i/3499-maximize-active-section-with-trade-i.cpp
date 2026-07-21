class Solution {
public:
    inline const int maxActiveSectionsAfterTrade(
        const string& __s
    ) const noexcept {
        int __ones{};
        int __max{};
        int __count{1};
        vector<int> __os;
        char __prev{};

        for( auto& __c : __s ) {
            __ones += __c - 48;

            if( 
                __prev &&
                __prev == __c
            ) ++__count;
            else if(
                __prev
            ) {
                __os.emplace_back( __count );
                __count = 1;

            }

            __prev = __c;

        }

        if( __count ) __os.emplace_back( __count );

        // for( auto& __o : __os )
        //     cout << __o << " ";

        if( __os.size() < 3 ) return __ones;

        int __sub{};

        if( !(__s.front() - 48) ) {
            for( int __i{1}; __i < __os.size() - 1; __i += 2 ) 
                if( 
                    __os[__i - 1] + __os[__i + 1] > __max 
                ) __max = __os[__i - 1] + __os[__i + 1];
            
        }
        else if( __os.size() > 3 ) {
            for( int __i{2}; __i < __os.size() - 1; __i += 2 ) 
                if( 
                    __os[__i - 1] + __os[__i + 1] > __max
                ) __max = __os[__i - 1] + __os[__i + 1];

        }

        return __max + __ones;
        
    }
};