#include "garbage_collector.h"

ms_gc::garbage_collector* ms_gc::garbage_collector::instance = nullptr;

void ms_gc::garbage_collector::init() {
    if (ms_gc::garbage_collector::instance == nullptr) {
        ms_gc::garbage_collector::instance = new garbage_collector();
    }
}

ms_gc::garbage_collector* ms_gc::garbage_collector::get_instance() {
    return ms_gc::garbage_collector::instance;
}

void ms_gc::garbage_collector::add_node(ms_gc::collectable* node) {
    this->collectables.push(node);
}

void ms_gc::garbage_collector::notify_delete() {
    this->__mark();
    this->__sweep();
}

void ms_gc::garbage_collector::bind_to_root(ms_gc::collectable* node) {
    ms_gc::linked_list<collectable*>::iterator it = this->collectables.begin();
    ms_gc::collectable* root_node = *it;
    root_node->point_to(node);
}

void ms_gc::garbage_collector::__mark_nodes(ms_gc::collectable* node) {
    if (!(node->me->is_available)) {
        return;
    }
    if (node->points_to_nodes()) {
        for (ms_gc::connection_node* temp : node->pointing_to) {
            this->__mark_nodes(temp->collectable_item);
        }
    }
    node->mark();
}

void ms_gc::garbage_collector::__mark() {
    ms_gc::linked_list<collectable*>::iterator it = this->collectables.begin();
    this->__mark_nodes(*it);
}

void ms_gc::garbage_collector::__sweep() {
    ms_gc::linked_list<collectable*>::iterator it;
    ms_gc::linked_list<collectable*>::iterator last_marked;
    bool do_cutting = false;
    it = this->collectables.begin();

    while (it != this->collectables.end()) {
        if (!(*it)->marked) {
            collectable* p = *it;
            delete p;
            do_cutting = true;
            it++;
            continue;
        } else {
            if (do_cutting) {
                this->collectables.cut(last_marked, it);
                do_cutting = false;
            }
        }
        last_marked = it;
        (*it)->unmark();
        it++;
    }
}
