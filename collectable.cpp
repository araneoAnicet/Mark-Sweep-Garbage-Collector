#include "collectable.h"

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
    ms_gc::garbage_collector::get_instance()->notify_delete(this);
}

void ms_gc::collectable::point_to(ms_gc::collectable* other) {
    this->pointing_to.push(other);
}

bool ms_gc::collectable::points_to_nodes() {
    return this->pointing_to.has_elements();
}
