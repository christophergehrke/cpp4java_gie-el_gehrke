#ifndef RATIONALNUMBERCOLLECTION_H
#define RATIONALNUMBERCOLLECTION_H

#include "RationalNumber.h"

const int MAXSIZE = 1000;

struct RationalNumberCollection {
    RationalNumber rn[MAXSIZE][2];
    int totalUniqueCount,
        totalCount;
    RationalNumber sum,
                   average,
                   median;
};

/**
  * Initializes the given RationalNumberCollection, filling it with RatinonalNumbers
  * with its numerator and denominator value of 0.
  * @param c A pointer to the RationalNumberCollection.
  */
void rncInit(RationalNumberCollection *c);

/**
  * Returns the amount of unique RationalNumbers of the given RationalNumberCollection.
  * @param c A pointer to the RationalNumberCollection.
  * @return The amount of unique RationalNumbers.
  */
int rncTotalUniqueCount(RationalNumberCollection *c);

/**
  * Returns the total amount of RationalNumbers of the given RationalNumberCollection.
  * @param c A pointer to the RationalNumberCollection.
  * @return The total amount of RationalNumbers.
  */
int rncTotalCount(RationalNumberCollection *c);

/**
  * Returns the sum of all RationalNumbers of the given RationalNumberCollection.
  * @param c A pointer to the RationalNumberCollection.
  * @return The sum of all RationalNumbers as RationalNumber.
  */
RationalNumber rncSum(RationalNumberCollection *c);

/**
  * Returns the arithmetic average of all RationalNumbers of the given RationalNumberCollection.
  * @param c A pointer to the RationalNumberCollection.
  * @return The arithmetic average of all RationalNumbers as RationalNumber.
  */
RationalNumber rncAverage(RationalNumberCollection *c);

/**
  * Returns the median of the given RationalNumberCollection.
  * @param c A pointer to the RationalNumberCollection.
  * @return The median of the RationalNumberCollection as RationalNumber.
  */
RationalNumber rncMedian(RationalNumberCollection *c);

/**
  * Returns the counter value of a RationalNumber of the given RationalNumberCollection.
  * @param c A pointer to the RationalNumberCollection.
  * @param rn The RationalNumber.
  * @return The counter value of the RationalNumber.
  */
int rncCount(RationalNumberCollection *c, RationalNumber rn);

/**
  * Adds a RationalNumber to the given RationalNumberCollection.
  * If the RationalNumber already exists in the RationalNumberCollection, the counter value of the
  * RationalNumber will be increased by 1.
  * @param c A pointer to the RationalNumberCollection.
  * @param rn The RationalNumber.
  */
void rncAdd(RationalNumberCollection *c, RationalNumber rn);

/**
  * Removes a RationalNumber of the given RationalNumberCollection.
  * If the counter value of the RationalNumber in the RationalNumberCollection is greater than 1,
  * the counter value will be decreased by 1.
  * @param c A pointer to the RationalNumberCollection.
  * @param rn The RationalNumber.
  */
void rncRemove(RationalNumberCollection *c, RationalNumber rn);

#endif // RATIONALNUMBERCOLLECTION_H
