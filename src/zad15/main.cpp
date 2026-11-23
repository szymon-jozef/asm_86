// Napisz w języku C kod odpowiadający poniższemu
// fragmentowi kodu w C (bez użycia adresowania indeksowego, tylko na
// bazie wskaźników). Następnie napisz kod w asemblerze dla obu
// fragmentów kodu w C.
// ```c
// unsigned char tab[5];
// for( int i=0; i!=5; i++ ) tab[i] = i;
// ```
#include <print>
namespace zad15 {
void kod_w_c() {
  std::println("===Kod w c===");
  int *tab = new int[5];
  for (int i = 0; i != 5; i++) {
    *(tab + i) = i;
  }
  for (int i = 0; i != 5; i++) {
    std::println("tab[{}] = {}", i, tab[i]);
  }

  delete[] tab;
}

void a() { int *tab = new int[5]; }
}  // namespace zad15

int main(void) {
  zad15::kod_w_c();
  zad15::a();
}
