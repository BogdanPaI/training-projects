/***********************************************************
 *                   SINGLY LINKED LIST                    *
 *                                                         *
 * A simple implementation of linked list. Its time        * 
 * complexity for insertion and deletion at the end(top)   *
 * is O(1) if we have head and tail pointers, but for      *
 * access by index and search its time complexity is O(n). *
 *                                                         *
 * For more info check:                                    *
 *        https://en.wikipedia.org/wiki/Linked_list        *
 ***********************************************************/

#ifndef DATA_STRUCT_LINKED_LIST_H_
#define DATA_STRUCT_LINKED_LIST_H_

#include <exception>
#include "ListNode.h"

namespace data_struct{
    template<typename T>
        class LinkedList {
        public:
            // Constructor
            LinkedList() {
                size_ = 0;
                head_ = nullptr;
            }
            
            //Destructor
            ~LinkedList() {
                while (size_ > 0) {
                    RemoveFront();
                }
            }
            
            // Check size of the list
            bool IsEmpty() const {
                return size_ == 0;
            }
            
            // Return size of the list
            int GetSize() const {
                return size_;
            }
            
            // Add item at the front 
            void PushFront(const T& element) {
                ListNode<T> *new_node = new ListNode<T>;
                new_node->SetItem(element);
                new_node->SetNext(head_);
                head_ = new_node;
                ++size_;
            } 
            
            // Return front element and delete node
            const T& PopFront() {
                ListNode<T> *cur_node = head_;
                T item = cur_node->GetItem();
                head_ = cur_node->GetNext();
                delete cur_node;
                return item;
            }
            
            // Return value of the front node
            const T& GetFront() const {
                return head_->GetItem();
            }
            
            // Return value from the node at given index
            const T& ValueAt(int index) const {
                int i = 0;
                ListNode<T> *cur_node = head_;
                while (i != index && cur_node != nullptr) {
                    cur_node = cur_node->GetNext();
                    ++i;
                }
                return cur_node->GetItem();
            }
            
            // Delete front node
            void RemoveFront() {
                ListNode<T> *old_node = head_;
                head_ = old_node->GetNext();
                delete old_node;
                --size_;
            }
            
        private:
            // Size of the list
            int size_;

            // Pointer to the head
            ListNode<T>* head_;

            // Empty list exception
            struct EmptyListException : std::exception {
                const char* what() const throw() {
                    return "List is empty.";
                }
            } empty_list_;        
        };
 }

 #endif