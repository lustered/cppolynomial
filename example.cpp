#include "lib/polynomial.h"

int main() {
  polynomial p1;
  p1.addTerm(5, 6);
  p1.addTerm(2, 3);
  p1.addTerm(1, 1);
  p1.addTerm(3, 4);

  polynomial p2;
  p2.addTerm(10, 4);
  p2.addTerm(3, 2);
  p2.addTerm(3, 0);

  polynomial p3(p1.addPol(p2));
  polynomial p4(p1.multPol(p3));

  std::cout << "polynomial 1: " << p1 << "polynomial 2: " << p2;
  std::cout << "p1 + p2: " << p3 << "p1 * p3 " << p4;

  return 0;
}
