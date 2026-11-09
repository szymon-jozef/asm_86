/// ```cpp
/// for (int i = 0; i < 5; i++) {
/// y += i;
/// }
/// ```
#include <print>
namespace zad12 {
void a() {
  int i = 0, y = 0;

  __asm {
        mov eax, y;
        mov ecx, i;

    petla:
        mov ecx, edx;
        add eax, ecx;

        add ecx, 1;
        sub edx, 5;
        jc petla;
  }

  std::println("i = {:d}, y = {:d}", i, y);
  // TODO! fix
}
} // namespace zad12

int main(void) { zad12::a(); }
