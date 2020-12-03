#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>


class polynomial{
    class node;
    class term;

    public: 
        node* head = nullptr;

        polynomial() : head(nullptr){}

        polynomial(const polynomial& p2)
        {
            this->head = new node(term(p2.head->data));
            node* ptr = this->head;
            node* ptr2 = p2.head->next;
            
            while(ptr2 != nullptr)
            {
                ptr->next = new node(term(ptr2->data));
                ptr2 = ptr2->next;
                ptr = ptr->next;
            }
        }

        /**
         * Add terms to the polynomial.
         * @param coeff coefficient.
         * @param expo exponent.
         */
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
            if(this->head->data.exp > expo)
            {
                t->next = this->head;
                this->head = t;
                return;
            }

            /* if the next term's exponent is <= than the adding tem */
            node* tmp = this->head;
            while(tmp->next != nullptr)
            {

                if(tmp->next->data.exp >= expo)
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

        polynomial multPol(polynomial p)
        {
            if(this->head == nullptr || p.head == nullptr)
                return polynomial();

            polynomial ret = polynomial();
            node* t2 = polynomial(p).head;

            while(t2 != nullptr)
            {
                node* t = polynomial(*this).head;

                while(t != nullptr)
                {
                    int nc = t2->data.coeff * t->data.coeff;
                    int ne = t2->data.exp + t->data.exp;
                    ret.addTerm(nc, ne);
                    t = t->next;
                }

                t2 = t2->next;
            }

            ret.combine();
            return ret;
        }

        polynomial addPol(polynomial p)
        {
            if(this->head == nullptr || p.head == nullptr)
                return polynomial();

            polynomial ret= polynomial(*this);
            polynomial cp = polynomial(p);

            node* t = ret.head;
            while(t != nullptr)
                t = t->next;

            node* t2 = cp.head;
            while(t2 != nullptr )
            {
                ret.addTerm(t2->data.coeff, t2->data.exp);
                t2 = t2->next;
            }
            ret.combine();

            return ret;
        }

        std::string print()
        {
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
                if(t->data.exp == t->next->data.exp)
                {
                    int nc = t->data.coeff + t->next->data.coeff;

                    term nt = term(nc, t->data.exp);
                    node* combined = new node(nt);
                    t->data = combined->data; 

                    t->next = (t->next->next != nullptr) ? t->next->next : nullptr;
                }
                else
                    t = t->next;
            }
        }

        class term{
            public:
                int coeff;
                int exp;

                term(int coeff, int expo) : coeff(coeff), exp(expo){}

                std::string termInfo()
                {
                    char buff[50];
                    snprintf(buff, sizeof(buff), "%dx^%d",this->coeff, this->exp);
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

                int exp(){ return this->data.exp;};
                int coeff(){ return this->data.coeff;};
        };
};

#endif
