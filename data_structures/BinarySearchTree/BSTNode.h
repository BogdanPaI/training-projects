/*****************************************************
 *                      BST NODE                     *
 *                                                   *
 * A simple implementation of a node of BST.         *
 *****************************************************/

#ifndef DATA_STRUCT_BST_NODE_H_
#define DATA_STRUCT_BST_NODE_H_

namespace data_struct {
    template<typename K, typename T>
        class BSTNode {
        public:
            void SetKey(const K& key) { key_ = key; }
            void SetValue(const T& value) { value_ = value; }
            void SetParent(BSTNode *parent_node) { parent_ = parent_node; }
            void SetLeft(BSTNode *left_node) { left_ = left_node; }
            void SetRight(BSTNode *right_node) { right_ = right_node; }
            const T& GetKey() { return key_; }
            const T& GetValue() { return value_; }
            BSTNode* GetParent() { return parent_; }
            BSTNode* GetLeft() { return left_; }
            BSTNode* GetRight() { return right_; }
            
        private:
            K key_;
            T value_;
            BSTNode *left_;
            BSTNode *right_;
            BSTNode *parent_;
        };
}

#endif
