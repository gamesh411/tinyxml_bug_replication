#include "replicate.h"
#include <cstdio>

namespace replicate_ns {

int use_replicate(bool should_do_something) {
  replicate replicate(should_do_something);
  return 42;
}

}

