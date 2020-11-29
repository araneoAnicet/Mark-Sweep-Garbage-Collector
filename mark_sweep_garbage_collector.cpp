#include "mark_sweep_garbage_collector.h"

ms_gc::root::root() {
    std::cout << "Allocated root collectable" << std::endl;
}

void ms_gc::init() { 
    ms_gc::garbage_collector::init();
    new ms_gc::root();
}