#include <iostream>
#include <stdio.h>
#include "rationalnumber.h"

struct RationalNumber rnNaN = { 1, 0 };

int ggT(int,int);
int max(int,int);
int min(int,int);

bool rnIsValid(RationalNumber n){
    return(n.denominator);
}

bool rnIsNotNull(RationalNumber n){
    return(!n.denominator );
}

bool rnLessThan(RationalNumber n1, RationalNumber n2){
    printf("rnLessThan \n");
    if(!rnIsValid(n1) && !rnIsValid(n2))return false;
    if(rnIsNotNull(n1) || rnIsNotNull(n2)) return false;
    if(rnEqual(n1,n2)) return false;

    int ggT1 = ggT(max(n1.nominator,n1.denominator),min(n1.nominator,n1.denominator));
    int ggT2 = ggT(max(n2.nominator,n2.denominator),min(n2.nominator,n2.denominator));

    RationalNumber rnLess1 = { n1.nominator / ggT1 , n1.denominator / ggT1 };
    RationalNumber rnLess2 = { n2.nominator / ggT2 , n2.denominator / ggT2 };

    if( rnLess1.denominator > 1 && rnLess1.nominator <= rnLess2.nominator && rnLess1.denominator >= rnLess2.denominator ) {
        return true;
    }else if(rnLess1.denominator < 1 && rnLess1.denominator < rnLess2.denominator){
        return true;
    }else{
        return false;
    }
}

bool rnEqual(RationalNumber n1, RationalNumber n2){

    printf("rnEqual \n");
    if(rnIsNotNull(n1) || rnIsNotNull(n2)) return false;
    if(!rnIsValid(n1) && !rnIsValid(n2))return false;

    int ggT1 = ggT(max(n1.nominator,n1.denominator),min(n1.nominator,n1.denominator));
    int ggT2 = ggT(max(n2.nominator,n2.denominator),min(n2.nominator,n2.denominator));

    RationalNumber rnEqual1 = { n1.nominator / ggT1 , n1.denominator / ggT1 };
    RationalNumber rnEqual2 = { n2.nominator / ggT2 , n2.denominator / ggT2 };

    if(rnEqual1.nominator == rnEqual2.nominator && rnEqual1.denominator == rnEqual2.denominator){
        return true;
    }
    return false;
}

RationalNumber rnAdd(RationalNumber n1, RationalNumber n2){

    printf("rnAdd \n");
    if( (rnIsValid(n1) && rnIsValid(n2)) && !(rnIsNotNull(n1) && rnIsNotNull(n2)) ){
        RationalNumber rNew;
        int fn = n1.nominator * n2.denominator;
        int fd = n1.denominator * n2.denominator;

        int sn = n2.nominator * n1.denominator;
        int sd = fd;

        rNew.nominator = fn + sn;
        rNew.denominator = sd;

        int max_ = max(rNew.nominator,rNew.denominator);
        int min_ = min(rNew.nominator,rNew.denominator);
        int ggT_ = ggT(max_,min_);
        rNew.nominator = rNew.nominator / ggT_;
        rNew.denominator = rNew.denominator / ggT_;

        return rNew;
    }else{
        return rnNaN;
    }
}

RationalNumber rnSubtract(RationalNumber n1, RationalNumber n2){

    printf("rsSubtract \n");
    if( (rnIsValid(n1) && rnIsValid(n2)) && !(rnIsNotNull(n1) && rnIsNotNull(n2)) ){

        RationalNumber rNew;
        int fn = n1.nominator * n2.denominator;
        int fd = n1.denominator * n2.denominator;

        int sn = n2.nominator * n1.denominator;
        int sd = fd;

        rNew.nominator = fn - sn;
        rNew.denominator = sd;

        int max_ = max(rNew.nominator,rNew.denominator);
        int min_ = min(rNew.nominator,rNew.denominator);
        int ggT_ = ggT(max_,min_);
        rNew.nominator = rNew.nominator / ggT_;
        rNew.denominator = rNew.denominator / ggT_;

        return rNew;
    }else{
        return rnNaN;
    }
}

RationalNumber rnMultiply(RationalNumber n1, RationalNumber n2){

    printf("rnMultiply \n");
    if( (rnIsValid(n1) && rnIsValid(n2)) && !(rnIsNotNull(n1) && rnIsNotNull(n2)) ){
        RationalNumber rNew;
        rNew.nominator = n1.nominator * n2.nominator;
        rNew.denominator = n1.denominator * n2.denominator;
        return rNew;
    }else{
        return rnNaN;
    }
}

RationalNumber rnDivide(RationalNumber n1, RationalNumber n2){
     printf("rnDivide \n");
    if( (rnIsValid(n1) && rnIsValid(n2)) && !(rnIsNotNull(n1) && rnIsNotNull(n2)) ){
        RationalNumber rNew;
        RationalNumber swap;

        swap.nominator = n2.denominator;
        swap.denominator = n2.nominator;

        n2.nominator = swap.nominator;
        n2.denominator = swap.denominator;

        rNew.nominator = n1.nominator * n2.nominator;
        rNew.denominator = n1.denominator * n2.denominator;

        return rNew;
    }else{
        return rnNaN;
    }
}

int ggT(int i, int j){
    if( i % j == 0){
        return j;
    }else{
        return ggT(j, i%j);
    }
}

int max(int i, int j){
    if(i < j){
        return j;
    }else{
        return i;
    }
}

int min(int i, int j){
    if(i < j){
        return i;
    }else{
        return j;
    }
}

void printRN(RationalNumber rn){
    printf("%d / %d", rn.nominator , rn.denominator);
}
