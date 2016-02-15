// In diesem Programm wird von der Main und einem neu gestartetem Thread
// eine Zahl und 1 erhöht und getestet ob ein Fehler durch die 
// fehlende Threadsynchronisation entsteht
// Das Skript testhel.sh startet das Programm wiederholt bis der Fehler auftritt

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int var = 0;
void* child_fn ( void* arg ) {
    var++;  return NULL;  
}

int main ( void ) {
    pthread_t child;
    pthread_create(&child, NULL, child_fn, NULL);
    var++;  pthread_join(child, NULL);
    if(var == 1)
        return 1;
    else
        return 0; 
}
