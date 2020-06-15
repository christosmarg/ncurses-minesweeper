#ifndef AUDIO_H
#define AUDIO_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#define AUDIO_PATH "res/detective-8bit.wav"
#define VOL_STEP 10

void *audio_play(void *tid);
void  volume(char option);
void  audio_pause(void);

#endif /* AUDIO_H */
