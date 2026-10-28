#include "ping.h"

// Source - https://stackoverflow.com/q/68804469
// Posted by user2138149, modified by community. See post 'Timeline' for change history
// Retrieved 2026-10-28, License - CC BY-SA 4.0
double
timediff(struct timespec begin, struct timespec end) {
return ((end.tv_sec - begin.tv_sec)
    + 1.0e-9 * (end.tv_nsec - begin.tv_nsec)) ;
}

/**
 * Ajoute une valeur en secondes (double) à un struct timespec.
 * @param ts      Pointeur vers le timespec à modifier.
 * @param seconds Valeur en secondes à ajouter (peut être négative).
 */
void timespec_add_double(struct timespec *ts, double seconds) {
    if (!ts) return;

    // 1. Séparer la partie entière et la partie décimale
    double sec_part;
    double nsec_part = modf(seconds, &sec_part);

    // 2. Ajouter les secondes entières
    ts->tv_sec += (time_t)sec_part;

    // 3. Convertir la partie décimale en nanosecondes et l'ajouter
    ts->tv_nsec += (long)(nsec_part * 1e9);

    // 4. Gérer le dépassement positif (tv_nsec >= 1 000 000 000)
    if (ts->tv_nsec >= 1000000000L) {
        ts->tv_sec += 1;
        ts->tv_nsec -= 1000000000L;
    }
    // 5. Gérer le dépassement négatif si 'seconds' était négatif (tv_nsec < 0)
    else if (ts->tv_nsec < 0) {
        ts->tv_sec -= 1;
        ts->tv_nsec += 1000000000L;
    }
}

/**
 * Additionne deux structures timespec.
 * @param result Pointeur vers la structure qui stockera le résultat (res = t1 + t2).
 * @param t1     Premier timespec.
 * @param t2     Deuxième timespec.
 */
void timespec_add(struct timespec *result, const struct timespec *t1, const struct timespec *t2) {
    if (!result || !t1 || !t2) return;

    // 1. Additionner les secondes et les nanosecondes séparément
    result->tv_sec = t1->tv_sec + t2->tv_sec;
    result->tv_nsec = t1->tv_nsec + t2->tv_nsec;

    // 2. Normaliser si les nanosecondes dépassent ou égalent 1 seconde
    if (result->tv_nsec >= 1000000000L) {
        result->tv_sec += 1;
        result->tv_nsec -= 1000000000L;
    }
}


