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
            BSTNode<K, T>* GetNewNode(BSTNode<K, T>* parent, const K& key, const T& value) {
                BSTNode<K, T> *new_node = new BSTNode<K, T>;
                new_node->SetKey(key);
                new_node->SetValue(value);
                new_node->SetParent(parent);
                new_node->SetLeft(nullptr);
                new_node->SetRight(nullptr);
                return new_node;
            }
            
            // Searching node in the tree
            bool Search(const K& key) {
                BSTNode<K, T> *temp = root_;
                while (temp != nullptr) {
                    if (key < temp-> GetKey()) {
                        temp = temp->GetLeft();
                    } else if (key > temp->GetKey()) {
                        temp = temp->GetRight();
                    } else {
                        return true;
                    }
                }
                return false;
            }
            
            // Inserting new node in the tree
            void Insert(const K& key, const T& value) {
				if (root_ == nullptr) {
					root_ = GetNewNode(root_, key, value);
					return;
				}

                BSTNode<K, T> *current = root_;
                BSTNode<K, T> *previous = root_;

                while (current != nullptr) {
                    if (key < current-> GetKey()) {
                        previous = current;
                        current = current->GetLeft();
                    } else if (key > current->GetKey()) {
                        previous = current;
                        current = current->GetRight();
                    }
                }

				if (key < previous->GetKey()) {
					BSTNode<K, T> *new_node = GetNewNode(previous, key, value);
					previous->SetLeft(new_node);
				} else if (key > previous->GetKey()) {
					BSTNode<K, T> *new_node = GetNewNode(previous, key, value);
					previous->SetRight(new_node);
				}
            }

        private:
            BSTNode<K, T> *root_;
            unsigned int height_;
        };
}

#endif