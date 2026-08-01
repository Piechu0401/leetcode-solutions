class Solution {
public:
    inline const int sumBase(
        int& __n, 
        const int& __k
    ) const noexcept {
        int __res{};
        int __p{__k};

        while( __p * __k < __n ) __p *= __k;

        while( __p ) {
            int __c{};

            while( ( __c + 1 ) * __p <= __n ) ++__c;

            // cout << __c << " " << __p << "\n";

            __n -= __c * __p;
            __p /= __k;
            __res += __c;

        }

        return __res;
        
    }
};