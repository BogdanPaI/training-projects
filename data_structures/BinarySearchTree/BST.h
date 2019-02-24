/********************************************************
 *                   Binary search tree                 *
 *                                                      *
 * A simple implementation of a binary search tree(BST).*
 *                                                      *
 * For more info check:                                 *
 *   https://en.wikipedia.org/wiki/Binary_search_tree   *
 ********************************************************/

#ifndef DATA_STRUCT_BST_H
#define DATA_STRUCT_BST_H

#include "BSTNode.h"

namespace data_struct {
    template<typename K, typename T>
        class BST {
        public:
            // Default constructor
            BST() {
                height_ = 0;
                root_ = nullptr;
            }
            
            // Destructor
            ~BST() {}
            
            // Function that return new node of BST
            BSTNode* GetNewNode(BSTNode* parent, const K& key, const T& value) {
                BSTNode *new_node = new BSTNode;
                new_node->SetKey(key);
                new_node->SetValue(value);
                new_node->SetParent(parent);
                new_node->SetLeft(nullptr);
                new_node->Setright(nullptr);
                return new_node;
            }

            BSTNode* Search(const K& key) {
                BSTNode *temp = root_;
                while (temp != nullptr && key != temp->GetKey()) {
                    if (key < temp-> GetKey()) {
                        temp = temp->GetLeft();
                    } else if (key > temp->GetKey()) {
                        temp = temp->GetRight();
                    }
                }
                return temp;
            }

        private:
            BSTNode *root_;
            unsigned int height_;
        };
}

#endif