enum setting {
  some_way,
  some_other_way
};

class class_with_default_argument_constructor {
public:
  class_with_default_argument_constructor(bool = true, setting = some_way);
};

void do_the_thing(void);
