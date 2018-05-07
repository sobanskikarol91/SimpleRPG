#include "Kostka.h"

Kostka::Kostka(int min, int max) : min(min), max(max) {};
int Kostka::losuj() { return (rand() % max - min) + min; }