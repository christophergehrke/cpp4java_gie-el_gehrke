#include "RationalNumber.h"


bool rnIsValid(RationalNumber n) {
    return (n.denominator != 0);
}

bool rnEqual(RationalNumber n1, RationalNumber n2) {
    // Kürzen der beiden Brüche, anschliessend vergleichen
    n1 = rnShorten(n1);
    n2 = rnShorten(n2);
    return (n1.numerator == n2.numerator && n1.denominator == n2.denominator);
}

bool rnLessThan(RationalNumber n1, RationalNumber n2) {

    // Brüche kürzen
    n1 = rnShorten(n1);
    n2 = rnShorten(n2);

    // Wenn beide Nenner > 0
    if (n1.denominator > 0 && n2.denominator > 0) {
        return (n1.numerator * n2.denominator < n1.denominator * n2.numerator);
    }
    // Wenn einer der beiden Nenner < 0, wird der Bruch *-1 genommen, dessen Nenner < 0 ist
    if (n1.denominator < 0 && n2.denominator > 0) {
        int num1 = n1.numerator * -1;
        int den1 = n1.denominator * -1;
        if (num1 * n2.denominator < den1 * n2.numerator) {
            return 1;
        }
        return 0;
    }
    if (n2.denominator < 0 && n1.denominator > 0) {
        int num2 = n2.numerator * -1;
        int den2 = n2.denominator * -1;
        if (n1.numerator * den2 == n1.denominator * num2) {
            return 1;
        }
        return 0;
    }
    return 0;
}

RationalNumber rnAdd(RationalNumber n1, RationalNumber n2) {
    RationalNumber result;
    // a*d + b*c / b*d
    result.numerator = (n1.numerator * n2.denominator) + (n1.denominator * n2.numerator);
    result.denominator = n1.denominator * n2.denominator;
    result = rnShorten(result);
    return result;
}

RationalNumber rnSubtract(RationalNumber n1, RationalNumber n2) {
    RationalNumber result;
    // a*d - b*c / b*d
    result.numerator = (n1.numerator * n2.denominator) - (n1.denominator * n2.numerator);
    result.denominator = n1.denominator * n2.denominator;
    return result;
}

RationalNumber rnMultiply(RationalNumber n1, RationalNumber n2) {
    RationalNumber result;
    // a_ = a*c     b_ = b*d
    result.numerator = n1.numerator * n2.numerator;
    result.denominator = n1.denominator * n2.denominator;
    result = rnShorten(result);
    return result;
}

RationalNumber rnDivide(RationalNumber n1, RationalNumber n2) {
    RationalNumber result;
    // Wenn Zähler von n2 != 0
    if (n2.numerator != 0) {
        // a_ = a*d     b_ = b*c
        result.numerator = n1.numerator * n2.denominator;
        result.denominator = n1.denominator * n2.numerator;
    }
    // Andernfalls ungültiger Bruch (0-Division)
    else {
        result.numerator = 0;
        result.denominator = 0;
    }
    return result;
}

RationalNumber rnShorten(RationalNumber n) {
    // Gröten gemeinsamen Teiler errechnen
    int gcd = rnEUCLID(n.numerator, n.denominator);
    // Bruch mit Hilfe des ggT kürzen
    RationalNumber rn = { n.numerator/gcd, n.denominator/gcd };
    return rn;
}

int rnEUCLID(int n1, int n2) {
    // Sobald kein Rest bei einer Division übrig bleibt, ist ggT gefunden
    while(n2 != 0) {
        int h = n1 % n2;
        n1 = n2;
        n2 = h;
    }
    return n1;
}
