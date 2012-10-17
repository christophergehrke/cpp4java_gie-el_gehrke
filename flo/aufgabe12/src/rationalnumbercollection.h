#include "rationalnumber.h"
#include <string>
using namespace std;

#ifndef RATIONALNUMBERCOLLECTION_H
#define RATIONALNUMBERCOLLECTION_H

/**
  * Default size if the array in the RationalNumberCollection.
  */
static const int RNC_MAX = 1000;

/**
  * A struct that holds a RationalNumber and an int value of her count.
  */
struct RationalNumberWithCount {
    RationalNumber n;
    int count;
};

/**
  * RationalNumberCollection struct that contains a RationalNumberWithCount array that
  * hold all structs of RationalNumber with an int value of their count.
  * The values of totalCount, sum, average, median and length are changed on add and
  * remove.
  */
struct RationalNumberCollection {
    RationalNumberWithCount rnwcar[RNC_MAX];
    int totalCount;
    RationalNumber sum;
    RationalNumber average;
    RationalNumber median;
    int length;
};
/**
  * Show current status of a RationalNumberCollection.
  * @param c - a pointer to the RationalNumberCollection.
  */
void showRnwcStatus(RationalNumberCollection *c);

/**
  * Initialize a RationalNumberCollection, set all values to their default.
  * @param c - a pointer to the RationalNumberCollection.
  */
void rncInit(RationalNumberCollection *c);

/**
  * Add a RationalNumber to a RationalNumbercollection.
  * @param c - a pointer to the RationalNumberCollection.
  * @param n - a RationalNumber to be added to c.
  * @return - returns the index of the position where the RationalNumber was added.
  */
int rncAdd(RationalNumberCollection *c, RationalNumber n);

/**
  * Gives the count of a specific RationalNumber in the RationalNumberCollection.
  * @param c - a pointer to the RationalNumberCollection.
  * @param n - a RationalNumber to be counted.
  * @return - returns the count of the RationalNumber.
  */
int rncCount(RationalNumberCollection *c, RationalNumber n);

/**
  * Removes a specific RationalNumber from the RationalNumberCollection.
  * @param c - a pointer to the RationalNumberCollection.
  * @param n - a RationalNumber to be removed.
  * @return - returns the current count of the RationalNumber or -1 if it couldn't be found in the collection.
  */
int rncRemove(RationalNumberCollection *c, RationalNumber n);

/**
  * Returns the totalUniqueCount value of the collection.
  * @param c - a pointer to the RationalNumberCollection.
  * @return - int value of the length of the collection array.
  */
int rncTotalUniqueCount(RationalNumberCollection *c);

/**
  * Returns the totalCount value of the collection.
  * @param c - a pointer to the RationalNumberCollection.
  * @return - int value of the total count.
  */
int rncTotalCount(RationalNumberCollection *c);

/**
  * Returns the current sum of the RationalNumber values in the collection.
  * @param c - a pointer to the RationalNumberCollection.
  * @return - int value of the sum.
  */
RationalNumber rncSum(RationalNumberCollection *c);

/**
  * Returns the current average of the RationalNumber values in the collection.
  * @param c - a pointer to the RationalNumberCollection.
  * @return - int value of the average.
  */
RationalNumber rncAverage(RationalNumberCollection *c);

/**
  * Removes a specific RationalNumber from the RationalNumberCollection.
  * @param c - a pointer to the RationalNumberCollection.
  * @return - int value of the median.
  */
RationalNumber rncMedian(RationalNumberCollection *c);

#endif // RATIONALNUMBERCOLLECTION_H
