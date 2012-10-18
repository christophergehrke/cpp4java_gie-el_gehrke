#include <stdio.h>
#include <assert.h>
#include <iostream>
using namespace std;

#include "RationalNumber.h"
#include "RationalNumberCollection.h"


int main() {

    printf("Performing unit tests for RationalNumber...");
    fflush(stdout);

    /* Part 1 - RationalNumber data type */
    RationalNumber  n1 = { 3, 4 },
                    n2 = { 6, 4 },
                    n3 = { 3, 2 },
                    n4 = { -9, -6 },
                    n5 = { 9, -6 },
                    n6 = { 9, 4 },
                    n0 = { 0, 4 },
                    nn = { 4, 0 };

    assert( rnIsValid(n0) );
    assert( !rnIsValid(nn) );

    assert( rnEqual( n2, n3) );
    assert( rnEqual( rnAdd(n1,n1), n2) );
    assert( rnEqual( n2,n4) );
    assert( !rnEqual( n4,n5) );
    assert( rnLessThan( n5,n3) );

    RationalNumber t1 = rnAdd(n1,n2);
    RationalNumber t2 = rnDivide(n3,n3);
    RationalNumber t3 = rnDivide(n2,n2);
    RationalNumber t4 = rnDivide(n6,n0);

    assert( rnEqual(t1, n6) );
    assert( rnEqual(t2, t3) );
    assert( !rnIsValid(t4) );

    printf(" successful!\n");

    printf("Performing unit tests for RationalNumberCollection...");

    RationalNumberCollection c = rncCreate(100);

    RationalNumber rn1 = { 2, 3 },
                   rn2 = { 1, 3 },
                   rn3 = { 6, -3 },
                   rn4 = { 7, 1 },
                   rn5 = { 0, 3 },
                   rn6 = { 0, 12 },
                   rn7 = { -2, -3},
                   res1 = { 0, 1 },
                   res2 = { 4, 3 },
                   res3 = { 4, 9 },
                   res4 = { 23, 3 },
                   res5 = { 23, 9 },
                   res6 = { 8, 1 },
                   res7 = { 2, 1 },
                   res8 = { 1, 2 },
                   res9 = { 6, 1 },
                   res10 = { 6, 5 },
                   res11 = { 13, 1 },
                   res12 = { 13, 6 },
                   res13 = { 13, 7 },
                   res14 = { 15, 1 },
                   res15 = { 5, 2 };

    printf("\n\nCollection initiated...\n\n");

    assert(rncTotalUniqueCount(c) == 0);
    assert(rncTotalCount(c) == 0);
    assert(rnEqual(rncSum(c), res1));
    assert(rnEqual(rncAverage(c), res1));
    assert(rnEqual(rncMedian(c), res1));

    printf("rncTotalUniqueCount()      : %i\n", rncTotalUniqueCount(c));
    printf("rncTotalCount()            : %i\n", rncTotalCount(c));
    printf("rncSum()                   : %i/%i\n", rncSum(c).numerator, rncSum(c).denominator);
    printf("rncAverage()               : %i/%i\n", rncAverage(c).numerator, rncAverage(c).denominator);
    printf("rncMedian()                : %i/%i\n\n", rncMedian(c).numerator, rncMedian(c).denominator);
    printf("rncSize()                  : %i\n\n", rncSize(c));
    printf("Collection:\n");
    rncPrint(c);
    printf("\n----------------------------------\n\n");

    rncAdd(c, rn1);
    assert(rncCount(c, rn1) == 1);
    assert(rncTotalUniqueCount(c) == 1);
    assert(rncTotalCount(c) == 1);
    assert(rnEqual(rncSum(c), rn1));
    assert(rnEqual(rncAverage(c), rn1));
    assert(rnEqual(rncMedian(c), rn1));

    printf("rncAdd()                   : %i/%i\n", rn1.numerator, rn1.denominator);
    printf("rncCount()                 : %i\n", rncCount(c, rn1));
    printf("rncTotalUniqueCount()      : %i\n", rncTotalUniqueCount(c));
    printf("rncTotalCount()            : %i\n", rncTotalCount(c));
    printf("rncSum()                   : %i/%i\n", rncSum(c).numerator, rncSum(c).denominator);
    printf("rncAverage()               : %i/%i\n", rncAverage(c).numerator, rncAverage(c).denominator);
    printf("rncMedian()                : %i/%i\n\n", rncMedian(c).numerator, rncMedian(c).denominator);
    printf("rncSize()                  : %i\n\n", rncSize(c));
    printf("Collection:\n");
    rncPrint(c);
    printf("\n----------------------------------\n\n");

    rncAdd(c, rn7);
    assert(rncCount(c, rn1) == 2);
    assert(rncTotalUniqueCount(c) == 1);
    assert(rncTotalCount(c) == 2);
    assert(rnEqual(rncSum(c), res2));
    assert(rnEqual(rncAverage(c), rn1));
    assert(rnEqual(rncMedian(c), rn1));

    printf("rncAdd()                   : %i/%i\n", rn7.numerator, rn7.denominator);
    printf("rncCount()                 : %i\n", rncCount(c, rn7));
    printf("rncTotalUniqueCount()      : %i\n", rncTotalUniqueCount(c));
    printf("rncTotalCount()            : %i\n", rncTotalCount(c));
    printf("rncSum()                   : %i/%i\n", rncSum(c).numerator, rncSum(c).denominator);
    printf("rncAverage()               : %i/%i\n", rncAverage(c).numerator, rncAverage(c).denominator);
    printf("rncMedian()                : %i/%i\n\n", rncMedian(c).numerator, rncMedian(c).denominator);
    printf("rncSize()                  : %i\n\n", rncSize(c));
    printf("Collection:\n");
    rncPrint(c);
    printf("\n----------------------------------\n\n");

    rncAdd(c, rn6);
    assert(rncCount(c, rn6) == 1);
    assert(rncTotalUniqueCount(c) == 2);
    assert(rncTotalCount(c) == 3);
    assert(rnEqual(rncSum(c), res2));
    assert(rnEqual(rncAverage(c), res3));
    assert(rnEqual(rncMedian(c), rn2));

    printf("rncAdd()                   : %i/%i\n", rn6.numerator, rn6.denominator);
    printf("rncCount()                 : %i\n", rncCount(c, rn6));
    printf("rncTotalUniqueCount()      : %i\n", rncTotalUniqueCount(c));
    printf("rncTotalCount()            : %i\n", rncTotalCount(c));
    printf("rncSum()                   : %i/%i\n", rncSum(c).numerator, rncSum(c).denominator);
    printf("rncAverage()               : %i/%i\n", rncAverage(c).numerator, rncAverage(c).denominator);
    printf("rncMedian()                : %i/%i\n\n", rncMedian(c).numerator, rncMedian(c).denominator);
    printf("rncSize()                  : %i\n\n", rncSize(c));
    printf("Collection:\n");
    rncPrint(c);
    printf("\n----------------------------------\n\n");

    rncRemove(c, rn1);
    assert(rncCount(c, rn1) == 1);
    assert(rncTotalUniqueCount(c) == 2);
    assert(rncTotalCount(c) == 2);
    assert(rnEqual(rncSum(c), rn1));
    assert(rnEqual(rncAverage(c), rn2));
    assert(rnEqual(rncMedian(c), rn2));

    printf("rncRemove()                : %i/%i\n", rn1.numerator, rn1.denominator);
    printf("rncCount()                 : %i\n", rncCount(c, rn1));
    printf("rncTotalUniqueCount()      : %i\n", rncTotalUniqueCount(c));
    printf("rncTotalCount()            : %i\n", rncTotalCount(c));
    printf("rncSum()                   : %i/%i\n", rncSum(c).numerator, rncSum(c).denominator);
    printf("rncAverage()               : %i/%i\n", rncAverage(c).numerator, rncAverage(c).denominator);
    printf("rncMedian()                : %i/%i\n\n", rncMedian(c).numerator, rncMedian(c).denominator);
    printf("rncSize()                  : %i\n\n", rncSize(c));
    printf("Collection:\n");
    rncPrint(c);
    printf("\n----------------------------------\n\n");

    rncAdd(c, rn4);
    assert(rncCount(c, rn4) == 1);
    assert(rncTotalUniqueCount(c) == 3);
    assert(rncTotalCount(c) == 3);
    assert(rnEqual(rncSum(c), res4));
    assert(rnEqual(rncAverage(c), res5));
    assert(rnEqual(rncMedian(c), rn1));

    printf("rncAdd()                   : %i/%i\n", rn4.numerator, rn4.denominator);
    printf("rncCount()                 : %i\n", rncCount(c, rn4));
    printf("rncTotalUniqueCount()      : %i\n", rncTotalUniqueCount(c));
    printf("rncTotalCount()            : %i\n", rncTotalCount(c));
    printf("rncSum()                   : %i/%i\n", rncSum(c).numerator, rncSum(c).denominator);
    printf("rncAverage()               : %i/%i\n", rncAverage(c).numerator, rncAverage(c).denominator);
    printf("rncMedian()                : %i/%i\n\n", rncMedian(c).numerator, rncMedian(c).denominator);
    printf("rncSize()                  : %i\n\n", rncSize(c));
    printf("Collection:\n");
    rncPrint(c);
    printf("\n----------------------------------\n\n");

    rncAdd(c, rn2);
    assert(rncCount(c, rn2) == 1);
    assert(rncTotalUniqueCount(c) == 4);
    assert(rncTotalCount(c) == 4);
    assert(rnEqual(rncSum(c), res6));
    assert(rnEqual(rncAverage(c), res7));
    assert(rnEqual(rncMedian(c), res8));

    printf("rncAdd()                   : %i/%i\n", rn2.numerator, rn2.denominator);
    printf("rncCount()                 : %i\n", rncCount(c, rn2));
    printf("rncTotalUniqueCount()      : %i\n", rncTotalUniqueCount(c));
    printf("rncTotalCount()            : %i\n", rncTotalCount(c));
    printf("rncSum()                   : %i/%i\n", rncSum(c).numerator, rncSum(c).denominator);
    printf("rncAverage()               : %i/%i\n", rncAverage(c).numerator, rncAverage(c).denominator);
    printf("rncMedian()                : %i/%i\n\n", rncMedian(c).numerator, rncMedian(c).denominator);
    printf("rncSize()                  : %i\n\n", rncSize(c));
    printf("Collection:\n");
    rncPrint(c);
    printf("\n----------------------------------\n\n");

    rncAdd(c, rn3);
    assert(rncCount(c, rn3) == 1);
    assert(rncTotalUniqueCount(c) == 5);
    assert(rncTotalCount(c) == 5);
    assert(rnEqual(rncSum(c), res9));
    assert(rnEqual(rncAverage(c), res10));
    assert(rnEqual(rncMedian(c), rn2));

    printf("rncAdd()                   : %i/%i\n", rn3.numerator, rn3.denominator);
    printf("rncCount()                 : %i\n", rncCount(c, rn3));
    printf("rncTotalUniqueCount()      : %i\n", rncTotalUniqueCount(c));
    printf("rncTotalCount()            : %i\n", rncTotalCount(c));
    printf("rncSum()                   : %i/%i\n", rncSum(c).numerator, rncSum(c).denominator);
    printf("rncAverage()               : %i/%i\n", rncAverage(c).numerator, rncAverage(c).denominator);
    printf("rncMedian()                : %i/%i\n\n", rncMedian(c).numerator, rncMedian(c).denominator);
    printf("rncSize()                  : %i\n\n", rncSize(c));
    printf("Collection:\n");
    rncPrint(c);
    printf("\n----------------------------------\n\n");

    rncAdd(c, rn4);
    assert(rncCount(c, rn4) == 2);
    assert(rncTotalUniqueCount(c) == 5);
    assert(rncTotalCount(c) == 6);
    assert(rnEqual(rncSum(c), res11));
    assert(rnEqual(rncAverage(c), res12));
    assert(rnEqual(rncMedian(c), rn2));

    printf("rncAdd()                   : %i/%i\n", rn4.numerator, rn4.denominator);
    printf("rncCount()                 : %i\n", rncCount(c, rn4));
    printf("rncTotalUniqueCount()      : %i\n", rncTotalUniqueCount(c));
    printf("rncTotalCount()            : %i\n", rncTotalCount(c));
    printf("rncSum()                   : %i/%i\n", rncSum(c).numerator, rncSum(c).denominator);
    printf("rncAverage()               : %i/%i\n", rncAverage(c).numerator, rncAverage(c).denominator);
    printf("rncMedian()                : %i/%i\n\n", rncMedian(c).numerator, rncMedian(c).denominator);
    printf("rncSize()                  : %i\n\n", rncSize(c));
    printf("Collection:\n");
    rncPrint(c);
    printf("\n----------------------------------\n\n");

    rncAdd(c, rn5);
    assert(rncCount(c, rn5) == 2);
    assert(rncTotalUniqueCount(c) == 5);
    assert(rncTotalCount(c) == 7);
    assert(rnEqual(rncSum(c), res11));
    assert(rnEqual(rncAverage(c), res13));
    assert(rnEqual(rncMedian(c), rn2));

    printf("rncAdd()                   : %i/%i\n", rn5.numerator, rn5.denominator);
    printf("rncCount()                 : %i\n", rncCount(c, rn5));
    printf("rncTotalUniqueCount()      : %i\n", rncTotalUniqueCount(c));
    printf("rncTotalCount()            : %i\n", rncTotalCount(c));
    printf("rncSum()                   : %i/%i\n", rncSum(c).numerator, rncSum(c).denominator);
    printf("rncAverage()               : %i/%i\n", rncAverage(c).numerator, rncAverage(c).denominator);
    printf("rncMedian()                : %i/%i\n\n", rncMedian(c).numerator, rncMedian(c).denominator);
    printf("rncSize()                  : %i\n\n", rncSize(c));
    printf("Collection:\n");
    rncPrint(c);
    printf("\n----------------------------------\n\n");

    rncRemove(c, rn3);
    assert(rncCount(c, rn3) == 0);
    assert(rncTotalUniqueCount(c) == 4);
    assert(rncTotalCount(c) == 6);
    assert(rnEqual(rncSum(c), res14));
    assert(rnEqual(rncAverage(c), res15));
    assert(rnEqual(rncMedian(c), res8));

    printf("rncRemove()                : %i/%i\n", rn3.numerator, rn3.denominator);
    printf("rncCount()                 : %i\n", rncCount(c, rn3));
    printf("rncTotalUniqueCount()      : %i\n", rncTotalUniqueCount(c));
    printf("rncTotalCount()            : %i\n", rncTotalCount(c));
    printf("rncSum()                   : %i/%i\n", rncSum(c).numerator, rncSum(c).denominator);
    printf("rncAverage()               : %i/%i\n", rncAverage(c).numerator, rncAverage(c).denominator);
    printf("rncMedian()                : %i/%i\n", rncMedian(c).numerator, rncMedian(c).denominator);
    printf("rncSize()                  : %i\n\n", rncSize(c));
    printf("Collection:\n");
    rncPrint(c);
    printf("\n----------------------------------\n\n");

    RationalNumber testrn = { 0, 1 };
    for (int i=0; i<98; i++) {
        rncAdd(c, testrn);
        testrn.numerator++;
    }

    printf("Collection vor Vergroessern:\n\n");
    rncPrint(c);
    printf("rncSize()                  : %i\n", rncSize(c));
    printf("\n----------------------------------\n\n");

    for (int i=0; i<5; i++) {
        rncAdd(c, testrn);
        testrn.numerator++;
    }

    printf("Collection vor Vergroessern:\n\n");
    rncPrint(c);
    printf("rncSize()                  : %i\n", rncSize(c));
    printf("\n----------------------------------\n\n");

    rncDelete(&c);

    printf("Collection nach Loeschen:\n");
    rncPrint(c);
    printf("rncSize()                  : %i\n", rncSize(c));
    printf("\n----------------------------------\n\n");

    printf(" successful!\n");

    return 0;
}
