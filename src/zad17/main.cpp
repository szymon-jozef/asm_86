// Napisz kod pokazujący wartość struktury bajt po bajcie oraz
// jej rozmiar. Następnie napisz w języku C kod odpowiadający poniższemu
// fragmentowi kodu w C (bez użycia odwołania do pól struktury). Następnie
// napisz kod w asemblerze dla obu fragmentów kodu w C.
#include <print>
namespace zad17 {
class Base {
  unsigned char a;
};
class MTestStruct : public Base {
public:
  int b;
  long c;
};

void a() {
  MTestStruct x;
  char *adr = (char *)&x;

  *adr = 1;             // x.a = 1;
  *(int *)&adr[4] = 2;  // x.b = 2;
  *(int *)&adr[8] = 3;  // x.c = 3;

  for (int i = 0; i < sizeof(MTestStruct); i++) {
    std::print("{:x}", adr[i]);
  }
}

};  // namespace zad17

int main(void) { zad17::a(); }
