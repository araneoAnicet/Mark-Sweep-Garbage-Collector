#include "Identity.h"

ms_gc::Identity::Identity() {
    this->id = ms_gc::Identity::top_id++;
}

unsigned int ms_gc::Identity::get() {
    return this->id;
}

unsigned int ms_gc::Identity::top_id = 0;
