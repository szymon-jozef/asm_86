#include <cstdio>

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

  printf("y = %d", y);
}

} // namespace zad1

int main(void) { zad1::a(); }
