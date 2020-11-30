#include <bits/stdc++.h>

class term{
    public:
        int coefficient;
        int exponent;

        term(int coefficient, int exponent)
        {
            this->coefficient = coefficient;
            this->exponent = exponent;
        }

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

        node() : data(term(1,1)), next(nullptr){}

        node(term exp) : data(exp), next(nullptr){}

        /* don't work */
        int exp(){ return this->data.exponent;};
        int coeff(){ return this->data.coefficient;};
};

class polynomial{
    public: 
        node* head = nullptr;

        void addTerm(node exp)
        {
            node* t = new node(exp);
            /* If empty polynomial, add to head */
            if(this->head == nullptr) 
            {
                /* std::cout << "the head is " + exp.data.termInfo() << std::endl; */
                this->head = t;
                return;
            }

            /* New polynomial's exponent is smaller than head */
            if(this->head->data.exponent > exp.data.exponent)
            {
                /* std::cout << "new head" << std::endl; */
                t->next = this->head;
                this->head = t;
                return;
            }

            /* if the next term's exponent is <= than the adding tem */
            node* tmp = this->head;
            while(tmp->next != nullptr)
            {
                /* std::cout << tmp->data.coefficient << std::endl; */

                if(tmp->next->data.exponent >= exp.data.exponent)
                {
                    /* std::cout << "between" << std::endl; */
                    t->next = tmp->next;
                    tmp->next = t;
                    return;
                }
                else 
                    tmp = tmp->next; 
            }

            /* std::cout << "in the end" << std::endl; */
            tmp->next = t;
        }

        std::string print(){

            if(this->head == nullptr)
                return "Empty Polynomial"; 

            node* t = this->head;
            char buff[350];
            std::string ret = "";

            snprintf(buff, sizeof(buff), "%dx^%d", t->coeff(), t->exp());
            ret+=buff;
            t = t->next;

            while(t != nullptr)
            {
                snprintf(buff, sizeof(buff), " + %dx^%d", t->coeff(), t->exp());
                ret += buff;
                t = t->next;
            }

            return ret;
        }
};

int main()
{
    polynomial p1 = polynomial();
    
    p1.addTerm(node(term(1,3)));
    p1.addTerm(node(term(3,5)));
    p1.addTerm(node(term(1,3)));
    p1.addTerm(node(term(5,1)));
    p1.addTerm(node(term(5,6)));
    p1.addTerm(node(term(5,0)));

    std::cout << p1.print() + "\n";

    return 0;
}
