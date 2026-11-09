#include <print>

/// Napisz kod w C oraz w asemblerze zliczający liczbę zer w bajcie a.
namespace zad6 {
void b() {
  char a = 0x80, y;

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

    mov y, cl;
  }

  std::println("y = {}", (int)y);
}
} // namespace zad6

int main(void) { zad6::b(); }
