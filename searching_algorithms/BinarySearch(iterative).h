/******************************************************
 *                    BINARY SEARCH                   *
 *                                                    *
 * Implementation of a binary search algorithm.       *
 * The algorithm uses divide and conquer paradigm and *
 * its time complexity is O(log(n)), but its also     *
 * requires a sorted array. If the item is found,     *
 * the function returns the index of this item.       *
 * Otherwise, the function will return -1.            *
 ******************************************************/

#ifndef ALG_SEARCH_BINARY_SEARCH_H_
#define ALG_SEARCH_BINARY_SEARCH_H_

namespace alg_search {
    template<typename T>
    int BinarySearch(T *arr, T search_element, int size) {
        int begin = 0, end = size;

        while (begin < size) {
            int mid = (begin + end) / 2;
            if (arr[mid] == search_element) {
                return mid;
            } else if (arr[mid] > search_element) {
                end = mid - 1;
            } else if (arr[mid] < search_element) {
                begin = mid + 1;
            }
        }
        
        return -1;
    }
}

#endif
