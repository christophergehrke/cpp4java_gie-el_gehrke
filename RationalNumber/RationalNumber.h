#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H


struct RationalNumber {
    int numerator;
    int denominator;
};

bool rnIsValid(RationalNumber n);

bool rnEqual(RationalNumber n1, RationalNumber n2);

bool rnLessThan(RationalNumber n1, RationalNumber n2);

RationalNumber rnAdd(RationalNumber n1, RationalNumber n2);

RationalNumber rnSubtract(RationalNumber n1, RationalNumber n2);

RationalNumber rnMultiply(RationalNumber n1, RationalNumber n2);

RationalNumber rnDivide(RationalNumber n1, RationalNumber n2);

RationalNumber rnShorten(RationalNumber n);

int rnEUCLID(int n1, int n2);

#endif // RATIONALNUMBER_H
