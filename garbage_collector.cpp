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

void ms_gc::garbage_collector::notify_delete(ms_gc::collectable* notifier) {
    notifier->mark();
    this->__mark();
    this->__sweep();
}

void ms_gc::garbage_collector::__mark_nodes(ms_gc::collectable* node) {
    if (node->points_to_nodes()) {
        for (ms_gc::collectable* temp : node->pointing_to) {
            this->__mark_nodes(temp);
        }
    } else {
        node->mark();
    }
}

void ms_gc::garbage_collector::__mark() {
    ms_gc::linked_list<collectable*>::iterator it = this->collectables.begin();
    this->__mark_nodes(*it);
}

void ms_gc::garbage_collector::__sweep() {
    std::cout << "Entered sweep" << std::endl;
    ms_gc::linked_list<collectable*>::iterator it;
    ms_gc::linked_list<collectable*>::iterator from;
    bool do_cutting = false;
    it = this->collectables.begin();
    while (it != this->collectables.end()) {
        std::cout << "iteration" << std::endl;
        if (!(*it)->marked) {
            std::cout << "Unmarked is being deleted..." << std::endl;
            delete *it;
        }
        it++;
    }
}
