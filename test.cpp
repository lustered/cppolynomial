#include "lib/polynomial.h"

int main()
{
    polynomial p1 = polynomial();
    
    p1.addTerm(5, 2);
    p1.addTerm(4, 5);
    p1.addTerm(3, 3);
    p1.addTerm(1, 2);
    p1.addTerm(5, 6);

    polynomial tmp = polynomial();
    tmp.addTerm(5, 2);

    /* adding polynomials */
    polynomial p2(p1.addPol(tmp));

    /* multiplying polynomials */
    polynomial p3(p1.multPol(p2));

    std::cout << "p1 = " + p1.print() << std::endl;
    std::cout << "p2 = " + p2.print() << std::endl;
    std::cout << "p3 = " + p3.print() << std::endl;

    /* Copy constructor test */
    /* std::cout << "p1 = " + p1.print() + "\n"; */
    /* std::cout << "p2 = " + p2.print() + "\n"; */
    /* p1.addTerm(10, 10); */
    /* std::cout << "p1 after adding 10x^10 = " + p1.print() + "\n"; */
    /* std::cout << "but p2 = " + p2.print() + "\n"; */

    return 0;
}

