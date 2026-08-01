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
        Node* __r,
        vector<int>& __res
    ) const noexcept {
        if( !__r ) return;

        for( auto& __n : __r->children ) {
            doTheTrick(
                __n,
                __res
            );

            __res.emplace_back( __n->val );

        }

    }

    inline const vector<int> postorder(
        Node* __r
    ) const noexcept {
        if( !__r ) return {};

        vector<int> __res;

        doTheTrick(
            __r,
            __res
        );

        __res.emplace_back( __r->val );

        return __res;

    }
};