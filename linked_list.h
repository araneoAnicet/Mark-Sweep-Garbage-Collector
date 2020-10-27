#pragma once

namespace ms_gc {
    template<class T>
    struct linked_list_node {
        T* value;
        T* next;
    };


    template<class T>
    class linked_list {
        private:
            linked_list_node<T>* root_node;

        public:
            
            linked_list();
    };
};