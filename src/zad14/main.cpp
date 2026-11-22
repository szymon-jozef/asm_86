/// ```c
/// x.bits.c = x.bits.a * x.bits.b;
/// ```

#include <print>
namespace zad14 {
void a() {
  // [0] -a [000] -b [0000] -c
  typedef union {
    unsigned char BYTE;
    struct {
      unsigned char a : 1;
      unsigned char b : 3;
      unsigned char c : 4;
    } bits;
  } un_X;

  un_X x;
  x.BYTE = 0b10001101;
  x.bits.a = 0b1;
  x.bits.b = 0b101;
  x.bits.c = 0b0;

  std::println("Before:\nBYTE = {:b}\na = {:b}\nb = {:b}\nc = {:b}", x.BYTE,
               (int)x.bits.a, (int)x.bits.b, (int)x.bits.c);

  // clang-format off
  __asm {
    mov al, x.BYTE; // a
    mov bl, al;     // b
    mov cl, al;     // c

    and al, 0x1;    // get a from BYTE
    
    shr bl, 1;
    and bl, 0x7;    // get b from BYTE

    cmp al, 1;
    jz warunek;

    mov cl, 0;
    jmp koniec;

warunek:
    mov cl, bl;

koniec:
    shl cl, 4;
    or x.BYTE, cl;

  }
  // clang-format on

  std::println("After:\nBYTE = {:b}\na = {:b}\nb = {:b}\nc = {:b}", x.BYTE,
               (int)x.bits.a, (int)x.bits.b, (int)x.bits.c);
}
}  // namespace zad14

int main(void) { zad14::a(); }
