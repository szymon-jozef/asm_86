/// Napisz kod w C (bez użycia pól bitowych) oraz w
/// asemblerze odpowiadający poniższemu fragmentowi kodu w C.
/// ```c
/// typedef union {
///     unsigned char BYTE;
///     struct{
///         unsigned char a:2;
///         unsigned char b:3;
///         unsigned char c:3;
///     }bits;
/// }un_X;
///
/// un_X x;
/// if( x.bits.c == 1 ) x.bits.a = x.bits.b;
/// ```
///
///
#include <print>
namespace zad13 {
void a() {
  // [000] - c [000] -b [00] -a
  //
  // [000] - c [000] -b [00] -a
  //    | --------------->| (shr 5)
  typedef union {
    unsigned char BYTE;
    struct {
      unsigned char a : 2;
      unsigned char b : 3;
      unsigned char c : 3;
    } bits;
  } un_X;

  un_X x;
  x.BYTE = 0b00110110;
  //      [001][101][10]

  std::println("Before:\nX.BYTE = {:b}", x.BYTE);

  // clang-format off
  __asm {
    mov al, x.BYTE;  // al = x.BYTE
    mov ah, al;      // ah = al
    mov bl, al;      // bl = al
    shr al, 5;       // al >> 5

    // if (x.BYTE != 1) GOTO koniec;
    sub al, 1;
    jnz koniec;

    // get 3 youngest bit from b
    shr ah, 2;       // ah >> 2
    and ah, 0x7;     // ah = x.bits.b

    and bl, 0xFC;    // zero 2 youngest bits (leave cb00)
    and ah, 0x3;     // get 2 youngest bits (leave 000000a)
    or bl, ah;       // save a to bl
    mov x.BYTE, bl;  // x.BYTE = bl
koniec:
  }

  // clang-format on

  std::println("After:\nX.a = {:b}\nX.b = {:b}\nX.c = {:b}\nX.BYTE = {:b}",
               (int)x.bits.a, (int)x.bits.b, (int)x.bits.c, (int)x.BYTE);
}
}  // namespace zad13

int main(void) { zad13::a(); }
