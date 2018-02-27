#include "utils/utils.hpp"

namespace utils{

    uint64_t factorial( uint64_t n ){
        if (n == 1 || n == 0){
            return 1;
        } else {
            return factorial( n -1 ) * n;
        }
    }

} // namespace utils