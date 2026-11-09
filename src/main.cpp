#include <print>

/// Napisz kod w asm, który odpowiada poniższemu fragmentowi kodu w c:
/// ```cpp
/// y = a * 20;
/// ```
///
/// a * 20 = a * (2^4 + 2^2) = a * 2^4 + a * 2^2
namespace zad1 {

void a() {
  char a = 2;
  short int y;

  __asm {
    // Copy data to fast cpu
        mov bh, 0;
        mov bl, a;
        mov ax, bx;

        shl ax, 4;
        shl bx, 2;
        add ax, bx;

        mov y, ax;
  }

  std::println("y = {}", y);
}
} // namespace zad1

/// ```cpp
/// if( a == 0x32 )
///     y = 0;
/// else
///     y = 1;
/// ```
///
namespace zad2 {
void a() {
  char a = 0x32, y;

  __asm {
    mov al, a;

    sub a, 0x32;

    jz jest_zero;
    mov y, 1;
    jmp koniec;

jest_zero:
    mov y, 0;

koniec:

  }

  std::println("y = {}", (int)y);
}
} // namespace zad2

/// ```cpp
/// if( a == 0x32 )
///  y = false;
/// else
///  y = true
/// ```
namespace zad3 {
void a() {
  char a = 0x32;
  bool y;

  __asm {
    mov al, a;

    sub a, 0x32;

    jz jest_zero;
    mov y, 1;
    jmp koniec;

jest_zero:
    mov y, 0;

koniec:

  }

  std::println("y = {}", y);
}
} // namespace zad3

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

/// ```cpp
/// while( y!=5 ) y += 1;
/// ```
namespace zad5 {
void b() {
  int y = 0;

  __asm {
            mov eax, y;

petla:
            add eax, 1;
            mov ebx, eax;
            sub ebx, 5;
            jnz petla;

            mov y, eax;
  }

  std::println("y = {}", y);
}

void c() {
  int y = 0;

  __asm {
            mov eax, y;

petla:
            add eax, 1;
            cmp eax, 5;
            jnz petla;

            mov y, eax;
  }

  std::println("y = {}", y);
}
} // namespace zad5
  //

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
