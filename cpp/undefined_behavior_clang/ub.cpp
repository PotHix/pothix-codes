#include <iostream>

int main() {
  while (1)
    ;
}

void unreachable() {
  // this is going to be printed and the rest is optimized away
  // via clang, as it's undefined behavior
  std::cout << "Hello world!" << std::endl;
}
