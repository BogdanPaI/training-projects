/******************************************************
 *              RECURSIVE BINARY SEARCH               *
 *                                                    *
 * Implementation of a recursive binary search.       *
 * The algorithm uses divide and conquer paradigm and *
 * its time complexity is O(log(n)), but its also     *
 * requires a sorted array. If the item is found,     *
 * the function returns the index of this item.       *
 * Otherwise, the function will return -1.            *
 ******************************************************/

#ifndef ALG_SEARCH_RECURSIVE_BINARY_SEARCH_H_
#define ALG_SEARCH_RECURSIVE_BINARY_SEARCH_H_

namespace alg_search {
    template<typename T>
    int RecursiveBinarySearch(T *arr, T search_element, int begin, int end) {
        if (begin >= end) {
            return -1;
        } else {
            while (begin < end) {
                int mid = (begin + end) / 2;
                if (arr[mid] == search_element) {
                    return mid;
                } else if (arr[mid] > search_element) {
                    return RecursiveBinarySearch(arr, search_element, begin, mid - 1);
                } else if (arr[mid] < search_element) {
                    return RecursiveBinarySearch(arr, search_element, mid + 1, end);
                }
            }
        } 
    }
}

#endif