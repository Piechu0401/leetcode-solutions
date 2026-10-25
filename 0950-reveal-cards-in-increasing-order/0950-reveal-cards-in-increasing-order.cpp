class Solution {
public:
    inline const vector<int> deckRevealedIncreasing(
        vector<int>& __d
    ) const noexcept {
        vector<int> __res = __d;
        vector<int> __dSorted = __d;
        queue<int> __q;

        sort( __dSorted.begin(), __dSorted.end(), less<int>() );

        for( int __i{}; __i < __d.size(); ++__i ) __q.push( __i );

        int __idx{};

        while( __q.size() ) {
            __res[__q.front()] = __dSorted[__idx];
            // cout << __q.front() << " " << __idx << "\n";
            __q.pop();

            if( !__q.size() ) break;

            ++__idx;

            __q.push( __q.front() );
            __q.pop();

        }

        return __res;

    }
};

// 2,3,5,7,11,13,17
// 0  5 1  4 2  6 3
// 2,13,3,11,5,17,7