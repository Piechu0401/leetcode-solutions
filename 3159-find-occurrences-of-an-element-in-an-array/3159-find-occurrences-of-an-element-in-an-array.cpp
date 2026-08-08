class Solution {
public:
    inline const vector<int> occurrencesOfElement(
        const vector<int>& __ns, 
        vector<int>& __qs, 
        const int& __x
    ) const noexcept {
        vector<int> __is;

        for( int __i{}; __i < __ns.size(); ++__i )
            if( __ns[__i] == __x ) __is.emplace_back( __i );

        for( auto& __q : __qs )
            if( __q > __is.size() ) __q = -1;
            else __q = __is[__q - 1];

        return __qs;
        
    }
};