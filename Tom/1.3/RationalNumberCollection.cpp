#include "RationalNumber.h"
#include "RationalNumberCollection.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

struct rnc {
    RationalNumber** a;
    int size,
        totalUniqueCount,
        totalCount;
    RationalNumber sum,
                   average,
                   median;
};

RationalNumber** getArray(RationalNumberCollection c) {
    return c->a;
}

int rncSize(RationalNumberCollection c) {
    return c->size;
}

int getTotalUniqueCount(RationalNumberCollection c) {
    return c->totalUniqueCount;
}

int getTotalCount(RationalNumberCollection c) {
    return c->totalCount;
}

RationalNumber getSum(RationalNumberCollection c) {
    return c->sum;
}

RationalNumber getAverage(RationalNumberCollection c) {
    return c->average;
}

RationalNumber getMedian(RationalNumberCollection c) {
    return c->median;
}

void rncInit(RationalNumberCollection c, int size) {

    // Allen Arrayelementen eine RationalNumber mit Zähler- und Nennerwerten von 0 eintragen,
    // mit Ausnahme des Zähler-Denominators. Diese bekommen eine 1 spendiert, die für
    // Rechenoperationen nötig ist.
    RationalNumber rn00 = { 0, 0 };
    RationalNumber rn01 = { 0, 1 };
    for (int i=0; i<size; i++) {
        c->a[i][0] = rn00;
        c->a[i][1] = rn01;
    }

    // Setze size auf size
    c->size = size;

    // Setze totalUniqueCount auf 0
    c->totalUniqueCount = 0;

    // Setze totalCount auf 0
    c->totalCount = 0;

    // Setze sum auf 0/1
    c->sum = rn01;

    // Setze average auf 0/1
    c->average = rn01;

    // Setze median auf 0/1
    c->median = rn01;

}

RationalNumberCollection rncCreate(int n) {

    // Speicher für Collection auf dem Heap reservieren
    RationalNumberCollection c = (rnc*) malloc(sizeof *c);

    // Speicher für Array auf dem Heap reservieren
    c->a = (RationalNumber**) malloc(n * sizeof(RationalNumber *));
    for (int i=0; i<n; i++) {
        c->a[i] = (RationalNumber*) malloc(2 * sizeof(RationalNumber));
    }

    // Collection initialisieren und zurückliefern
    rncInit(c, n);
    return c;

}

void rncDeleteArray(RationalNumberCollection c) {

    // Speicher des Arrays auf dem Heap freigeben
    RationalNumber **a = getArray(*(&c));
    for(int i=0; i<rncSize(*(&c)); i++) {
            free(a[i]);
    }
    free(a);

}

void rncDelete(RationalNumberCollection* c) {

    // Speicher des Arrays auf dem Heap freigeben
    rncDeleteArray(**(&c));

    // Speicher der Collection auf dem Heap freigeben
    free(**(&c));

}

void rncPrint(RationalNumberCollection c) {
    for (int i=0; i<rncTotalUniqueCount(c); i++) {
        printf("Index %i   : [%i,%i] (%i)\n", i, c->a[i][0].numerator, c->a[i][0].denominator, c->a[i][1].numerator);
    }
}

void rncScaleUp(RationalNumberCollection c) {

    // Neue Größe des Arrays berechnen
    int newSize = rncSize(c)+(rncSize(c)/10);

    // Speicher auf dem Heap reservieren
    RationalNumber** a = (RationalNumber**) malloc(newSize * sizeof(RationalNumber *));
    for (int i=0; i<newSize; i++) {
        a[i] = (RationalNumber*) malloc(2 * sizeof(RationalNumber));
    }

    // Array mit Standardwerten füllen
    RationalNumber rn00 = { 0, 0 };
    RationalNumber rn01 = { 0, 1 };
    for (int i=0; i<newSize; i++) {
        a[i][0] = rn00;
        a[i][1] = rn01;
    }

    // Arraywerte übertragen
    for(int i=0; i<getTotalUniqueCount(c); i++) {
        a[i][0] = c->a[i][0];
        a[i][1] = c->a[i][1];
    }

    // Speicher des alten Arrays auf dem Heap freigeben
    rncDeleteArray(c);

    // Zeiger auf neues Array umbiegen und neue Länge der Collection setzen
    c->a = a;
    c->size = newSize;

}

int rncSearch(RationalNumberCollection c, RationalNumber rn, int min, int max) {

    // Wenn Collection leer
    if (max < min) {
        return -1;
    }

    // Mitte der Collection ermitteln
    int mid = (min + max) / 2;

    // Wenn rn in der unteren Teil-Collection
    if (rnLessThan(rn,c->a[mid][0])) {
        return rncSearch(c, rn, min, mid-1);
    }
    // Wenn rn in der oberen Teil-Collection
    else if (rnLessThan(c->a[mid][0],rn)) {
        return rncSearch(c, rn, mid+1, max);
    }
    // rn wurde gefunden
    else {
        return mid;
    }
}

int rncTotalUniqueCount(RationalNumberCollection c) {
    return getTotalUniqueCount(c);
}

int rncTotalCount(RationalNumberCollection c) {
    return getTotalCount(c);
}

RationalNumber rncSum(RationalNumberCollection c) {
    return getSum(c);
}

void rncCalcAverage(RationalNumberCollection c) {

    // Alle Brüche in der Collection zählen und sie summieren
    int i = 0;
    RationalNumber count =  { 0, 1 };
    RationalNumber result = { 0, 1 };
    while(i < getTotalUniqueCount(c)) {
        result = rnAdd(result, rnMultiply(c->a[i][0], c->a[i][1]));
        count.numerator += c->a[i][1].numerator;
        i++;
    }

    // Wenn keine Brüche gespeichert
    if (count.numerator == 0) {
        count.numerator = 1;
    }

    // Gekürzte RationalNumber zurückgeben
    c->average = rnShorten(rnDivide(result, count));

}

RationalNumber rncAverage(RationalNumberCollection c) {
    return getAverage(c);
}

void rncCalcMedian(RationalNumberCollection c) {

    // TotalUniqueCount der Collection bestimmen
    int tuc = getTotalUniqueCount(c);

    // Wenn Collection leer
    if (tuc == 0) {
        RationalNumber result = { 0, 1 };
        c->median = result;
    }

    // Wenn TotalUniqueCount der Collection == 1
    if (tuc == 1) {
        c->median = c->a[0][0];
    }

    // Wenn TotalUniqueCount der Collection == 2
    else if (tuc == 2) {
        RationalNumber r = { 2, 1 };
        c->median = rnShorten(rnDivide(rnAdd(c->a[0][0], c->a[1][0]), r));
    }

    // Wenn TotalUniqueCount der Collection gerade
    else if (tuc%2 == 0) {
        RationalNumber r = { 2, 1 };
        int lowerMedian = (tuc / 2) - 1;
        int upperMedian = tuc / 2;
        c->median = rnShorten(rnDivide(rnAdd(c->a[lowerMedian][0], c->a[upperMedian][0]), r));
    }
    // Wenn TotalUniqueCount der Collection ungerade
    else {
        c->median = c->a[tuc / 2][0];
    }

}

RationalNumber rncMedian(RationalNumberCollection c) {
    return getMedian(c);
}

int rncCount(RationalNumberCollection c, RationalNumber rn) {

    // Wenn rn ungültig -> return 0
    if (!rnIsValid(rn)) {
        return 0;
    }

    // Wenn Collection leer ist -> return 0
    if (rncSize(c) == 0) {
        return 0;
    }

    // rn kürzen
    rn = rnShorten(rn);

    // Falls Bruch bereits vorhanden, ermittel Vorkommen des Bruchs
    int i = rncSearch(c, rn, 0, getTotalUniqueCount(c)-1);
    if (i >= 0) {
        return c->a[i][1].numerator;
    }

    return 0;

}

void rncSort(RationalNumberCollection c, int len) {

    // Temporäre Collection erstellen
    RationalNumberCollection temp = rncCreate(len);

    // Variablen zum Speichern von Indexpositionen
    int tempIndex = 0;
    int minIndex = 0;

    // Solange sich Brüche in der Collection c befinden
    while (minIndex != -1) {

        minIndex = -1;

        // Suche kleinsten Bruch aus der Collection c
        int minCount;
        for (int i=0; i<len; i++) {
            if (c->a[i][1].numerator == 0) {
                continue;
            }
            if (minIndex == -1 || rnLessThan(c->a[i][0],c->a[minIndex][0])) {
                minIndex = i;
                minCount = c->a[i][1].numerator;
            }
        }

        // Wenn kleinsten Bruch gefunden
        if (minIndex != -1) {

            // Übertrage den gefunden kleinsten Bruch und dessen Vorkommen in die Collection temp
            temp->a[tempIndex][0] = c->a[minIndex][0];
            temp->a[tempIndex][1].numerator = minCount;

            // Erhöhe den totalUniqueCount der Collection temp
            temp->totalUniqueCount++;

            // Entferne den gefunden kleinsten Bruch und dessen Vorkommen aus der Collection c
            c->a[minIndex][0].numerator = 0;
            c->a[minIndex][0].denominator = 0;
            c->a[minIndex][1].numerator = 0;

            // Zeige auf den nächsten Index der Collection temp
            tempIndex++;

        }

    }

    // Übertrage alle Brüche und ihre Vorkommen der Collection temp in die Collection c
    int tempLen = getTotalUniqueCount(temp);
    for (int j=0; j<tempLen; j++) {
        c->a[j][0] = temp->a[j][0];
        c->a[j][1].numerator = temp->a[j][1].numerator;
    }

    // Temporäre Collection temp aus dem Speicher entfernen
    rncDelete(&temp);

}

void rncAdd(RationalNumberCollection c, RationalNumber rn) {

    // Wenn rn ungültig -> return
    if (!rnIsValid(rn)) {
        return;
    }

    // TotalUniqueCount der Collection ermitteln
    int tuc = getTotalUniqueCount(c);

    // rn kürzen
    rn = rnShorten(rn);

    // Falls Bruch bereits vorhanden
    int i = rncSearch(c, rn, 0, tuc-1);
    if (i >= 0) {
        // Erhöhe Counter des Bruchs
        c->a[i][1].numerator++;
        // Erhöhe totalCount der Collection
        c->totalCount++;
        // Erhöhe sum der Collection
        c->sum = rnShorten(rnAdd(c->sum,rn));
        // Berechne average der Collection
        rncCalcAverage(c);
        return;
    }

    // Falls die Collection voll belegt ist
    if (tuc == rncSize(c)) {
        rncScaleUp(c);
    }

    // Trage den Bruch ein und erhöhe den Counter des Bruchs
    c->a[tuc][0] = rn;
    c->a[tuc][1].numerator++;
    // Erhöhe totalUniqueCount der Collection
    c->totalUniqueCount++;
    // Erhöhe totalCount der Collection
    c->totalCount++;
    // Erhöhe sum der Collection
    c->sum = rnShorten(rnAdd(c->sum,rn));
    // Berechne average der Collection
    rncCalcAverage(c);

    // Collection sortieren wenn Länge der Collection > 0
    if (tuc > 0) {
        rncSort(c, tuc+1);
    }

    // Berechne median der Collection
    rncCalcMedian(c);

}

void rncRemove(RationalNumberCollection c, RationalNumber rn) {

    // Wenn rn ungültig -> return
    if (!rnIsValid(rn)) {
        return;
    }

    // TotalUniqueCount der Collection ermitteln
    int tuc = getTotalUniqueCount(c);

    // Wenn Collection leer -> return
    if (tuc == 0) {
        return;
    }

    // rn kürzen
    rn = rnShorten(rn);

    // Falls Bruch bereits vorhanden
    int i = rncSearch(*(&c), rn, 0, tuc-1);
    if (i >= 0) {
        // Veringere Counter des Bruchs
        c->a[i][1].numerator--;
        // Veringere totalCount der Collection
        c->totalCount--;
        // Verringere sum der Collection
        c->sum = rnShorten(rnSubtract(c->sum,rn));
        // Wenn Counter anschließend == 0, entferne Bruch aus Collection
        if (c->a[i][1].numerator == 0) {
            c->a[i][0].numerator = 0;
            c->a[i][0].denominator = 0;
            // Verringere totalUniqueCount der Collection
            c->totalUniqueCount--;
            // Collection sortieren wenn Bruch nicht letzter Bruch in der Collection war
            if (tuc > 1) {
               rncSort(c, tuc);
            }
            // Berechne median der Collection
            rncCalcMedian(c);
        }
        // Berechne average der Collection
        rncCalcAverage(c);
    }

}
