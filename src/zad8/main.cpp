#import <print>

/// Napisz kod w C oraz w asemblerze zamieniający kolejność 
// bitów w bajcie.
// Najmłodszy bit zmiennej a ma być najstarszym zmiennej r, itp., zgodnie z
// rysunkiem poniżej
namespace zad8 {
void c() {
  unsigned char a = 0b0011, r;

  __asm {
        mov al, a; // kopia
        mov ah, 0x1; // maska
        mov cl, 0; // iterator
        mov dl, 0; // output
    petla:
        mov bl, al; // kopia kopii
        and bl, ah; // bl ma najmłodszy bit

        shl dl, 1;
        add dl, bl;
        shr al, 1;

        add cl, 1;
        cmp cl, 8;
        jnz petla;

        mov r, dl;
  }

  std::println("Liczba {:08b} z odwróconymi bitami: {:08b}", a, r);
}
} // namespace zad8

int main(void) { zad8::c(); }
