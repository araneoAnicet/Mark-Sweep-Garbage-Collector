#pragma once
#include "linked_list_impl.h"
#include "collectable.h"


namespace ms_gc {
    class collectable;
    class garbage_collector {
        friend collectable;
    private:
        static garbage_collector* instance;
        linked_list<collectable*> collectables;
        void __mark();
        void __sweep();
        void __mark_nodes(collectable* node);
        void bind_to_root(collectable* node);
    public:
        static void init();
        void notify_delete();
        void add_node(collectable* node);
        static garbage_collector* get_instance();
    };
};
