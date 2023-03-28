#include "link.h"
#include <iostream>
#include <SDL2/SDL.h>

void MyAudioCallback(void* userdata, Uint8* stream, int streamLength);
int player(char* filename);
void repeat(LinkedList& list, int round = 2);
void reverse(LinkedList& list);
void shuffle(LinkedList& list);
void createNew(LinkedList& list);
