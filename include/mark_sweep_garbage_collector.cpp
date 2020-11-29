#include "mark_sweep_garbage_collector.h"


void ms_gc::init() { 
    ms_gc::garbage_collector::init();
    new ms_gc::root();
}