#pragma once
#include <iterator>


namespace ms_gc {
    template<class T>
    struct linked_list_node {
        T* value;
        T* next;
    };

    template<typename T>
    class linked_list_iterator: public std::iterator<std::input_iterator_tag, T> {
        public:
            linked_list_iterator(const linked_list_iterator& it);
            linked_list_iterator(T* p);

            bool operator!=(linked_list_iterator const& other) const;
            bool operator==(linked_list_iterator const& other) const;
            typename linked_list_iterator::reference operator*() const;
            linked_list_iterator& operator++();
    };


    template<class T>
    class linked_list {
        private:
            linked_list_node<T>* root_node;
            linked_list_node<T>* top;
        public:

            linked_list();
            linked_list(T* initial_value);
    };
};