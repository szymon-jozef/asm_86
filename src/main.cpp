#include <print>

/// Napisz kod w asm, który odpowiada poniższemu fragmentowi kodu w c:
/// ```cpp
/// y = a * 20;
/// ```
///
/// a * 20 = a * (2^4 + 2^2) = a * 2^4 + a * 2^2
namespace zad1 {

void a() {
  char a = 2;
  short int y;

  __asm {
    // Copy data to fast cpu
        mov bh, 0;
        mov bl, a;
        mov ax, bx;

        shl ax, 4;
        shl bx, 2;
        add ax, bx;

        mov y, ax;
  }

  std::println("y = {}", y);
}
} // namespace zad1

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
