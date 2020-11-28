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
};

class node{
    public:
        term data;
        node* next;

        node() : data(term(1,2)), next(NULL){}

        node(term exp) : data(exp), next(NULL){}

        int* exp(){ return this->data.exponent;};
        int* coeff(){ return this->data.coefficient;};
};

class polynomial{
    public: 
        node* head;

        void addTerm(term* exp)
        {
            node t = node(*exp); 

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
};

int main()
{
    
    return 0;
}
