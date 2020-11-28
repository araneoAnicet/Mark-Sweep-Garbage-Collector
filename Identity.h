#pragma once

namespace ms_gc {
    class Identity {
        private:
            unsigned int id;
            static unsigned int top_id;
        public:
            Identity();
            unsigned int get();
    };
}