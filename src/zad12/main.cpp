/// ```cpp
/// for (int i = 0; i < 5; i++) {
/// y += i;
/// }
/// ```
#include <print>
namespace zad12 {
void a() {
  int i, y;

  __asm {
    // inicjalizacja
    mov eax, 0; // y
    mov ecx, 0; // i
    
petla:
    add eax, 1;
    add ecx, 1;

    mov ebx, ecx;
    sub ebx, 5;
    jc petla;

    mov y, eax;
    mov i, ecx;
  }

  std::println("i = {:d}, y = {:d}", i, y);
  // TODO! fix
}
} // namespace zad12

int main(void) { zad12::a(); }
