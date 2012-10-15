#include "RationalNumber.h"
#include "RationalNumberCollection.h"


int rncSearch(RationalNumberCollection *c, RationalNumber rn, int min, int max) {

    // Zeiger auf Collection
    RationalNumber (*ptr)[2] = c->rn;

    // Wenn Collection leer
    if (max < min) {
        return -1;
    }

    // Mitte der Collection ermitteln
    int mid = (min + max) / 2;

    // Wenn rn in der unteren Teil-Collection
    if (rnLessThan(rn,ptr[mid][0])) {
        return rncSearch(*(&c), rn, min, mid-1);
    }
    // Wenn rn in der oberen Teil-Collection
    else if (rnLessThan(ptr[mid][0],rn)) {
        return rncSearch(*(&c), rn, mid+1, max);
    }
    // rn wurde gefunden
    else {
        return mid;
    }
}

void rncInit(RationalNumberCollection *c) {

    // Zeiger auf Collection
    RationalNumber (*ptr)[2] = c->rn;

    // Allen Arrayelementen eine RationalNumber mit Z�hler- und Nennerwerten von 0 eintragen,
    // mit Ausnahme des Z�hler-Denominators. Diese bekommen eine 1 spendiert, die f�r
    // Rechenoperationen n�tig ist.
    RationalNumber rn = { 0, 0 };
    RationalNumber counter = { 0, 1 };
    for (int i=0; i<MAXSIZE; i++) {
        ptr[i][0] = rn;
        ptr[i][1] = counter;
    }

    // Setze totalUniqueCount auf 0
    c->totalUniqueCount = 0;

    // Setze totalCount auf 0
    c->totalCount = 0;

    // Setze sum auf 0/1
    c->sum = counter;

    // Setze average auf 0/1
    c->average = counter;

    // Setze median auf 0/1
    c->median = counter;

}

int rncTotalUniqueCount(RationalNumberCollection *c) {

    return c->totalUniqueCount;

}

int rncTotalCount(RationalNumberCollection *c) {

    return c->totalCount;

}

RationalNumber rncSum(RationalNumberCollection *c) {

    return c->sum;

}

void rncCalcAverage(RationalNumberCollection *c) {

    // Zeiger auf Collection
    RationalNumber (*ptr)[2] = c->rn;

    // Alle Br�che in der Collection z�hlen und sie summieren
    int i = 0;
    RationalNumber count =  { 0, 1 };
    RationalNumber result = { 0, 1 };
    while(ptr[i][1].numerator > 0) {
        result = rnAdd(result, rnMultiply(ptr[i][0], ptr[i][1]));
        count.numerator += ptr[i][1].numerator;
        i++;
    }

    // Wenn keine Br�che gespeichert
    if (count.numerator == 0) {
        count.numerator = 1;
    }

    // Gek�rzte RationalNumber zur�ckgeben
    c->average = rnShorten(rnDivide(result, count));

}

RationalNumber rncAverage(RationalNumberCollection *c) {

    return c->average;

}

void rncCalcMedian(RationalNumberCollection *c) {

    // L�nge der Collection bestimmen
    int len = rncTotalUniqueCount(*(&c));

    // Wenn Collection leer
    if (len == 0) {
        RationalNumber result = { 0, 1 };
        c->median = result;
    }

    // Zeiger auf Collection
    RationalNumber (*ptr)[2] = c->rn;

    // Wenn L�nge der Collection == 1
    if (len == 1) {
        c->median = ptr[0][0];
    }

    // Wenn L�nge der Collection == 2
    if (len == 2) {
        RationalNumber r = { 2, 1 };
        c->median = rnShorten(rnDivide(rnAdd(ptr[0][0], ptr[1][0]), r));
    }

    // Wenn L�nge der Collection gerade
    if (len%2 == 0) {
        RationalNumber r = { 2, 1 };
        int lowerMedian = (len / 2) - 1;
        int upperMedian = len / 2;
        c->median = rnShorten(rnDivide(rnAdd(ptr[lowerMedian][0], ptr[upperMedian][0]), r));
    }
    // Wenn L�nge der Collection ungerade
    else {
        int median = len / 2;
        c->median = ptr[median][0];
    }

}

RationalNumber rncMedian(RationalNumberCollection *c) {

    return c->median;

}

int rncCount(RationalNumberCollection *c, RationalNumber rn) {

    // Wenn rn ung�ltig -> return 0
    if (!rnIsValid(rn)) {
        return 0;
    }

    // L�nge der Collection bestimmen
    int len = rncTotalUniqueCount(*(&c));

    // Wenn Collection leer ist -> return 0
    if (len == 0) {
        return 0;
    }

    // Zeiger auf Collection
    RationalNumber (*ptr)[2] = c->rn;

    // rn k�rzen
    rn = rnShorten(rn);

    // Falls Bruch bereits vorhanden, ermittel Vorkommen des Bruchs
    int i = rncSearch(*(&c), rn, 0, len-1);
    if (i >= 0) {
        return ptr[i][1].numerator;
    }

    return 0;

}

void rncSort(RationalNumberCollection *c, int len) {

    // Tempor�re Collection erstellen
    RationalNumberCollection temp;
    rncInit(&temp);

    // Zeiger auf Collection
    RationalNumber (*ptr)[2] = c->rn;

    // Zeiger auf tempor�re Collection
    RationalNumber (*tempptr)[2] = temp.rn;

    // Variablen zum Speichern von Indexpositionen
    int tempIndex = 0;
    int minIndex = 0;

    // Solange sich Br�che in der Collection c befinden
    while (minIndex != -1) {

        minIndex = -1;

        // Suche kleinsten Bruch aus der Collection c
        int minCount;
        for (int i=0; i<len; i++) {
            if (ptr[i][1].numerator == 0) {
                continue;
            }
            if (minIndex == -1 || rnLessThan(ptr[i][0],ptr[minIndex][0])) {
                minIndex = i;
                minCount = ptr[i][1].numerator;
            }
        }

        // Wenn kleinsten Bruch gefunden
        if (minIndex != -1) {

            // �bertrage den gefunden kleinsten Bruch und dessen Vorkommen in die Collection temp
            tempptr[tempIndex][0] = ptr[minIndex][0];
            tempptr[tempIndex][1].numerator = minCount;

            // Erh�he den totalUniqueCount der Collection temp
            temp.totalUniqueCount++;

            // Entferne den gefunden kleinsten Bruch und dessen Vorkommen aus der Collection c
            ptr[minIndex][0].numerator = 0;
            ptr[minIndex][0].denominator = 0;
            ptr[minIndex][1].numerator = 0;

            // Zeige auf den n�chsten Index der Collection temp
            tempIndex++;

        }

    }

    // �bertrage alle Br�che und ihre Vorkommen der Collection temp in die Collection c
    int tempLen = rncTotalUniqueCount(&temp);
    for (int j=0; j<tempLen; j++) {
        ptr[j][0] = tempptr[j][0];
        ptr[j][1].numerator = tempptr[j][1].numerator;
    }

}

void rncAdd(RationalNumberCollection *c, RationalNumber rn) {

    // Wenn rn ung�ltig -> return
    if (!rnIsValid(rn)) {
        return;
    }

    // L�nge der Collection ermitteln
    int len = rncTotalUniqueCount(*(&c));

    // rn k�rzen
    rn = rnShorten(rn);

    // Zeiger auf Collection
    RationalNumber (*ptr)[2] = c->rn;

    // Falls Bruch bereits vorhanden
    int i = rncSearch(*(&c), rn, 0, len-1);
    if (i >= 0) {
        // Erh�he Counter des Bruchs
        ptr[i][1].numerator++;
        // Erh�he totalCount der Collection
        c->totalCount++;
        // Erh�he sum der Collection
        c->sum = rnShorten(rnAdd(c->sum,rn));
        // Berechne average der Collection
        rncCalcAverage(*(&c));
        return;
    }

    // Falls nocht nicht alle Elemente des Arrays belegt sind
    if (len < MAXSIZE) {
        // Trage den Bruch ein und erh�he den Counter des Bruchs
        ptr[len][0] = rn;
        ptr[len][1].numerator++;
        // Erh�he totalUniqueCount der Collection
        c->totalUniqueCount++;
        // Erh�he totalCount der Collection
        c->totalCount++;
        // Erh�he sum der Collection
        c->sum = rnShorten(rnAdd(c->sum,rn));
        // Berechne average der Collection
        rncCalcAverage(*(&c));
    }

    // Collection sortieren wenn L�nge der Collection > 0
    if (len > 0) {
        rncSort(*(&c), len+1);
    }

    // Berechne median der Collection
    rncCalcMedian(*(&c));

}

void rncRemove(RationalNumberCollection *c, RationalNumber rn) {

    // Wenn rn ung�ltig -> return
    if (!rnIsValid(rn)) {
        return;
    }

    // L�nge der Collection ermitteln
    int len = rncTotalUniqueCount(*(&c));

    // Wenn Collection leer -> return
    if (len == 0) {
        return;
    }

    // rn k�rzen
    rn = rnShorten(rn);

    // Zeiger auf Collection
    RationalNumber (*ptr)[2] = c->rn;

    // Falls Bruch bereits vorhanden
    int i = rncSearch(*(&c), rn, 0, len-1);
    if (i >= 0) {
        // Veringere Counter des Bruchs
        ptr[i][1].numerator--;
        // Veringere totalCount der Collection
        c->totalCount--;
        // Verringere sum der Collection
        c->sum = rnShorten(rnSubtract(c->sum,rn));
        // Wenn Counter anschlie�end == 0, entferne Bruch aus Collection
        if (ptr[i][1].numerator == 0) {
            ptr[i][0].numerator = 0;
            ptr[i][0].denominator = 0;
            // Verringere totalUniqueCount der Collection
            c->totalUniqueCount--;
            // Collection sortieren wenn Bruch nicht letzter Bruch in der Collection war
            if (len > 1) {
               rncSort(*(&c), len);
            }
            // Berechne median der Collection
            rncCalcMedian(*(&c));
        }
        // Berechne average der Collection
        rncCalcAverage(*(&c));
    }

}
