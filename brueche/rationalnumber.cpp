#include <iostream>
#include "rationalnumber.h"

using namespace std;

RationalNumber number1 = {2, 4};
RationalNumber number2 = {2, 3};

bool rnIsValid (RationalNumber number){
   return (number.denominator);
}

bool rnEqual(RationalNumber n1 , RationalNumber n2){
    return (n1.numerator == n2.numerator && n1.denominator == n2.denominator);
}

bool rnLessThan(RationalNumber n1, RationalNumber n2){
    if (rnEqual(n1, n2)){
        return false;
    }
    if (n1.denominator < n2.denominator){
        return true;
    }else false;
}

int rnAdd( ){

}






