#pragma once
#include "collectable_ptr.h"
#include <iostream>

/*
    Collectalbe container

*/

template<typename T>
ms_gc::collectable_container<T>::collectable_container(T p) {
    this->p = p;
}

template<typename T>
ms_gc::collectable_container<T>::~collectable_container() {
    delete this->p;
}

template<typename T>
T ms_gc::collectable_container<T>::operator*() {
    return this->p;
}

/*
    Collectalbe container

*/


template<typename T>
ms_gc::collectable_ptr<T>::collectable_ptr(T p) {
    this->container = new ms_gc::collectable_container<T>(p);
}

template<typename T>
T ms_gc::collectable_ptr<T>::operator*() {
    return **(this->container);
}

template<typename T>
T ms_gc::collectable_ptr<T>::operator->() {
    return **(this->container);
}

template<typename T>
void ms_gc::collectable_ptr<T>::point_to(ms_gc::collectable* other) {
    this->container->point_to(other);
}

template<typename T>
void ms_gc::collectable_ptr<T>::remove() {
    this->container->remove();
}

template<typename T>
ms_gc::collectable_container<T>* ms_gc::collectable_ptr<T>::to_collectable() {
    return this->container;
}

template<typename T>
ms_gc::collectable_ptr<T> ms_gc::make_collectable(T p) {
    ms_gc::collectable_ptr<T> temp(p);
    return temp;
}

