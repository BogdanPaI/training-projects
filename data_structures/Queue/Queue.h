/****************************************************
 *                      QUEUE                       *
 *                                                  *
 * A simple implementation of queue. It is ADT that * 
 * works with FIFO(first in, first out) paradigm.   * 
 * Its time complexity for insertion and deletion   *
 * at the end(top) is O(1), but for random access   *
 * and search its time complexity is O(n).          *
 ****************************************************/

#ifndef DATA_STRUCT_QUEUE_H_
#define DATA_STRUCT_QUEUE_H_

#include <exception>

namespace data_struct {
    template<typename T>
        class Queue {
        public:
            // Constructor       
            Queue() {
                size_ = 0;
                first_ = 0;
                last_ = 0;
                data_ = new T[CAPACITY];
            }

            // Copy constructor
            Queue(const Queue& obj) {
                size_ = obj.size_;
                first_ = obj.first_;
                last_ = obj.last_;
                data_ = new T[CAPACITY];
                for (int i = 0; i < size_; i++) {
                    data_[i] = obj.data_[i];
                }
            }

            // Assignment operator
            Queue& operator = (const Queue& obj) {
                if (this == &obj) {
                    throw self_assignment_;
                } else {
                    delete[] data_;
                    size_ = obj.size_;
                    first_ = obj.first_;
                    last_ = obj.last_;
                    data_ = new T[CAPACITY];
                    for (int i = 0; i < size_; i++) {
                        data_[i] = obj.data_[i];
                    }
                }
            }

            // Destructor
            ~Queue() {
                delete [] data_;
            }            

            // Function that return size of queue
            int GetSize() const {
                return size_;
            }

            // Check size
            bool IsEmpty() const {
                return size_ == 0;
            }

            // Adds the element to the end of the queue
            void Enqueue(const T& item) {
                if (size_ >= CAPACITY) {
                    throw full_queue_;
                } else {
                    data_[last_] = item;
                    last_ = (last_ + 1) % CAPACITY;
                    size_++;
                }
            }

            // Delete first element of queue
            void Dequeue() {
                if (size_ == 0) {
                    throw empty_queue_;
                } else {
                    first_ = (first_ + 1) % CAPACITY;
                    size_--;
                }
            }

            // Return first element of queue
            const T& First() const {
                if (size_ == 0) {
                    throw empty_queue_;
                } else {
                    return data_[first_];
                }
            }

        private:
            // Queue capacity
            static const int CAPACITY = 10;

	    // Array that imitates queue
	    T *data_;

            // Current size of queue
            int size_;

            // First element
            int first_;

            // Last element
            int last_;

            // Full queue exception
            struct FullQueueException : std::exception {
                const char* what() const throw() {
		    return "Queue is full.";
                }
            } full_queue_;

            // Empty queue exception
            struct EmptyQueueException : std::exception {
                const char* what() const throw() {
		    return "Queue is empty.";
                }
            } empty_queue_;

            // Self assignment exception
	    struct SelfAssignmentQueueException : std::exception {
		const char* what() const throw() {
		    return "Self assignment.";
	        }
	    } self_assignment_;
        };
}

#endif
