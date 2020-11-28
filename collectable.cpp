#include "collectable.h"

void ms_gc::collectable::init() {
    this->me = new ms_gc::connection_node();
    this->me->collectable_item = this;
    this->me->is_available = true;
}

ms_gc::collectable::collectable() {
    this->init();
    this->init_collectable();
}

void ms_gc::collectable::mark() {
    this->marked = true;
}

void ms_gc::collectable::unmark() {
    this->marked = false;
}

void ms_gc::collectable::init_collectable() {
    ms_gc::garbage_collector::get_instance()->add_node(this);
}

void ms_gc::collectable::remove() {
    this->me->is_available = false;
    ms_gc::garbage_collector::get_instance()->notify_delete();
}

void ms_gc::collectable::point_to(ms_gc::collectable* other) {
    this->pointing_to.push(other->me);
}

bool ms_gc::collectable::points_to_nodes() {
    return this->pointing_to.has_elements();
}
