namespace replicate_ns {

enum replicate_enum {
  replicate_enum_first,
  replicate_enum_second
};

class replicate {
public:
  replicate(bool first_param = true, replicate_enum second_param = replicate_enum_first)
    : _private_bool(first_param),
      _private_replicate_enum(second_param)
  {}
private:
  bool _private_bool;
  replicate_enum _private_replicate_enum;
};

int use_replicate(bool should_do_something);

}
