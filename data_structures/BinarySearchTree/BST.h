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

#include <queue>
#include <iostream>
#include <algorithm>
#include "BSTNode.h"

namespace data_struct {
    template<typename K, typename T>
        class BST {
        public:
            // Default constructor
            BST() {
                height_ = 0;
                amount_of_nodes_ = 0;
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
            bool Search(const K& key) const {
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
                    ++amount_of_nodes_;
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
                    ++amount_of_nodes_;
                } else if (key > previous->GetKey()) {
                    BSTNode<K, T> *new_node = GetNewNode(previous, key, value);
                    previous->SetRight(new_node);
                    ++amount_of_nodes_;
                }
            }
            
            // Return node with minimal key 
            BSTNode<K, T>* GetMin() const {
                BSTNode<K, T> *current = root_;
                BSTNode<K, T> *previous = root_;
                
                while (current != nullptr) {
                    previous = current;
                    current = current->GetLeft();
                }
                
                return previous;
            }
            
            // Return node with maximum key
            BSTNode<K, T>* GetMax() const {
                BSTNode<K, T> *current = root_;
                BSTNode<K, T> *previous = root_;
                
                while (current != nullptr) {
                    previous = current;
                    current = current->GetRight();
                }
                
                return previous;
            }
            
            // Return amount of nodes in the tree
            unsigned int GetNodesAmount() const {
                return amount_of_nodes_;
            }
            
            // Return height of the tree
            unsigned int GetHeight() {
                return HeightInternal(root_);
            }

            // Level-order traversal in BST(Breadth first search)
            void LevelOrder() {
                if (root_ == nullptr) {
                    return;
                } else {
                    std::queue<BSTNode<K, T>*> order;
                    order.push(root_);

                    while (!order.empty()) {
                        BSTNode<K, T>* current = order.front();
                        order.pop();
                        std::cout << current->GetKey() << " ";
                        
                        if (current->GetLeft() != nullptr) {
                            order.push(current->GetLeft());
                        }

                        if (current->GetRight() != nullptr) {
                            order.push(current->GetRight());
                        }
                    }
                }
            }

        private:
            // Internal function that recursively finds height of the tree
            unsigned int HeightInternal(BSTNode<K, T>* node) {
                if (node == nullptr) {
                    return 0;
                } else {
                    return std::max(HeightInternal(node->GetLeft()), HeightInternal(node->GetRight())) + 1;
                }
            }
            
        private:
            BSTNode<K, T> *root_;
            unsigned int amount_of_nodes_;
            unsigned int height_;
        };
}

#endif
