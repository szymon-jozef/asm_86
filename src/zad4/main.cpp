#include <print>

/// ```cpp
/// for( int i=0; i!=5; i++ ) y += i;
/// ```
namespace zad4 {
void a() {
  int i = 0, y = 0;
  __asm {
        mov eax, y;
        mov ecx, i;

    petla:
        add eax, ecx;
        add ecx, 1;
        cmp ecx, 5;
        jnz petla;

        mov i, ecx;
        mov y, eax;
  }

  std::println("y = {}, i = {}", y, i);
}
} // namespace zad4

int main(void) { zad4::a(); }
