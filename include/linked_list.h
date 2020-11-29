#pragma once
#include <stdexcept>


namespace ms_gc {
    template<class T>
    struct linked_list_node {
        T value;
        linked_list_node<T>* next;
        linked_list_node<T>* prev;
    };

    template<class T>
    class linked_list;

    template<typename T>
    class linked_list_iterator {
        friend linked_list<T>;
        private:
            linked_list_node<T>* p;
            linked_list<T>* list_instance;
        public:
            linked_list_iterator(linked_list_node<T>* node, linked_list<T>* list_instance);
            linked_list_iterator(linked_list<T>* list_instance);
            linked_list_iterator();

            bool operator!=(linked_list_iterator const& other);
            bool operator==(linked_list_iterator const& other);
            T operator*();
            linked_list_iterator<T>* operator++(int n);
            linked_list_iterator<T>* operator++();
    };


    template<class T>
    class linked_list {
        private:
            linked_list_node<T>* root_node;
            linked_list_node<T>* top_node;
        public:
            typedef linked_list_iterator<T> iterator;
            typedef linked_list<const T> const_iterator;
            iterator begin();
            iterator end();
            linked_list();
            linked_list(T initial_value);
            void push(T new_value);
            void cut(iterator first, iterator last);
            bool has_elements();
    };
};
