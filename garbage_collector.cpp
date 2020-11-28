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
    std::cout << "Entered sweep" << std::endl;
    ms_gc::linked_list<collectable*>::iterator it;
    ms_gc::linked_list<collectable*>::iterator from;
    it = this->collectables.begin();
    while (it != this->collectables.end()) {
        std::cout << "Iterating over: " << (*it)->id.get() << std::endl;
        if (!(*it)->marked) {
            std::cout << "Deleting object " << (*it)->id.get() << std::endl;
            collectable* p = *it;
            delete p;
        }
        it++;
    }
}
