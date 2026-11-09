#include <print>

/// Napisz kod w C oraz asemblerze odpowiadający poniższemu 
/// fragmentowi kodu w C (BEZ UŻYCIA MNOŻENIA).
/// ```cpp
/// y = a * 1.125;
/// ```
namespace zad10 {
void a() {
  unsigned short int a = 1000, y;

  // a * 1.125 = (a * 1) + (a * 0.125) = a + a >> 3

  __asm {
    mov ax, a;
    mov bx, ax;
    shr ax, 3;
    add ax, bx;
    
    mov y, ax;
  }

  std::println("{} = {} * 1.125", y, a);
} // namespace zad10
} // namespace zad10

int main(void) { zad10::a(); }
