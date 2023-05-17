#ifndef BILL_H_INCLUDED
#define BILL_H_INCLUDED

#include "cart.h"

class Bill
{
    public:
        Bill();

        void gen_bill(Cart *);
};

#endif // BILL_H_INCLUDED
