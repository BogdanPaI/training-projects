/*************************************************************
 *                       HASH TABLE                          *
 *                                                           *
 * A simple implementation of hash table with linear probing.*  
 *                                                           *
 * For more info check:                                      *
 *        https://en.wikipedia.org/wiki/Hash_table           *
 *************************************************************/

#ifndef DATA_STRUCT_HASH_TABLE_H_
#define DATA_STRUCT_HASH_TABLE_H_

#include "Entry.h"

namespace data_struct {
    template<typename T>
        class HashTable {
        public:
            HashTable(int capacity) {
                capacity_ = capacity;
				data_ = new Entry<T>[capacity_];

				for (int i = 0; i < capacity_; ++i) {
					data_[i].SetKey("");
				}
            }
			
			~HashTable() {
				delete[] data_;
			}
            
            void Add(Entry<T>& element) {
				int current_index = 0;
				int index = Hash(element.GetKey());
				
				for (current_index = index; data_[current_index].GetKey() != ""; 
					 current_index = (current_index + 1) % capacity_) {
					if (data_[current_index].GetKey() == element.GetKey()) {
						break;
					}
				}
				
				data_[current_index].SetKey(element.GetKey());
				data_[current_index].SetValue(element.GetValue());
            }

			void Remove(const std::string key) {
				int current_index = 0;
				int index = Hash(key);

				for (current_index = index; data_[current_index].GetKey() != "";
					current_index = (current_index + 1) % capacity_) {
					if (data_[current_index].GetKey() == key) {
						data_[current_index].SetKey("");
						data_[current_index].SetValue(NULL);
						break;
					}
				}
			}

			const T& Get(const std::string key) {
				int current_index = 0;
				int index = Hash(key);

				for (current_index = index; data_[current_index].GetKey() != "";
					current_index = (current_index + 1) % capacity_) {
					if (data_[current_index].GetKey() == key) {
						return data_[current_index].GetValue();
					}
				}
				return NULL;
			}

			bool Exists(const std::string key) {
				int current_index = 0;
				int index = Hash(key);

				for (current_index = index; data_[current_index].GetKey() != "";
					current_index = (current_index + 1) % capacity_) {
					if (data_[current_index].GetKey() == key) {
						return true;
					}
				}
				return false;
			}

        private:
            unsigned int Hash(const std::string key) {
                unsigned int h = 0;
                for (int i = 0; i < key.length(); ++i) {
                    h = (h << 5) | (h >> 27);
                    h += (unsigned int) key[i];
                }
				return h % capacity_;
            }
        private:
            int capacity_;
            Entry<T> *data_;
        };
}

#endif