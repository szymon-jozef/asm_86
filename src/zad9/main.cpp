#include <print>

/// Napisz kod w C oraz asemblerze odpowiadający poniższemu 
/// fragmentowi kodu w C (BEZ UŻYCIA MNOŻENIA)
/// ```cpp
/// y = a * b;
/// ```
namespace zad9 {
void a() {
  char a = 2, b = 4;
  short int y;

  // a * b

  __asm {
        mov al, a;
        mov ah, 0;

        mov bx, 0; // suma
        mov cx, b; // maska
    petla:
        mov dl, cl; // kopia
                   
        and dl, 0x01; // najmłodszy bit
        jz pomin_dodawanie;
        add bx, ax;

    pomin_dodawanie:

        shl ax, 1;
        shr cl, 1;
        jnz petla;

        mov y, bx;
  }

  std::println("{:d} * {:d} = {:d}", a, b, y);
}
} // namespace zad9

int main(void) { zad9::a(); }
