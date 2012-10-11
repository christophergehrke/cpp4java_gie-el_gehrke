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

    // Allen Arrayelemente eine RationalNumber mit Zähler- und Nennerwerten von 0 eintragen
    RationalNumber rn = { 0, 0 };
    for (int i=0; i<MAXSIZE; i++) {
        ptr[i][0] = rn;
        ptr[i][1] = rn;
    }

}

int rncTotalUniqueCount(RationalNumberCollection *c) {

    // Zeiger auf Collection
    RationalNumber (*ptr)[2] = c->rn;

    // Alle verschiedene Brüche zählen
    int i = 0;
    while(ptr[i][1].numerator > 0) {
        i++;
    }
    return i;

}

int rncTotalCount(RationalNumberCollection *c) {

    // Zeiger auf Collection
    RationalNumber (*ptr)[2] = c->rn;

    // Alle Brüche zählen
    int i = 0;
    int count = 0;
    while(ptr[i][1].numerator > 0) {
        count += ptr[i][1].numerator;
        i++;
    }
    return count;

}

double rncSum(RationalNumberCollection *c) {

    // Zeiger auf Collection
    RationalNumber (*ptr)[2] = c->rn;

    // Alle Brüche in der Collection summieren
    int i = 0;
    double result = 0;
    while(ptr[i][1].numerator > 0) {
        result += (((double)ptr[i][0].numerator / ptr[i][0].denominator) * ptr[i][1].numerator);
        i++;
    }
    return result;

}

double rncAverage(RationalNumberCollection *c) {

    // Zeiger auf Collection
    RationalNumber (*ptr)[2] = c->rn;

    // Alle Brüche in der Collection zählen und sie summieren
    int i = 0;
    int count = 0;
    double result = 0;
    while(ptr[i][1].numerator > 0) {
        result += (((double)ptr[i][0].numerator / ptr[i][0].denominator)*ptr[i][1].numerator);
        count += ptr[i][1].numerator;
        i++;
    }

    // Wenn keine Brüche gespeichert
    if (count == 0) {
        return 0;
    }

    // Wenn mindestens 1 Bruch gespeichert ist
    return result/count;

}

double rncMedian(RationalNumberCollection *c) {

    // Länge der Collection bestimmen
    int len = rncTotalUniqueCount(*(&c));

    // Wenn Collection leer
    if (len == 0) {
        return 0;
    }

    // Zeiger auf Collection
    RationalNumber (*ptr)[2] = c->rn;

    // Wenn Länge der Collection == 1
    if (len == 1) {
        return ((double) ptr[0][0].numerator / ptr[0][0].denominator);
    }

    // Wenn Länge der Collection == 2
    if (len == 2) {
        return ((((double) ptr[0][0].numerator / ptr[0][0].denominator) + ((double) ptr[1][0].numerator / ptr[1][0].denominator)) / 2);
    }

    // Wenn Länge der Collection gerade
    if (len%2 == 0) {
        int lowerMedian = (len/2)-1;
        int upperMedian = len/2;
        return ((((double) ptr[lowerMedian][0].numerator / ptr[lowerMedian][0].denominator) + ((double) ptr[upperMedian][0].numerator / ptr[upperMedian][0].denominator)) / 2);
    }
    // Wenn Länger der Collection ungerade
    else {
        int median = len/2;
        return ((double) ptr[median][0].numerator / ptr[median][0].denominator);
    }

}

int rncCount(RationalNumberCollection *c, RationalNumber rn) {

    // Wenn rn ungültig -> return 0
    if (!rnIsValid(rn)) {
        return 0;
    }

    // Länge der Collection bestimmen
    int len = rncTotalUniqueCount(*(&c));

    // Wenn Collection leer ist -> return 0
    if (len == 0) {
        return 0;
    }

    // Zeiger auf Collection
    RationalNumber (*ptr)[2] = c->rn;

    // rn kürzen
    rn = rnShorten(rn);

    // Falls Bruch bereits vorhanden, ermittel Vorkommen des Bruchs
    int i = rncSearch(*(&c), rn, 0, len-1);
    if (i >= 0) {
        return ptr[i][1].numerator;
    }

    return 0;

}

void rncSort(RationalNumberCollection *c, int len) {

    // Temporäre Collection erstellen
    RationalNumberCollection temp;
    rncInit(&temp);

    // Zeiger auf Collection
    RationalNumber (*ptr)[2] = c->rn;

    // Zeiger auf temporäre Collection
    RationalNumber (*tempptr)[2] = temp.rn;

    // Variablen zum Speichern von Indexpositionen
    int tempIndex = 0;
    int minIndex = 0;

    // Solange sich Brüche in der Collection c befinden
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

            // Übertrage den gefunden kleinsten Bruch und dessen Vorkommen in die Collection temp
            tempptr[tempIndex][0] = ptr[minIndex][0];
            tempptr[tempIndex][1].numerator = minCount;

            // Entferne den gefunden kleinsten Bruch und dessen Vorkommen aus der Collection c
            ptr[minIndex][0].numerator = 0;
            ptr[minIndex][0].denominator = 0;
            ptr[minIndex][1].numerator = 0;

            // Zeige auf den nächsten Index der Collection temp
            tempIndex++;

        }

    }

    // Übertrage alle Brüche und ihre Vorkommen der Collection temp in die Collection c
    int tempLen = rncTotalUniqueCount(&temp);
    for (int j=0; j<tempLen; j++) {
        ptr[j][0] = tempptr[j][0];
        ptr[j][1].numerator = tempptr[j][1].numerator;
    }

}

void rncAdd(RationalNumberCollection *c, RationalNumber rn) {

    // Länge der Collection ermitteln
    int len = rncTotalUniqueCount(*(&c));

    // Wenn rn ungültig -> return
    if (!rnIsValid(rn)) {
        return;
    }

    // rn kürzen
    rn = rnShorten(rn);

    // Zeiger auf Collection
    RationalNumber (*ptr)[2] = c->rn;

    // Falls Bruch bereits vorhanden, erhöhe Counter des Bruchs
    int i = rncSearch(*(&c), rn, 0, len-1);
    if (i >= 0) {
        ptr[i][1].numerator++;
        return;
    }

    // Falls nocht nicht alle Elemente des Arrays belegt sind, trage Bruch ein und erhöhe den Counter des Bruchs
    if (len < MAXSIZE) {
        ptr[len][0] = rn;
        ptr[len][1].numerator++;
    }

    // Collection sortieren wenn Länge der Collection > 0
    if (len > 0) {
        rncSort(*(&c), len+1);
    }

}

void rncRemove(RationalNumberCollection *c, RationalNumber rn) {

    // Wenn rn ungültig -> return
    if (!rnIsValid(rn)) {
        return;
    }

    // Länge der Collection ermitteln
    int len = rncTotalUniqueCount(*(&c));

    // Wenn Collection leer -> return
    if (len == 0) {
        return;
    }

    // rn kürzen
    rn = rnShorten(rn);

    // Zeiger auf Collection
    RationalNumber (*ptr)[2] = c->rn;

    // Falls Bruch bereits vorhanden, veringere Counter des Bruchs
    int i = rncSearch(*(&c), rn, 0, len-1);
    if (i >= 0) {
        ptr[i][1].numerator--;
        // Wenn Counter anschließend == 0, entferne Bruch aus Collection
        if (ptr[i][1].numerator == 0) {
            ptr[i][0].numerator = 0;
            ptr[i][0].denominator = 0;
            // Collection sortieren wenn Bruch nicht letzter Bruch in der Collection war
            if (len > 1) {
               rncSort(*(&c), len);
            }
        }
        return;
    }

}
