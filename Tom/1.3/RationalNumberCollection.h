#ifndef RATIONALNUMBERCOLLECTION_H
#define RATIONALNUMBERCOLLECTION_H

#include "RationalNumber.h"


/**
  * Represents the RationalNumberCollection
  */
typedef struct rnc *RationalNumberCollection;

/**
  * Creates a RationalNumberCollection with a given size, allocating memory space on the heap
  * @param n The size of the RationalNumberCollection
  * @return The RationalNumberCollection
  */
RationalNumberCollection rncCreate(int n);

/**
  * Deletes the given RationalNumberCollection, deallocating its memory space on the heap
  * @param n The RationalNumberCollection
  */
void rncDelete(RationalNumberCollection* c);

/**
  * Prints the RationalNumberCollection
  * @param c The RationalNumberCollection
  */
void rncPrint(RationalNumberCollection c);

/**
  * Gets the size of the RationalNumberCollection
  * @param n The RationalNumberCollection
  * @return The size
  */
int rncSize(RationalNumberCollection c);

/**
  * Returns the amount of unique RationalNumbers of the given RationalNumberCollection.
  * @param c A pointer to the RationalNumberCollection.
  * @return The amount of unique RationalNumbers.
  */
int rncTotalUniqueCount(RationalNumberCollection c);

/**
  * Returns the total amount of RationalNumbers of the given RationalNumberCollection.
  * @param c A pointer to the RationalNumberCollection.
  * @return The total amount of RationalNumbers.
  */
int rncTotalCount(RationalNumberCollection c);

/**
  * Returns the sum of all RationalNumbers of the given RationalNumberCollection.
  * @param c A pointer to the RationalNumberCollection.
  * @return The sum of all RationalNumbers as RationalNumber.
  */
RationalNumber rncSum(RationalNumberCollection c);

/**
  * Returns the arithmetic average of all RationalNumbers of the given RationalNumberCollection.
  * @param c A pointer to the RationalNumberCollection.
  * @return The arithmetic average of all RationalNumbers as RationalNumber.
  */
RationalNumber rncAverage(RationalNumberCollection c);

/**
  * Returns the median of the given RationalNumberCollection.
  * @param c A pointer to the RationalNumberCollection.
  * @return The median of the RationalNumberCollection as RationalNumber.
  */
RationalNumber rncMedian(RationalNumberCollection c);

/**
  * Returns the counter value of a RationalNumber of the given RationalNumberCollection.
  * @param c A pointer to the RationalNumberCollection.
  * @param rn The RationalNumber.
  * @return The counter value of the RationalNumber.
  */
int rncCount(RationalNumberCollection c, RationalNumber rn);

/**
  * Adds a RationalNumber to the given RationalNumberCollection.
  * If the RationalNumber already exists in the RationalNumberCollection, the counter value of the
  * RationalNumber will be increased by 1.
  * @param c A pointer to the RationalNumberCollection.
  * @param rn The RationalNumber.
  */
void rncAdd(RationalNumberCollection c, RationalNumber rn);

/**
  * Removes a RationalNumber of the given RationalNumberCollection.
  * If the counter value of the RationalNumber in the RationalNumberCollection is greater than 1,
  * the counter value will be decreased by 1.
  * @param c A pointer to the RationalNumberCollection.
  * @param rn The RationalNumber.
  */
void rncRemove(RationalNumberCollection c, RationalNumber rn);

#endif // RATIONALNUMBERCOLLECTION_H
