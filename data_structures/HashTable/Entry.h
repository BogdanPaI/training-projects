/******************************************************
 *                       ENTRY                        *
 *                                                    *
 * A simple implementation of an entry of hash table. *
 ******************************************************/

#ifndef DATA_STRUCT_HASH_ENTRY_H_
#define DATA_STRUCT_HASH_ENTRY_H_

#include <string>

namespace data_struct {
    template<typename T>
        class Entry {
        public:
			Entry() {};
			~Entry() {};
            void SetKey(const std::string& key) { key_ = key; };
            void SetValue(const T& value) { value_ = value; };
            const std::string& GetKey() { return key_; };
            const T& GetValue() { return value_; };
        private:
            std::string key_;
            T value_;
        };
}

#endif