#include <print>

/// ```cpp
/// if( a == 0x32 )
///  y = false;
/// else
///  y = true
/// ```
namespace zad3 {
void a() {
  char a = 0x32;
  bool y;

  __asm {
    mov al, a;

    sub a, 0x32;

    jz jest_zero;
    mov y, 1;
    jmp koniec;

jest_zero:
    mov y, 0;

koniec:

  }

  std::println("y = {}", y);
}
} // namespace zad3

int main(void) { zad3::a(); }
