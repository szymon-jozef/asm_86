#include <print>

/// Napisz kod w asemblerze odpowiadający poniższemu
/// fragmentowi kodu w C z wykorzystaniem FLAGI C
namespace zad11 {
void a() {
  char a = 10, y;

  __asm {
        mov al, a;

        sub al, 0x05;
        jc mniejsze;
        mov y, 1;
        jmp koniec;
    mniejsze:
        mov y, 0;
    koniec:
  }

  std::println("Y = {:d}", y);
}

/// ```cpp
/// if (a > 0x05) {
///     y = 0;
/// } else {
///     y = 1;
/// }
/// ```
///
void d() {
  char a = 10, y;

  __asm {
    // TODO!
  }
}
} // namespace zad11

int main() { zad11::a(); }
