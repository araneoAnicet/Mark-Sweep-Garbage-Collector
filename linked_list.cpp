#include "linked_list.h"

template<typename T>
ms_gc::linked_list_iterator<T>::linked_list_iterator(const ms_gc::linked_list_iterator<T>& it) {
    p(it.p);
}

template<typename T>
ms_gc::linked_list_iterator<T>::linked_list_iterator(T* p) {
    p(p);
}

template<typename T>
bool ms_gc::linked_list_iterator<T>::operator!=(ms_gc::linked_list_iterator<T> const& other) const {
    return p != other.p;
}

template<typename T>
bool ms_gc::linked_list_iterator<T>::operator==(ms_gc::linked_list_iterator<T> const& other) const {
    return p == other.p;
}

template<typename T>
typename ms_gc::linked_list_iterator<T>::reference ms_gc::linked_list_iterator<T>::operator*() const {
    return *p;
}

template<typename T>
ms_gc::linked_list_iterator<T> &ms_gc::linked_list_iterator<T>::operator++() {
    ++p;
    return *this;
}
