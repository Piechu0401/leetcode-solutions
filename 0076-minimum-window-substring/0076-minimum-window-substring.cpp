class Solution {
public:
    inline const string minWindow(
        const string& __s, 
        const string& __t
    ) const noexcept {
        if( __s.length() < __t.length() ) return "";
        if( __s == __t ) return __s;

        int __l{};
        int __r{0};

        string __res( __s.length(), 'Z' );
        unordered_map<char, int> __sum;
        unordered_map<char, int> __tum;

        auto __isAll = [&]() -> const bool {
            if( __sum.size() < __tum.size() ) return 0;

            for( auto& __e : __tum )
                if( __sum[__e.first] < __e.second ) return 0;

            return 1;

        };

        for( auto& __c : __t ) ++__tum[__c];

        char __valid = 0;

        while(
            __r < __s.length() &&
            !__valid
        ) {
            if( __tum.count( __s[__r] ) ) ++__sum[__s[__r]];

            __valid = __isAll();

            if( !__valid ) ++__r;

        }

        if( __r == __s.length() && !__valid ) return "";

        while(
            __l < __r &&
            __valid && (
                !__tum.count( __s[__l] ) ||
                __sum[__s[__l]] > __tum[__s[__l]] 
            )
        ) {
            if(
                __tum.count( __s[__l] ) &&
                __sum[__s[__l]] > __tum[__s[__l]] 
            ) --__sum[__s[__l]];

            __valid = __isAll();

            if( __valid ) ++__l;

        }

        __res = __s.substr( __l, __r - __l + 1 );

        while( __r < __s.length() ) {
            // cout << __l << "\n";
            if( __tum.count( __s[__l] ) ) {
                --__sum[__s[__l]];
                if( !__sum[__s[__l]] ) __sum.erase( __s[__l] );

            }

            ++__l;
            ++__r;

            __valid = __isAll();

            while(
                __r < __s.length() &&
                !__valid
            ) {
                if( __tum.count( __s[__r] ) ) ++__sum[__s[__r]];

                __valid = __isAll();

                if( !__valid ) ++__r;

            }

            if( __valid && __r - __l + 1 < __res.length() ) __res = __s.substr( __l, __r - __l + 1 );

            while(
                __l < __r &&
                __valid && (
                    !__tum.count( __s[__l] ) ||
                    __sum[__s[__l]] > __tum[__s[__l]] 
                )
            ) {
                if(
                    __tum.count( __s[__l] ) &&
                    __sum[__s[__l]] > __tum[__s[__l]] 
                ) --__sum[__s[__l]];

                __valid = __isAll();

                if( __valid ) ++__l;

            }

            if( __valid && __r - __l + 1 < __res.length() ) __res = __s.substr( __l, __r - __l + 1 );

        }
        
        // cout << (int)__l << " " << (int)__r << "\n";

        return __res;

    }
};

// ABC              A = 1, B = 1, C = 1
// ADOBECODEBANC    A = 2, B = 2, C = 2