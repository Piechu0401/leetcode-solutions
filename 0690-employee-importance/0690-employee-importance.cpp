/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    inline const int getImportance(
        vector<Employee*>&  __es, 
        int&                __id
    ) const noexcept {
        int __res{};
        unordered_map<int, pair<int, vector<int>>> __um;
        unordered_set<int> __used;
        queue<int> __q;

        for( auto& __e : __es ) __um[__e->id] = { __e->importance, __e->subordinates };

        __q.push( __id );

        while( __q.size() ) {
            __res += __um[__q.front()].first;

            for( auto& __sub : __um[__q.front()].second )
                if( !__used.count( __sub ) ) {
                    __used.insert( __sub );
                    __q.push( __sub );

                }
            
            __q.pop();

        }

        return __res;
        
    }
};