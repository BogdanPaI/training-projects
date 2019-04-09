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
            ~Heap() { delete [] data_; }
            // Function that returns size of heap
            size_t GetSize() const { return size_; }
            // Function that checks emptiness of heap
            bool IsEmpty() const { return size_ == 0; }
            // Function that inserts element at the end of array
            void Insert(const T& item) {
                if ( size_ < capacity_) {
                    data_[++size_] = item;
                } else {
                    throw std::overflow_error("Heap is full.")                
                }
            };
            // Function that returns the max item
            T& GetMax() { return data_[1]; }
        private:
            // The upword restoration of pyramidal structure of heap(need for insertion)
            void Up();
            // Descending restoration of pyramidal structure of heap(nead for GetMax function)
            void Down();
        private:
            T *data_;
            size_t size_;
            size_t capacity_;
        };
}
#endif