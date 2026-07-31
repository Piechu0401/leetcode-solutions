class Solution {
public:
    inline const int minimumPushes(
        const string& __w
    ) const noexcept {
        int __ls[26]{};
        string __unique{};

        for( auto& __c : __w ) {
            if( !__ls[__c - 97] ) __unique += __c;
            
            ++__ls[__c - 97];
            
        };

        sort( 
            __unique.begin(),
            __unique.end(),
            [&](
                const char& __a,
                const char& __b
            ) -> const bool {
                return __ls[__a - 97] > __ls[__b - 97];
            
            }
        );

        int __res{};
        char __clicks{1};
        char __idx{};

        // cout << __unique << "\n";

        for( auto& __c : __unique ) {
            __res += __clicks * __ls[__c - 97];
            __idx = ( ( ++__idx ) % 8 );
            if( !__idx ) ++__clicks;

        }

        return __res;
        
    }
};