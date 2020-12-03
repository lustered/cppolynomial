#include "lib/polynomial.h"

int main()
{
    polynomial p1 = polynomial();
    p1.addTerm(5, 6);
    p1.addTerm(2, 3);
    p1.addTerm(1, 1);
    p1.addTerm(3, 4);

    polynomial p2 = polynomial();
    p2.addTerm(10, 4);
    p2.addTerm(3, 2);
    p2.addTerm(3, 0);

    polynomial p3(p1.addPol(p2));

    printf("\np1 = %s\np2 = %s\np1+p2 = %s\n",
            p1.print().c_str(),p2.print().c_str(),p3.print().c_str());

    polynomial p4(p1.multPol(p3));

    printf("\np1 = %s\np3 = %s\np1+p3 = %s\n",
            p1.print().c_str(),p3.print().c_str(),p4.print().c_str());

    return 0;
}
