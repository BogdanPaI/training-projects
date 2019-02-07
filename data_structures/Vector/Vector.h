/***********************************************************
 *                         VECTOR                          *
 *                                                         *
 * A simple implementation of dynamic array. Its time      *
 * complexity for insertion(deletion) at the top and       *
 * access by index is O(1), but for insertion or           *
 * deletion in random cell and search its time complexity  *
 * is O(n).                                                *
 *                                                         *
 * For more info check:                                    *
 *        https://en.wikipedia.org/wiki/Dynamic_array      *
 ***********************************************************/

#ifndef DATA_STRUCT_VECTOR_H_
#define DATA_STRUCT_VECTOR_H_

#include <exception>

namespace data_struct {
    template<typename T>
        class Vector {
        public:
            // Standard constructor
            Vector() {
                size_ = -1;
                capacity_ = 8;
                data_ = new T[capacity_];
            }
            
            // Constructor with custom capacity
            Vector(int capacity) {
                size_ = -1;
                capacity_ = capacity;
                data_ = new T[capacity_];
            }
            
            // Destructor
            ~Vector() {
                delete[] data_;
            }
            
            // Return size of vector
            int GetSize() const {
                return size_;
            }
            
            // Return capacity of vector
            int GetCapacity() const {
                return capacity_;
            }
            
            // Check size of vector
            bool IsEmpty() const {
                return size_ == -1;
            }
            
            // Return element at given index
            const T& At(int index) {
                if (index >= 0 && index <= size_) {
		            return data_[index];
	            } else {
                    throw out_of_bounds_;
                }    
            }
            
            // Add element at the top of vector
            void Push(const T& item) {
                if (size_ >= capacity_) {
                    Resize();
                }

                data_[++size_] = item;
            }
            
            // Add element in position by index
            void Insert(int index, const T& item) {
                if (size_ >= capacity_) {
                    Resize();
                }

                for (int i = size_; i >= index; ++i) {
                    data_[++i] = data_[i];
                }

                data_[index] = item;
                ++size_;
            }
            
            // Return element from top of vector
            const T& Pop() {
                if (size_ != -1 && size_ <= capacity_) {
                    return data_[size_];
                } else {
                    throw out_of_bounds_;
                }
            }
            
            // Delete element by index
            void Delete(int index) {
                for (int i = index; i < size_ - 1; ++i) {
                    data_[i] = data_[++i];
                }
                --size_;
            }
           
        private:
            // Amount of elements in vector
            int size_;

            // Maximum possible amount of elements before resize
            int capacity_;

            // Array that stores elements
            T *data_;

            // Resize vector when size bigger or equal to capacity
            void Resize() {
                int new_capacity = capacity_ * 2;
                T *new_data = new T[new_capacity];

                for (int i = 0; i < size_; ++i) {
                    new_data[i] = data_[i];
                }

                data_ = std::move(new_data);
            }

            // Index out of bounds exception
            struct IndexOutOfBounds : std::exception {
                const char* what() const throw() {
                    return "Index out of bounds.";
                }
            } out_of_bounds_;
        };
}

#endif
