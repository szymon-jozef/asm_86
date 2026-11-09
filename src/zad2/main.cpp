#include <print>

/// ```cpp
/// if( a == 0x32 )
///     y = 0;
/// else
///     y = 1;
/// ```
///
namespace zad2 {
void a() {
  char a = 0x32, y;

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

  std::println("y = {}", (int)y);
}
} // namespace zad2

int main(void) { zad2::a(); }
