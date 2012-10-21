#include "rationalnumber.h"
#include "rationalnumbercollection.h"
#include "utils.h"
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

/*
 *
 * module internal
 *
 *
 * */

struct RationalNumberCollection {
    RationalNumberWithCount rnwcar[RNC_MAX];
    int totalCount;
    RationalNumber sum;
    RationalNumber average;
    RationalNumber median;
    int length;
};

/* internal calculating */

int rncCalculateTotalCount(RationalNumberCollection *c){
    int count = 0;
    for(int i = 0;i<c->length;i++){
        count += c->rnwcar[i].count;
    }
    return count;
}

RationalNumber rncCalculateSum(RationalNumberCollection *c){
    RationalNumber sum = {0, 1};
    for(int i = 0;i<c->length;i++){
    	for(int j = 0;j<c->rnwcar[i].count;j++){
    		sum = rnAdd(sum, c->rnwcar[i].n);
    	}
    }
    return sum;
}

RationalNumber rncCalculateAverage(RationalNumberCollection *c){
    RationalNumber num = rncSum(c),
            denum = {rncTotalCount(c), 1},
            average = rnDivide(num, denum);
    return average;
}

RationalNumber rncCalculateMedian(RationalNumberCollection *c){
    RationalNumber median,
            num,
            denum = {2, 1};
    if(c->length == 1){
        return c->rnwcar[0].n;
    }
    if(c->length%2 == 0){
        num = rnAdd(c->rnwcar[(c->length/2)-1].n, c->rnwcar[c->length/2].n);
        median = rnDivide(num, denum);
    } else {
        median = c->rnwcar[(c->length/2)+1].n;
    }
    return median;
}
void rncUpdateCollection(RationalNumberCollection *c){
	c->sum = rncCalculateSum(c);
    c->totalCount = rncCalculateTotalCount(c);
    c->average = rncCalculateAverage(c);
    c->median = rncCalculateMedian(c);
}
/*  binary search
 *  source: http://en.wikipedia.org/wiki/Binary_search_algorithm
 */
int midpoint(int imin, int imax){
	return imin + ((imax - imin) / 2);
}
int binarySearch(RationalNumberWithCount A[], RationalNumber key, int imin, int imax){
	// continually narrow search until just one element remains
	int imid;
	while (imin < imax)
	{
		imid = midpoint(imin, imax);
		// code must guarantee the interval is reduced at each iteration
		assert(imid < imax);
		// note: 0 <= imin < imax implies imid will always be less than imax

		// reduce the search
		if(rnLessThan(A[imid].n, key)){
			imin = imid + 1;
		} else {
			imax = imid;
		}
	}
	// At exit of while:
	//   if A[] is empty, then imax < imin
	//   otherwise imax == imin

	// deferred test for equality
	if ((imax == imin) && (rnEqual(A[imin].n, key)))
		return imin;
	else
		return -1;
}

/*
 *
 * module external
 *
 *
 * */

void rncInit(RationalNumberCollection* c){
    RationalNumber rn = {0, 0};
    RationalNumberWithCount defaultValue = {rn, 0};
    c->length = 0;
    c->average = rn;
    c->median = rn;
    c->sum = rn;
    c->totalCount = 0;
    // set fields of array values to default value
    for(int i;i<RNC_MAX;i++){
        c->rnwcar[i] = defaultValue;
    }
}
int rncAdd(RationalNumberCollection *c, RationalNumber n){
    if(n.denum == 0){
        return 0;
    }
    n = rnNormalize(n);
    for(int i = 0;i<c->length;i++){
        // if value is allready in array
        if(rnEqual(n, c->rnwcar[i].n)){
            c->rnwcar[i].count++;
            rncUpdateCollection(c);
            return i;
        }
        // shift right if new value is less than current [i]
        if(rnLessThan(n, c->rnwcar[i].n)){
            for(int j = c->length;j>i;j--){
                c->rnwcar[j] = c->rnwcar[j-1];
            }
            c->rnwcar[i].n = n;
            c->rnwcar[i].count = 1;
            c->length++;
            rncUpdateCollection(c);
            return i;
        }
    }
    // new value that is biggest
    c->rnwcar[c->length].n = n;
    c->rnwcar[c->length].count = 1;
    c->length++;
    rncUpdateCollection(c);
    return c->length;
}
int rncRemove(RationalNumberCollection *c, RationalNumber n){
    RationalNumber rn = {0, 0};
    RationalNumberWithCount defaultValue = {rn, 0};
    int index = binarySearch(c->rnwcar, n, 0, c->length);
    if(index == -1){
        return index;
    } else {
        c->rnwcar[index].count--;
        // shift array left if count is 0 and rn is deleted from array
        if(c->rnwcar[index].count == 0){
            for(int i = index;i<c->length;i++){
                c->rnwcar[index] = c->rnwcar[index+1];
            }
            c->rnwcar[c->length] = defaultValue;
            c->length--;
            rncUpdateCollection(c);
            return 0;
        } else {
        	rncUpdateCollection(c);
            return c->rnwcar[index].count;
        }
    }
}
int rncCount(RationalNumberCollection *c, RationalNumber n){
    RationalNumberWithCount rnwc;
    int index = binarySearch(c->rnwcar, n, 0, c->length);
    if(index == -1){
        return 0;
    } else {
        rnwc = c->rnwcar[index];
        return rnwc.count;
    }
}

int rncTotalUniqueCount(RationalNumberCollection *c){
    return c->length;
}

int rncTotalCount(RationalNumberCollection *c){
	return c->totalCount;
}

RationalNumber rncSum(RationalNumberCollection *c){
	return c->sum;
}

RationalNumber rncAverage(RationalNumberCollection *c){
	return c->average;
}

RationalNumber rncMedian(RationalNumberCollection *c){
	return c->median;
}
void showRnwcStatus(RationalNumberCollection *c){
    int i = 0;
    cout << endl;
    cout << "====================================" << endl;
    cout << "Rational number collection contents:" << endl;
    cout << "------------------------------------" << endl;
    while(c->rnwcar[i].count != 0){
        cout << "#" << i << ": " << c->rnwcar[i].n.num << "/" << c->rnwcar[i].n.denum << " (count: " << c->rnwcar[i].count << ")" << endl;
        i++;
    }
    cout << endl;
    cout << "Rational number collection data:" << endl;
    cout << "------------------------------------" << endl;
    cout << "Total unique count: " << c->length << endl;
    cout << "Total count.......: " << c->totalCount << endl;
    cout << "Sum...............: " << c->sum.num << "/" << c->sum.denum << endl;
    cout << "Average...........: " << c->average.num << "/" << c->average.denum << endl;
    cout << "Median............: " << c->median.num << "/" << c->median.denum << endl;
    cout << "====================================" << endl;
}
