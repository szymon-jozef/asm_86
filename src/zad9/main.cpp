/// Napisz kod w C oraz asemblerze odpowiadający poniższemu 
/// fragmentowi kodu w C (BEZ UŻYCIA MNOŻENIA)
/// ```cpp
/// y = a * b;
/// ```
namespace zad9 {
void a() {
  char a;
  short int b;

  // a * b

  __asm {
        mov al, a;

  }
}
} // namespace zad9

int main(void) {}
