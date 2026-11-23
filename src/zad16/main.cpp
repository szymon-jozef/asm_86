// Napisz kod pokazujący wartość struktury bajt po bajcie oraz
// jej rozmiar. Następnie napisz w języku C kod odpowiadający poniższemu
// fragmentowi kodu w C (bez użycia odwołania do pól struktury). Następnie
// napisz kod w asemblerze dla obu fragmentów kodu w C.
#include <print>
namespace zad16 {
// #pragma pack(1)
typedef struct {
  unsigned char a;  // 1 bajt
  int b;            // 4 bajty
  long c;           // 4 bajty
} MTestStruct;

void kod_w_c() {
  MTestStruct x;
  char *adr = (char *)&x;
  *adr = 1;             // x.a = 1;
  *(int *)&adr[4] = 2;  // x.b = 2;
  *(int *)&adr[8] = 3;  // x.c = 3;
  int size = sizeof(MTestStruct);

  for (int i = 0; i < size; i++) {
    std::print("{:x}", adr[i]);
  }
}

void a() {
  MTestStruct x;
  char *adr = (char *)&x;

  // clang-format off
  __asm {
    lea eax, adr;
    mov byte ptr[eax], 1;
    add eax, 4;
    mov dword ptr[eax], 2;
    add eax, 4;
    mov dword ptr[eax], 3;
  }
  // clang-format on

  for (int i = 0; i < sizeof(MTestStruct); i++) {
    std::print("{:x}", adr[i]);
  }
}
}  // namespace zad16

int main(void) {
  // zad16::kod_w_c();
  zad16::a();
}
