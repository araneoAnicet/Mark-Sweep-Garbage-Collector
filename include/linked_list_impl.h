#pragma once
#include "linked_list.h"
#include <iostream>
/*
    Linked list node iterator
*/

template<typename T>
ms_gc::linked_list_iterator<T>::linked_list_iterator(ms_gc::linked_list<T>* list_instance) {
    this->p = nullptr;
    this->list_instance = list_instance;
}

template<typename T>
ms_gc::linked_list_iterator<T>::linked_list_iterator(ms_gc::linked_list_node<T>* node, ms_gc::linked_list<T>* list_instance) {
    this->p = node;
    this->list_instance = list_instance;
}

template<typename T>
ms_gc::linked_list_iterator<T>::linked_list_iterator() {
    this->p = nullptr;
}


template<typename T>
bool ms_gc::linked_list_iterator<T>::operator!=(linked_list_iterator const& other) {
    return other.p != this->p;
}

template<typename T>
bool ms_gc::linked_list_iterator<T>::operator==(linked_list_iterator const& other) {
    return other.p == this->p;
}


template<typename T>
T ms_gc::linked_list_iterator<T>::operator*() {
    return this->p->value;
}

template<typename T>
ms_gc::linked_list_iterator<T>* ms_gc::linked_list_iterator<T>::operator++(int n) {
    if (n == 0) {
        this->p = this->p->next;
    }
    return this;
}

template<typename T>
ms_gc::linked_list_iterator<T>* ms_gc::linked_list_iterator<T>::operator++() {
    this->p = this->p->next;
    return this;
}
/*
    Linked list itself
*/
template<typename T>
ms_gc::linked_list<T>::linked_list() {
    this->root_node = new linked_list_node<T>();
    this->top_node = this->root_node;
}

template<typename T>
ms_gc::linked_list<T>::linked_list(T initial_value) {
    this->root_node = new linked_list_node<T>();
    this->root_node->value = initial_value;
    this->top_node = new linked_list_node<T>();
    this->root_node->next = this->top_node;
}

template<typename T>
typename ms_gc::linked_list<T>::iterator ms_gc::linked_list<T>::begin() {
    return iterator(this->root_node, this);
}

template<typename T>
typename ms_gc::linked_list<T>::iterator ms_gc::linked_list<T>::end() {
    return iterator(this->top_node, this);
}

template<typename T>
void ms_gc::linked_list<T>::push(T new_value) {
    this->top_node->value = new_value;
    this->top_node->next = new linked_list_node<T>();
    this->top_node = this->top_node->next;
}

template<typename T>
void ms_gc::linked_list<T>::cut(typename ms_gc::linked_list<T>::iterator first, typename ms_gc::linked_list<T>::iterator last) {
    if (first.list_instance != last.list_instance) {
        throw std::invalid_argument("Cutting elements of different lists");
    }
    first.p->next = last.p;
}

template<typename T>
bool ms_gc::linked_list<T>::has_elements() {
    return !(this->root_node == this->top_node);
}
