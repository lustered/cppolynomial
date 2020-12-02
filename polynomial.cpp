#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>

class term{
    public:
        int coefficient;
        int exponent;

        term(int coefficient, int exponent)
        {
            this->coefficient = coefficient;
            this->exponent = exponent;
        }

        /* term(term& t1) : coefficient(t1.coefficient), exponent(t1.exponent){} */

        std::string termInfo()
        {
            char buff[50];
            snprintf(buff, sizeof(buff), "%dx^%d",this->coefficient, this->exponent);
            std::string ret = buff;
            return ret;
        }
};

class node{
    public:
        term data;
        node* next;

        node() : data(term(0,0)), next(nullptr){}

        node(term exp) : data(exp), next(nullptr){}

        /* don't work */
        int exp(){ return this->data.exponent;};
        int coeff(){ return this->data.coefficient;};
};

class polynomial{
    public: 
        node* head = nullptr;

        polynomial() : head(nullptr){}

        polynomial(const polynomial& p2)
        {
            this->head = new node(term(p2.head->data));
            node* ptr = p2.head->next;
            node* ptr2 = this->head;
            
            while(ptr != nullptr)
            {
                ptr2->next = new node(term(ptr->data));
                ptr = ptr->next;
                ptr2 = ptr2->next;
            }
        }

        void addTerm(int coeff, int expo)
        {
            node* t = new node(term(coeff,expo));
            /* If empty polynomial, add to head */
            if(this->head == nullptr) 
            {
                this->head = t;
                return;
            }

            /* New polynomial's exponent is smaller than head */
            if(this->head->data.exponent > expo)
            {
                t->next = this->head;
                this->head = t;
                return;
            }

            /* if the next term's exponent is <= than the adding tem */
            node* tmp = this->head;
            while(tmp->next != nullptr)
            {

                if(tmp->next->data.exponent >= expo)
                {
                    t->next = tmp->next;
                    tmp->next = t;
                    return;
                }
                else 
                    tmp = tmp->next; 
            }

            tmp->next = t;
            this->combine();
        }

        polynomial addPol(polynomial p)
        {
            if(this->head == nullptr || p.head == nullptr)
                return polynomial();

            polynomial ret= polynomial(*this);
            polynomial cp = polynomial(p);

            node* t = ret.head;
            while(t->next != nullptr)
                t = t->next;

            node* t2 = cp.head;
            while(t2->next != nullptr )
            {
                ret.addTerm(t2->data.coefficient, t2->data.exponent);
                t2 = t2->next;
            }
            ret.combine();

            return ret;
        }

        std::string print(){

            if(this->head == nullptr)
                return "Empty Polynomial"; 

            node* t = this->head;
            char buff[350];
            std::string ret = "";

            snprintf(buff, sizeof(buff), "%dx^%d", t->coeff(), t->exp());
            ret += buff;
            t = t->next;

            while(t != nullptr)
            {
                snprintf(buff, sizeof(buff), " + %dx^%d", t->coeff(), t->exp());
                ret += buff;
                t = t->next;
            }

            return ret;
        }

    private:
        void combine()
        {
            if(this->head == nullptr)
                return;

            node* t = this->head;
            while(t->next != nullptr)
            {
                if(t->data.exponent == t->next->data.exponent)
                {
                    int nc = t->data.coefficient +
                                   t->next->data.coefficient;

                    term nt = term(nc, t->data.exponent);
                    node* combined = new node(nt);
                    t->data = combined->data; 
                    t->next = (t->next->next != nullptr) ? t->next->next : nullptr;
                }
                else
                    t = t->next;
            }
        }
};

int main()
{
    polynomial p1 = polynomial();
    
    p1.addTerm(1, 3);
    p1.addTerm(3, 5);
    p1.addTerm(1, 3);
    p1.addTerm(5, 1);
    /* p1.addTerm(5, 6); */
    /* p1.addTerm(2, 0); */

    /* std::cout << p1.print() + "\n"; */

    polynomial tmp = polynomial();
    tmp.addTerm(5, 2);

    /* adding polynomials */
    polynomial p2(p1.addPol(tmp));
    std::cout << "p2 = " + p2.print() + "\n";

    /* Copy constructor test */
    /* std::cout << "p1 = " + p1.print() + "\n"; */
    /* std::cout << "p2 = " + p2.print() + "\n"; */
    /* p1.addTerm(10, 10); */
    /* std::cout << "p1 after adding 10x^10 = " + p1.print() + "\n"; */
    /* std::cout << "but p2 = " + p2.print() + "\n"; */

    return 0;
}
