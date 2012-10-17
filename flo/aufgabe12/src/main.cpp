/*
   Simple Unit Test for type RationalNumber
*/

#include <stdio.h>
#include <assert.h>
#include <iostream>
using namespace std;

#include "rationalnumber.h"
#include "rationalnumbercollection.h"

int main()
{

    printf("Performing unit tests for RationalNumber...\n");
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

    printf("\nSuccessful!\n");

    /* Part 2 - RationalNumberCollection data type */
    printf("Performing unit tests for RationalNumberCollection...\n");

    RationalNumberCollection rnc;
    RationalNumber rn0 = {3, 4},
            rn1 = {6, 4},
            rn2 = {3, 2},
            rn3 = {-9, -6},
            rn4 = {0, 4},
            rn5 = {4, 0},
            rn6 = {5, -7},
            rn7 = {2, 5},
            rn8 = {2, 5},
            rn9 = {5, 3};

    rncInit(&rnc);

    showRnwcStatus(&rnc);

    rncAdd(&rnc, rn0);
    rncAdd(&rnc, rn0);
    rncAdd(&rnc, rn1);
    rncAdd(&rnc, rn2);
    rncAdd(&rnc, rn3);
    rncAdd(&rnc, rn6);
    rncAdd(&rnc, rn2);
    rncAdd(&rnc, rn3);
    rncAdd(&rnc, rn4);
    rncAdd(&rnc, rn5);
    rncAdd(&rnc, rn5);
    rncAdd(&rnc, rn2);
    rncAdd(&rnc, rn6);
    rncAdd(&rnc, rn7);
    rncAdd(&rnc, rn8);
    rncAdd(&rnc, rn9);

    showRnwcStatus(&rnc);

    int rnIndexCount;

    cout << "\nTest if " << rn2.num << "/" << rn2.denum << " is 6 times in collection, remove" << endl;
    cout << "it and test if it is 5 times in collection." << endl;
    assert(rncCount(&rnc, rn2) == 6);
    rnIndexCount = rncRemove(&rnc, rn2);
    assert(rncCount(&rnc, rn2) == 5);

    showRnwcStatus(&rnc);

    assert(rncTotalUniqueCount(&rnc) == 6);
    assert(rncCount(&rnc, rn9) == 1);
    rnIndexCount = rncRemove(&rnc, rn9);
    assert(rncTotalUniqueCount(&rnc) == 5);
    assert(rncCount(&rnc, rn9) == 0);

    showRnwcStatus(&rnc);

    printf("\nSuccessful!\n");

    return 0;
}

