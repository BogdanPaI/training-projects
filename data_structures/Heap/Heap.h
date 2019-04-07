#ifndef HEAP_STRUCT_H
#define HEAP_STRUCT_H

namespace data_struct {
    template<typename T>
        class Heap {
        public:
            // Default constructor
            Heap(size_t size);
            // Destructor
            ~Heap();
            // Function that returns size of heap
            size_t GetSize() const;
            // Function that checks emptiness of heap
            bool IsEmpty() const;
            // Function that inserts element at the end of array
            void Insert(const T& item);
            // Function that returns the max item
            T& GetMax();
        private:
            // The upword restoration of pyramidal structure of heap(need for insertion)
            void Up();
            // Descending restoration of pyramidal structure of heap(nead for GetMax function)
            void Down();
        private:
            T *data_;
            size_t size_;
        };
}
#endif