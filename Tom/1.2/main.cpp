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

    RationalNumberCollection c;

    RationalNumber  rn1 = { 2, 3 },
                    rn2 = { 1, 3 },
                    rn3 = { 6, -3 },
                    rn4 = { 7, 1 },
                    rn5 = { 0, 3 },
                    rn6 = { 0, 12 },
                    rn7 = { -2, -3};

    rncInit(&c);
    RationalNumber (*ptr)[2] = c.rn;

    cout << endl << endl;
    cout << "Collection initiated..." << endl << endl;
    cout << "rncTotalUniqueCount()          : " << rncTotalUniqueCount(&c) << endl;
    assert(rncTotalUniqueCount(&c) == 0);
    cout << "rncTtotalCount()               : " << rncTotalCount(&c) << endl;
    assert(rncTotalCount(&c) == 0);
    cout << "rncSum()                       : " << rncSum(&c) << endl;
    assert(rncSum(&c) == 0);
    cout << "rncAverage()                   : " << rncAverage(&c) << endl;
    assert(rncAverage(&c) == 0);
    cout << "rncMedian()                    : " << rncMedian(&c) << endl;
    assert(rncMedian(&c) == 0);
    cout << endl << "Collection                     : ";
    for (int i=0; i<rncTotalUniqueCount(&c); i++) {
        if (i == 0) {
            cout << "[" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
            continue;
        }
        cout << "                                 [" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
    }
    cout << "------------------------------------------------------------" << endl;
    cout << "rncAdd()                       : " << rn1.numerator << "/" << rn1.denominator << endl;
    rncAdd(&c, rn1);
    cout << "rncCount()                     : " << rncCount(&c, rn1) << endl;
    assert(rncCount(&c, rn1) == 1);
    cout << "rncTotalUniqueCount()          : " << rncTotalUniqueCount(&c) << endl;
    assert(rncTotalUniqueCount(&c) == 1);
    cout << "rncTtotalCount()               : " << rncTotalCount(&c) << endl;
    assert(rncTotalCount(&c) == 1);
    cout << "rncSum()                       : " << rncSum(&c) << endl;
    assert(rncSum(&c) == (double) rn1.numerator/rn1.denominator);
    cout << "rncAverage()                   : " << rncAverage(&c) << endl;
    assert(rncAverage(&c) == (double) rn1.numerator/rn1.denominator);
    cout << "rncMedian()                    : " << rncMedian(&c) << endl;
    assert(rncMedian(&c) == (double) rn1.numerator/rn1.denominator);
    cout << endl << "Collection                     : ";
    for (int i=0; i<rncTotalUniqueCount(&c); i++) {
        if (i == 0) {
            cout << "[" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
            continue;
        }
        cout << "                                 [" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
    }
    cout << "------------------------------------------------------------" << endl;
    cout << "rncAdd()                       : " << rn7.numerator << "/" << rn7.denominator << endl;
    rncAdd(&c, rn7);
    cout << "rncCount()                     : " << rncCount(&c, rn7) << endl;
    assert(rncCount(&c, rn1) == 2);
    cout << "rncTotalUniqueCount()          : " << rncTotalUniqueCount(&c) << endl;
    assert(rncTotalUniqueCount(&c) == 1);
    cout << "rncTtotalCount()               : " << rncTotalCount(&c) << endl;
    assert(rncTotalCount(&c) == 2);
    cout << "rncSum()                       : " << rncSum(&c) << endl;
    assert(rncSum(&c) == (((double) rn1.numerator/rn1.denominator) * 2));
    cout << "rncAverage()                   : " << rncAverage(&c) << endl;
    assert(rncAverage(&c) == (double) rn1.numerator/rn1.denominator);
    cout << "rncMedian()                    : " << rncMedian(&c) << endl;
    assert(rncMedian(&c) == (double) rn1.numerator/rn1.denominator);
    cout << endl << "Collection                     : ";
    for (int i=0; i<rncTotalUniqueCount(&c); i++) {
        if (i == 0) {
            cout << "[" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
            continue;
        }
        cout << "                                 [" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
    }
    cout << "------------------------------------------------------------" << endl;
    cout << "rncAdd()                       : " << rn6.numerator << "/" << rn6.denominator << endl;
    rncAdd(&c, rn6);
    cout << "rncCount()                     : " << rncCount(&c, rn6) << endl;
    assert(rncCount(&c, rn6) == 1);
    cout << "rncTotalUniqueCount()          : " << rncTotalUniqueCount(&c) << endl;
    assert(rncTotalUniqueCount(&c) == 2);
    cout << "rncTtotalCount()               : " << rncTotalCount(&c) << endl;
    assert(rncTotalCount(&c) == 3);
    cout << "rncSum()                       : " << rncSum(&c) << endl;
    assert(rncSum(&c) == (((double) rn1.numerator/rn1.denominator) * 2));
    cout << "rncAverage()                   : " << rncAverage(&c) << endl;
    assert(rncAverage(&c) == (((double) rn1.numerator/rn1.denominator) * 2 / 3));
    cout << "rncMedian()                    : " << rncMedian(&c) << endl;
    assert(rncMedian(&c) == (((double) rn1.numerator/rn1.denominator) / 2));
    cout << endl << "Collection                     : ";
    for (int i=0; i<rncTotalUniqueCount(&c); i++) {
        if (i == 0) {
            cout << "[" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
            continue;
        }
        cout << "                                 [" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
    }
    cout << "------------------------------------------------------------" << endl;
    cout << "rncRemove()                    : " << rn1.numerator << "/" << rn1.denominator << endl;
    rncRemove(&c, rn1);
    cout << "rncCount()                     : " << rncCount(&c, rn1) << endl;
    assert(rncCount(&c, rn1) == 1);
    cout << "rncTotalUniqueCount()          : " << rncTotalUniqueCount(&c) << endl;
    assert(rncTotalUniqueCount(&c) == 2);
    cout << "rncTtotalCount()               : " << rncTotalCount(&c) << endl;
    assert(rncTotalCount(&c) == 2);
    cout << "rncSum()                       : " << rncSum(&c) << endl;
    assert(rncSum(&c) == ((double) rn1.numerator/rn1.denominator));
    cout << "rncAverage()                   : " << rncAverage(&c) << endl;
    assert(rncAverage(&c) == (((double) rn1.numerator/rn1.denominator) / 2));
    cout << "rncMedian()                    : " << rncMedian(&c) << endl;
    assert(rncMedian(&c) == (((double) rn1.numerator/rn1.denominator) / 2));
    cout << endl << "Collection                     : ";
    for (int i=0; i<rncTotalUniqueCount(&c); i++) {
        if (i == 0) {
            cout << "[" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
            continue;
        }
        cout << "                                 [" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
    }
    cout << "------------------------------------------------------------" << endl;
    cout << "rncAdd()                       : " << rn4.numerator << "/" << rn4.denominator << endl;
    rncAdd(&c, rn4);
    cout << "rncCount()                     : " << rncCount(&c, rn4) << endl;
    assert(rncCount(&c, rn4) == 1);
    cout << "rncTotalUniqueCount()          : " << rncTotalUniqueCount(&c) << endl;
    assert(rncTotalUniqueCount(&c) == 3);
    cout << "rncTtotalCount()               : " << rncTotalCount(&c) << endl;
    assert(rncTotalCount(&c) == 3);
    cout << "rncSum()                       : " << rncSum(&c) << endl;
    assert(rncSum(&c) == (((double) rn1.numerator/rn1.denominator) + 7));
    cout << "rncAverage()                   : " << rncAverage(&c) << endl;
    assert(rncAverage(&c) == ((((double) rn1.numerator/rn1.denominator) + 7) / 3));
    cout << "rncMedian()                    : " << rncMedian(&c) << endl;
    assert(rncMedian(&c) == (double) rn1.numerator/rn1.denominator);
    cout << endl << "Collection                     : ";
    for (int i=0; i<rncTotalUniqueCount(&c); i++) {
        if (i == 0) {
            cout << "[" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
            continue;
        }
        cout << "                                 [" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
    }
    cout << "------------------------------------------------------------" << endl;
    cout << "rncAdd()                       : " << rn2.numerator << "/" << rn2.denominator << endl;
    rncAdd(&c, rn2);
    cout << "rncCount()                     : " << rncCount(&c, rn2) << endl;
    assert(rncCount(&c, rn2) == 1);
    cout << "rncTotalUniqueCount()          : " << rncTotalUniqueCount(&c) << endl;
    assert(rncTotalUniqueCount(&c) == 4);
    cout << "rncTtotalCount()               : " << rncTotalCount(&c) << endl;
    assert(rncTotalCount(&c) == 4);
    cout << "rncSum()                       : " << rncSum(&c) << endl;
    assert(rncSum(&c) == 8);
    cout << "rncAverage()                   : " << rncAverage(&c) << endl;
    assert(rncAverage(&c) == 2);
    cout << "rncMedian()                    : " << rncMedian(&c) << endl;
    assert(rncMedian(&c) == (double) 1/2);
    cout << endl << "Collection                     : ";
    for (int i=0; i<rncTotalUniqueCount(&c); i++) {
        if (i == 0) {
            cout << "[" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
            continue;
        }
        cout << "                                 [" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
    }
    cout << "------------------------------------------------------------" << endl;
    cout << "rncAdd()                       : " << rn3.numerator << "/" << rn3.denominator << endl;
    rncAdd(&c, rn3);
    cout << "rncCount()                     : " << rncCount(&c, rn3) << endl;
    assert(rncCount(&c, rn3) == 1);
    cout << "rncTotalUniqueCount()          : " << rncTotalUniqueCount(&c) << endl;
    assert(rncTotalUniqueCount(&c) == 5);
    cout << "rncTtotalCount()               : " << rncTotalCount(&c) << endl;
    assert(rncTotalCount(&c) == 5);
    cout << "rncSum()                       : " << rncSum(&c) << endl;
    assert(rncSum(&c) == 6);
    cout << "rncAverage()                   : " << rncAverage(&c) << endl;
    assert(rncAverage(&c) == (double) 6/5);
    cout << "rncMedian()                    : " << rncMedian(&c) << endl;
    assert(rncMedian(&c) == (double) 1/3);
    cout << endl << "Collection                     : ";
    for (int i=0; i<rncTotalUniqueCount(&c); i++) {
        if (i == 0) {
            cout << "[" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
            continue;
        }
        cout << "                                 [" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
    }
    cout << "------------------------------------------------------------" << endl;
    cout << "rncAdd()                       : " << rn4.numerator << "/" << rn4.denominator << endl;
    rncAdd(&c, rn4);
    cout << "rncCount()                     : " << rncCount(&c, rn4) << endl;
    assert(rncCount(&c, rn4) == 2);
    cout << "rncTotalUniqueCount()          : " << rncTotalUniqueCount(&c) << endl;
    assert(rncTotalUniqueCount(&c) == 5);
    cout << "rncTtotalCount()               : " << rncTotalCount(&c) << endl;
    assert(rncTotalCount(&c) == 6);
    cout << "rncSum()                       : " << rncSum(&c) << endl;
    assert(rncSum(&c) == 13);
    cout << "rncAverage()                   : " << rncAverage(&c) << endl;
    assert(rncAverage(&c) == (double) 13/6);
    cout << "rncMedian()                    : " << rncMedian(&c) << endl;
    assert(rncMedian(&c) == (double) 1/3);
    cout << endl << "Collection                     : ";
    for (int i=0; i<rncTotalUniqueCount(&c); i++) {
        if (i == 0) {
            cout << "[" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
            continue;
        }
        cout << "                                 [" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
    }
    cout << "------------------------------------------------------------" << endl;
    cout << "rncAdd()                       : " << rn5.numerator << "/" << rn5.denominator << endl;
    rncAdd(&c, rn5);
    cout << "rncCount()                     : " << rncCount(&c, rn5) << endl;
    assert(rncCount(&c, rn5) == 2);
    cout << "rncTotalUniqueCount()          : " << rncTotalUniqueCount(&c) << endl;
    assert(rncTotalUniqueCount(&c) == 5);
    cout << "rncTtotalCount()               : " << rncTotalCount(&c) << endl;
    assert(rncTotalCount(&c) == 7);
    cout << "rncSum()                       : " << rncSum(&c) << endl;
    assert(rncSum(&c) == 13);
    cout << "rncAverage()                   : " << rncAverage(&c) << endl;
    assert(rncAverage(&c) == (double) 13/7);
    cout << "rncMedian()                    : " << rncMedian(&c) << endl;
    assert(rncMedian(&c) == (double) 1/3);
    cout << endl << "Collection                     : ";
    for (int i=0; i<rncTotalUniqueCount(&c); i++) {
        if (i == 0) {
            cout << "[" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
            continue;
        }
        cout << "                                 [" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
    }
    cout << "------------------------------------------------------------" << endl;
    cout << "rncRemove()                    : " << rn3.numerator << "/" << rn3.denominator << endl;
    rncRemove(&c, rn3);
    cout << "rncCount()                     : " << rncCount(&c, rn3) << endl;
    assert(rncCount(&c, rn3) == 0);
    cout << "rncTotalUniqueCount()          : " << rncTotalUniqueCount(&c) << endl;
    assert(rncTotalUniqueCount(&c) == 4);
    cout << "rncTtotalCount()               : " << rncTotalCount(&c) << endl;
    assert(rncTotalCount(&c) == 6);
    cout << "rncSum()                       : " << rncSum(&c) << endl;
    assert(rncSum(&c) == 15);
    cout << "rncAverage()                   : " << rncAverage(&c) << endl;
    assert(rncAverage(&c) == (double) 5 / 2);
    cout << "rncMedian()                    : " << rncMedian(&c) << endl;
    assert(rncMedian(&c) == (double) 1 / 2);
    cout << endl << "Collection                     : ";
    for (int i=0; i<rncTotalUniqueCount(&c); i++) {
        if (i == 0) {
            cout << "[" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
            continue;
        }
        cout << "                                 [" << ptr[i][0].numerator << "," << ptr[i][0].denominator << "] (" << ptr[i][1].numerator << ")" << endl;
    }
    cout << "------------------------------------------------------------" << endl << endl;

    printf(" successful!\n");

    return 0;
}
