#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

struct RationalNumber {
    int numerator;
    int denominator;

};

bool rnIsValid (RationalNumber n);
bool rnEqual ();
bool rnLessThan ();
int rnAdd();
int rnSubtract();
int rnMultiply();
int rnDivide();

#endif // RATIONALNUMBER_H
