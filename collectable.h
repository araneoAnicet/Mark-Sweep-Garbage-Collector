#pragma once
#include "linked_list_impl.h"
#include "garbage_collector.h"


namespace ms_gc {
    class garbage_collector;
    class collectable {
        friend garbage_collector;
        protected:
            bool marked = false;
            linked_list<collectable*> pointing_to;
            void mark();
            void unmark();
            void init_collectable();
        public:
            void remove();
            void point_to(collectable* other);
            bool points_to_nodes();
    };
}
