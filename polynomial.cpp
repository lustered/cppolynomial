#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>

class term{
    public:
        int* coefficient;
        int* exponent;

        term(int coefficient, int exponent)
        {
            this->coefficient = &coefficient;
            this->exponent = &exponent;
        }

        std::string tv()
        {
            char buff[50];
            snprintf(buff, sizeof(buff), "%dx^%d",*this->coefficient, *this->exponent);
            std::string ret = buff;
            return ret;
        }
};

class node{
    public:
        term data;
        node* next;

        node() : data(term(3,5)), next(NULL){}

        node(term exp) : data(exp), next(NULL){}

        /* don't work */
        int* exp(){ return this->data.exponent;};
        int* coeff(){ return this->data.coefficient;};
};

class polynomial{
    public: 
        node* head;

        void addTerm(term* exp)
        {
            /* node t = node(*exp); */ 
            node t = *exp; 

            if(this->head == NULL) 
            {
                this->head = &t;
                return;
            }

            if(head->data.exponent > exp->exponent)
            {
                t.next = this->head;
                this->head = &t;
                return;
            }

            node* tmp = this->head;
            while(tmp != NULL)
            {
                if(tmp->next->coeff() >= exp->exponent)
                {
                    t.next = tmp->next;
                    tmp->next = &t;
                    return;
                }
            }
        }
        std::string print(){
            if(this->head == NULL)
                return "empty polynomial";

            node* t = this->head;
            char buff[350];
            std::string ret = "";

            while(t != NULL)
            {
                snprintf(buff, sizeof(buff), "%dx^%d + ", *t->coeff(), *t->exp());
                ret += buff;
                t = t->next;
            }

            return ret;
        }
};

int main()
{
    
    term t1 = term(3, 10);
    std::cout << t1.tv() << std::endl;
    /* node n1 = node(t1); */
    node n1 = node();
    /* std::cout << *n1.data.coefficient << " " << *n1.data.exponent << std::endl; */
    std::cout << n1.data.tv() << std::endl;
    return 0;
}
