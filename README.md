# C-music-playlist
A music playlist application in c++. Using circular linked list as a data structure. 


The project Uses it's own implementation of Linked List data structure. It stores file-names of the music files in a circular linked list. the property of circular linked list means that, when we iterate through the list and reach the end of the list, it will automatically bring us back to the beginning.

This property can be utilized to create music playlists, as the program simply needs to store the objects on the list and just iterate through it.

The project makes use of the external library SDL (which is not included in this project), to play the audio files.
It supports up to 3 distinct playlists, since it allocates 3 linked lists (which are objects of the LinkedList class created in the custom implementation file (Link.h).
