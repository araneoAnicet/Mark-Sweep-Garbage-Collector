#pragma once

namespace ms_gc {
    template<class T>
    class linked_list {
        public:
            struct node {
                T* value;
                T* next;
            };
            linked_list();
    };
};