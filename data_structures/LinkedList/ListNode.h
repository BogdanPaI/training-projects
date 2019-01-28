/*****************************************************
 *                        NODE                       *
 *                                                   *
 * A simple implementation of a node of linked list. *
 *****************************************************/

#ifndef DATA_STRUCT_LIST_NODE_H_
#define DATA_STRUCT_LIST_NODE_H_

namespace data_struct {
    template<typename T>
        class ListNode {
        public:

            void SetItem(const T& item) {
                item_ = item;
            }

            void SetNext(ListNode<T> *next) {
                next_ = next;
            }

            const T& GetItem() const {
                return item_;
            }

            ListNode<T>* GetNext() {
                return next_;
            }

        private:
            T item_;
            ListNode<T>* next_;
        };
 }

 #endif