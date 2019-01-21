/*****************************************************
 *                   LINEAR SEARCH                   *
 *                                                   *
 * Implementation of a simplest searching algorithm. *
 * Its time complexity is O(n). If the item is found,* 
 * the function returns the index of this item.      *
 * Otherwise, the function will return -1.           *
 *****************************************************/

#ifndef ALG_SEARCH_LINEAR_SEARCH_H_
#define ALG_SEARCH_LINEAR_SEARCH_H_

namespace alg_search {
    template<typename T>
    int LinearSearch(T A[], T search_element, int size) {
        for (int i = 0; i < size; i++) {
            if (A[i] == search_element) {
                return i;
            }
        }
        return -1;
    } 
}

#endif
