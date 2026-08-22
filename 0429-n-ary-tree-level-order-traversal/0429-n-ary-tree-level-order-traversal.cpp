/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    inline void doTheTrick(
        vector<vector<int>>& __res,
        Node* __r,
        const int& __d
    ) const noexcept {
        if( !__r ) return;

        if( __res.size() == __d ) __res.push_back( { __r->val } );
        else __res[__d].emplace_back( __r->val );

        for( auto& __ch : __r->children )
            doTheTrick(
                __res,
                __ch,
                __d + 1
            );

    }

    inline const vector<vector<int>> levelOrder(
        Node* __r
    ) const noexcept {
        vector<vector<int>> __res;

        doTheTrick(
            __res,
            __r,
            0
        );

        return __res;
        
    }
};