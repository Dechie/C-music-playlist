#include "link.h"
#include <iostream>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <unistd.h>
#include <vector>

using namespace std;

struct AudioData
{
  Uint8* pos;
  Uint32 length;
};

void MyAudioCallback(void* usersong, Uint8* stream, int streamLength)
{
  AudioData* audio = (AudioData*)usersong;

  if(audio->length == 0)
  {
    return;
  }

  Uint32 length = (Uint32)streamLength;
  length = (length > audio->length ? audio->length : length);

  SDL_memcpy(stream, audio->pos, length);

  audio->pos += length;
  audio->length -= length;


}

int player(char * filename)
{

  SDL_Init(SDL_INIT_AUDIO);

  Uint8* wavStart;
  Uint32 wavLength;

  SDL_AudioSpec wavSpec;


  if(SDL_LoadWAV(filename, &wavSpec, &wavStart, &wavLength) == NULL)
  {
    // TODO: Proper error handling

		std::cerr << "Error: " << filename 
			<< " could not be loaded as an audio file" << std::endl;

		return 1;
  } 

  AudioData audio;
  audio.pos = wavStart;
  audio.length = wavLength;

  wavSpec.callback = MyAudioCallback;
  wavSpec.userdata = &audio;

  SDL_AudioDeviceID device = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL,
			SDL_AUDIO_ALLOW_ANY_CHANGE);

  if(device == 0)
	{
		// TODO: Proper error handling
		std::cerr << "Error: " << SDL_GetError() << std::endl;

  SDL_AudioDeviceID device = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL,
			SDL_AUDIO_ALLOW_ANY_CHANGE);
	}
  
	SDL_PauseAudioDevice(device, 0);

	while(audio.length > 0)
	{
		SDL_Delay(100);
	}

	SDL_CloseAudioDevice(device);
	SDL_FreeWAV(wavStart);


	SDL_Quit();
	return 0;
}

void repeat(LinkedList &list, int rounds = 2)
{
  
  int n = list.len;
  struct node * temp = new node;
  temp = list.head;

  char* name = new char;
  char * song = new char;
  char * artist = new char;


  for (int i = 0; i < n * rounds; ++i)
  {
    
    name = &(temp->song[0]);

    strcpy(song, name);
    strcpy(artist, temp->artist);

    system("clear");

    cout << "\t";
    for (int j = 0; j < 40; ++j)
      cout << '*';
    cout << endl;
    
    cout << "\t\t" << name << " -- " << artist << endl << endl;
    cout << "\t <<Previous" << "\t" << "Next>>" << endl;

    cout << "\t";

    for (int j = 0; j < 40; ++j)
      cout << '*';
    cout << endl;

    strcat(name, ".wav");
    player(name);
    
    name = strtok(name, ".");
    cout << "song ended. playing next music." << endl << endl;

    temp = temp->next;

    sleep(1);
  }
}

void reverse(LinkedList &list)
{

  Stack copy;
  LinkedList reversed;

  int n = list.len;

  node* temp = new node;
  temp = list.head;

  for (int i = 0; i < n; i++)
  {
    copy.push(temp);
    temp = temp->next;
  }

  for (int i = 0; i < n; ++i)
  {
    temp = copy.pop();
     
    reversed.add_end(temp->song, temp->artist);

  }

  repeat(reversed, 1);

}
