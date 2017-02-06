#include "replicate.h"
#include <cstdio>

void function_with_default_arg(bool arg) {
  if (arg) {}
}


void do_the_thing() {
  function_with_default_arg(true);
}

