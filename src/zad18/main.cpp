// Napisz kod pokazujący wartość struktury bajt po bajcie oraz
// jej rozmiar. Następnie napisz w języku C kod odpowiadający poniższemu
// fragmentowi kodu w C (bez użycia odwołania do pól struktury). Następnie
// napisz kod w asemblerze dla obu fragmentów kodu w C. Porównaj z
// wynikami z zadania 16.
#include <print>
namespace zad18 {

class Base {
public:
  unsigned char a;
  virtual void aaa() {}
};

class MTestStruct : public Base {
public:
  int b;
  long c;
  virtual void aaa() {}
};

void a() {
  MTestStruct x;
  x.a = 1;
  x.b = 2;
  x.c = 3;

  char *ptr = (char *)(&x);
  for (int i = 0; i < sizeof(MTestStruct); ++i) {
    std::print("{:x}", ptr[i]);
  }
}

};  // namespace zad18

int main(void) { zad18::a(); }
