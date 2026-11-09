#include <print>

/// ```cpp
/// while( y!=5 ) y += 1;
/// ```
namespace zad5 {
void b() {
  int y = 0;

  __asm {
        mov eax, y;
petla:
        add eax, 1;
        mov ebx, eax;
        sub ebx, 5;
        jnz petla;

        mov y, eax;
  }

  std::println("y = {}", y);
}

void c() {
  int y = 0;

  __asm {
        mov eax, y;
    petla:
        add eax, 1;
        cmp eax, 5;
        jnz petla;

        mov y, eax;
  }

  std::println("y = {}", y);
}
} // namespace zad5

int main(void) {
  zad5::b();
  zad5::c();
}
