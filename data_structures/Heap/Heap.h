#ifndef HEAP_STRUCT_H
#define HEAP_STRUCT_H

#include <stdexcept>

namespace data_struct {
    template<typename T>
        class Heap {
        public:
            // Default constructor
            Heap(size_t capacity) {
                size_ = 0;
                capacity_ = capacity;
                data_ = new T[capacity_];
            }

            // Destructor
            ~Heap() { delete[] data_; }

            // Function that returns size of heap
            size_t GetSize() const { return size_; }

            // Function that checks emptiness of heap
            bool IsEmpty() const { return size_ == 0; }

            // Function that inserts element at the end of array
            void Insert(const T& item) {
                if ( size_ < capacity_ ) {
                    data_[++size_] = item;
                    Up(size_);
                } else {
                    throw std::overflow_error("Heap is full.");                
                }
            }

            // Function that returns the max item
            T& GetMax() { 
                T max = data_[1];
                data_[1] = data_[size_];
                data_[size_] = NULL;
                size_--;
                Down(1);
                return max;
            }

        private:
            // The upword heapifying(need for insertion)
            void Up(size_t i) {
                while ( i > 1 && data_[i / 2] < data_[i] ) {
                    T swap = data_[i / 2];
                    data_[i / 2] = data_[i];
                    data_[i] = swap;
                    i = i / 2;
                }
            }

            // Descending heapifying(nead for GetMax function)
            void Down(size_t i) {
                while ( 2*i <= size_) {
                    size_t j = 2*i;
                    if (j < size_ && data_[j] < data_[j + 1]) {
                        j++;
                    }
                    if ( !(data_[i] < data_[j]) ) {
                        break;
                    }
                    T swap = data_[j];
                    data_[j] = data_[i];
                    data_[i] = swap;
                    i = j;
                }
            }

        private:
            T *data_;
            size_t size_;
            size_t capacity_;
        };
}
#endif