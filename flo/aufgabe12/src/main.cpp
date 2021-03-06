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
    int rnIndexCount;
    int test = 0;
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

    cout << "Add rn0: " << rn0.num << "/" << rn0.denum << endl;
    rncAdd(&rnc, rn0);

    cout << "Add rn0: " << rn0.num << "/" << rn0.denum << "\n" << endl;
    rncAdd(&rnc, rn0);

    test++;
    cout << "Test #" << test << ": Average and medianshould be rn0 (" << rn0.num << "/" << rn0.denum << ")\nas there was only rn0 added to the collection.\n" << endl;
    assert(rnEqual(rncAverage(&rnc), rn0));
    assert(rnEqual(rncMedian(&rnc), rn0));
    showRnwcStatus(&rnc);

    cout << "Add rn1: " << rn1.num << "/" << rn1.denum << endl;
    rncAdd(&rnc, rn1);
    showRnwcStatus(&rnc);

    cout << "Add rn2: " << rn2.num << "/" << rn2.denum << endl;
    rncAdd(&rnc, rn2);
    showRnwcStatus(&rnc);

    cout << "Add rn3: " << rn3.num << "/" << rn3.denum << endl;
    rncAdd(&rnc, rn3);

    test++;
    cout << "Test #" << test << ": Count of rn3 (" << rn3.num << "/" << rn3.denum << ")\nshould be 3 as it is equal to rn1 and rn2.\n" << endl;
    assert(rncCount(&rnc, rn3) == 3);
    showRnwcStatus(&rnc);

    cout << "Add rn6: " << rn6.num << "/" << rn6.denum << endl;
    rncAdd(&rnc, rn6);

    test++;
    cout << "Test #" << test << ": Negative RationalNumber rn6 (" << rn6.num << "/" << rn6.denum << ")\nadded, sum should be 37/7.\n" << endl;
    assert(rnEqual(rncSum(&rnc), {37,7}));
    showRnwcStatus(&rnc);

    cout << "Add rn2: " << rn2.num << "/" << rn2.denum << endl;
    rncAdd(&rnc, rn2);

    cout << "Add rn3: " << rn3.num << "/" << rn3.denum << endl;
    rncAdd(&rnc, rn3);

    cout << "Add rn4: " << rn4.num << "/" << rn4.denum << endl;
    rncAdd(&rnc, rn4);

    cout << "Add rn5: " << rn5.num << "/" << rn5.denum << endl;
    rncAdd(&rnc, rn5);
    cout << "Add rn5: " << rn5.num << "/" << rn5.denum << "\n" << endl;
    rncAdd(&rnc, rn5);

    test++;
    cout << "Test #" << test << ": Total unique count should not\nincrease as " << rn5.num << "/" << rn5.denum << " is not a valid RationalNumber.\n" << endl;
    assert(rncTotalUniqueCount(&rnc) == 4);
    showRnwcStatus(&rnc);

    cout << "Add rn2: " << rn2.num << "/" << rn2.denum << endl;
    rncAdd(&rnc, rn2);

    cout << "Add rn6: " << rn6.num << "/" << rn6.denum << endl;
    rncAdd(&rnc, rn6);

    cout << "Add rn7: " << rn7.num << "/" << rn7.denum << endl;
    rncAdd(&rnc, rn7);

    rncAdd(&rnc, rn8);
    cout << "Add rn8: " << rn8.num << "/" << rn8.denum << endl;
    showRnwcStatus(&rnc);

    rncAdd(&rnc, rn9);
    cout << "Add rn9: " << rn9.num << "/" << rn9.denum << endl;
    showRnwcStatus(&rnc);

    test++;
    cout << "Test #" << test << ": Count of rn2 (" << rn2.num << "/" << rn2.denum << ")\nshould be 6 as it is equal to rn1 and rn3.\n" << endl;
    assert(rncCount(&rnc, rn2) == 6);
    showRnwcStatus(&rnc);

    test++;
    cout << "Test #" << test << ": Count of rn2 (" << rn2.num << "/" << rn2.denum << ")\nshould be 5 as we removed one rn2.\n" << endl;
    rnIndexCount = rncRemove(&rnc, rn2);
    assert(rncCount(&rnc, rn2) == 5);
    showRnwcStatus(&rnc);

    test++;
    cout << "Test #" << test << ": Count of rn9 (" << rn9.num << "/" << rn9.denum << ")\nshould be 1 as we only added it one time.\n" << endl;
    assert(rncCount(&rnc, rn9) == 1);

    rnIndexCount = rncRemove(&rnc, rn9);
    test++;
    cout << "Test #" << test << ": Total unique Count should be 5\nas we removed one rn9.\n" << endl;
    assert(rncTotalUniqueCount(&rnc) == 5);

    test++;
    cout << "Test #" << test << ": Count of rn9 (" << rn9.num << "/" << rn9.denum << ")\nshould be 0 as we removed the only rn9.\n" << endl;
    assert(rncCount(&rnc, rn9) == 0);
    showRnwcStatus(&rnc);

    test++;
    cout << "Test #" << test << ": Total count should be 12 as we\nadded 16 RationalNumber of which 2 where\nnot valid (" << rn5.num << "/" << rn5.denum << ") and 2 where removed.\n" << endl;
    assert(rncTotalCount(&rnc) == 12);
    showRnwcStatus(&rnc);

    printf("\nSuccessful!\n");

    return 0;
}

