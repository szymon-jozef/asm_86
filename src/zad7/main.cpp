#include <print>

/// Napisz kod w C oraz w asemblerze określający parzystość
/// liczby jedynek
namespace zad7 {
void b() {
  unsigned char a = 0x3;
  bool y;

  __asm {
    mov al, a; // kopia
    mov ah, 0x1; // maska
    mov cl, 0x0; // suma
    mov dl, 8; // iterator
    
petla:
    mov bl, al;
    and bl, ah;
    xor bl, 1;
    add cl, bl;
    shr al, 1;

    sub dl, 1;
    jnz petla;

    and cl, 0x1;
    jnz parzysta;
    mov y, 0;
    jmp koniec;

parzysta:
    mov y, 1;
koniec:
  }

  std::println("Liczba {} jest {}", (int)a, y ? "parzysta" : "nieparzysta");
}
} // namespace zad7

int main(void) { zad7::b(); }
