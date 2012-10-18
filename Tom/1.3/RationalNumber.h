#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H


struct RationalNumber {
    int numerator,
        denominator;
};

/**
  * Checks if the given RationalNumber is valid (denominator equals 0)
  * @param n The RationalNumber
  * @return The result as bool
  */
bool rnIsValid(RationalNumber n);

/**
  * Checks if the given RationalNumbers are equal
  * @param n1 The first RationalNumber
  * @param n1 The second RationalNumber
  * @return The result as bool
  */
bool rnEqual(RationalNumber n1, RationalNumber n2);

/**
  * Checks if the first RationalNumber is less than the second one
  * @param n1 The first RationalNumber
  * @param n1 The second RationalNumber
  * @return The result as bool
  */
bool rnLessThan(RationalNumber n1, RationalNumber n2);

/**
  * Adds two given RationalNumbers
  * @param n1 The first RationalNumber
  * @param n1 The second RationalNumber
  * @return The result as RationalNumber
  */
RationalNumber rnAdd(RationalNumber n1, RationalNumber n2);

/**
  * Subtracts two given RationalNumbers
  * @param n1 The first RationalNumber
  * @param n1 The second RationalNumber
  * @return The result as RationalNumber
  */
RationalNumber rnSubtract(RationalNumber n1, RationalNumber n2);

/**
  * Multiplies two given RationalNumbers
  * @param n1 The first RationalNumber
  * @param n1 The second RationalNumber
  * @return The result as RationalNumber
  */
RationalNumber rnMultiply(RationalNumber n1, RationalNumber n2);

/**
  * Divides two given RationalNumbers
  * @param n1 The first RationalNumber
  * @param n1 The second RationalNumber
  * @return The result as RationalNumber
  */
RationalNumber rnDivide(RationalNumber n1, RationalNumber n2);

/**
  * Shortens a given RationalNumber
  * @param n1 The RationalNumber
  * @return The shortened RationalNumber
  */
RationalNumber rnShorten(RationalNumber n);

/**
  * Finds the greatest common divisor (gcd) of two numbers
  * @param n1 The first Number
  * @param n2 The seconds Number
  * @return The greatest common divisor (gcd) as int
  */
int rnEUCLID(int n1, int n2);

#endif // RATIONALNUMBER_H
