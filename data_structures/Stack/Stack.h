/****************************************************
 *                      STACK                       *
 *                                                  *
 * A simple implementation of stack. It is ADT that * 
 * works with LIFO(last in, first out) paradigm.    * 
 * Its time complexity for insertion and deletion   *
 * at the top is O(1), but for random access and    *
 * search its time complexity is O(n).              *
 ****************************************************/

#ifndef DATA_STRUCT_STACK_H_
#define DATA_STRUCT_STACK_H_

#include <exception>

namespace data_struct {
    template<typename T>
        class Stack {
        public:
            // Default constructor
	    Stack() {
	        size_ = 0;
		data_ = new T[CAPACITY];
	    }

            // Copy constructor
            Stack(const Stack &obj) {
                size_ = obj.size_;
		data_ = new T[CAPACITY];
                for (int i = 0; i < size_; i++) {
                    data_[i] = obj.data_[i];
                }
            }

	    // Assignment operator
	    Stack& operator = (const Stack &obj) {
	        if (this == &obj) {
		    throw self_assignment_;
		} else {
		    delete[] data_;
		    size_ = obj.size_;
		    data_ = new T[CAPACITY];
		    for (int i = 0; i < size; i++) {
			data_[i] = obj.data_[i];
		    }
		}
		return *this;
	    }

            // Destructor
            ~Stack() {
                delete[] data_;
            }
                
            // Check size
            bool IsEmpty() const {
                return size_ == 0;
            }

            // Return size of stack
            int GetSize() const {
                return size_;
            }

            // Add element at the top of stack
            void Push(const T& item) {
                if (size_ >= CAPACITY) {
		    throw full_stack_;
                } else {
                    data_[size_] = item;
                    size_++;
                }
            }

            // Delete element from top
            void Pop() {
                if (size_ == 0) {
		    throw empty_stack_;
                } else {
                    size_--;
                }
            }

            // Return element from top of stack
            const T& Top() {
                if (size_ == 0) {
		    throw empty_stack_;
                } else {
                    int top = size_;
		    return data_[--top];
                }
            }
                
        private:
            // Capacity of stack
            static const int CAPACITY = 10;

            // Size of stack
            int size_;

            // Array that holds items
            T *data_;

	    // Empty stack exception
	    struct EmptyStackException : std::exception {
	        const char* what() const throw() {
		    return "Stack is empty.";
	        }
	    } empty_stack_;

	    // Index out of bounds exception
            struct FullStackException : std::exception {
		const char* what() const throw() {
		    return "Stack is full.";
		}
	    } full_stack_;

            // Self assignment exception
	    struct SelfAssignmentStackException : std::exception {
		const char* what() const throw() {
		    return "Self assignment.";
		}
	    } self_assignment_;
        };
}
#endif
