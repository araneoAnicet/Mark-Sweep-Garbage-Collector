#pragma once
#include "linked_list_impl.h"
#include "garbage_collector.h"
#include "Identity.h"

namespace ms_gc {

    class collectable;

    struct connection_node {
        collectable* collectable_item;
        bool is_available = false;
    };

    //class collectable;
    class garbage_collector;
    class collectable {
        friend garbage_collector;
        protected:
            void init();
            connection_node* me;
            bool marked = false;
            linked_list<connection_node*> pointing_to;
            void mark();
            void unmark();
            void init_collectable();
        public:
            collectable();
            void remove();
            void point_to(collectable* other);
            bool points_to_nodes();
            Identity id;
    };
}
