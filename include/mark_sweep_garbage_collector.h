#pragma once
#include "garbage_collector.h"
#include "collectable_ptr_impl.h"

namespace ms_gc {
    class root : public collectable {};
    void init();
};