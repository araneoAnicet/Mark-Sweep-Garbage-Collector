#pragma once
#include "collectable.h"

namespace ms_gc {

    template<class T>
    class collectable_container : public collectable {
        private:
            T p;
        public:
            collectable_container(T p);
            ~collectable_container();
            T operator*();
    };

    template<class T>
    class collectable_ptr {
        private:
            collectable_container<T>* container;
        public:
            collectable_ptr(T p);
            T operator*();
            T operator->();
            void point_to(collectable* other);
            void remove();
            collectable_container<T>* to_collectable();
    };

    template<typename T>
    collectable_ptr<T> make_collectable(T p);
}
