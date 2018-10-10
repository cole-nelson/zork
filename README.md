# ZORK : ECE 30862 Project 1

## Structure
- Zork class. This will have a string:GameObject* <unordered_map> to keep track of every object in the game. This makes construction of objects very simple -- only need to read the XML string and create an object and associate it with its name. This also helps with object persistence, i.e. objects "deleted" from the game can be brought back. Also, the unordered map will make it easy to prevent memory leaks since all allocated objects will be in one place. Zork class will also have functions to setup the game (read XML file, etc.) and play the game, to keep those separate. 
- GameObject class that every object in the game will inherit from. This way we can use standard containers to keep track of all objects regardless of their actual type. 
-Using RapidXML parser -- pretty simple to use, shouldn't be a problem. I've found out how to iterate through it already, so it's just a matter of doing some tests.
- Makefile: I made a Makefile for this. Hopefully that works for you guys, if you're using Eclipse you can just set it up as a "Makefile Project". I'll work on this a little more later, but the structure will look like this:
```
--Zork
  -src
    -*.cpp files
  -inc
    -*.h files
    -RapidXML files
  -obj
    -*.o files
  -zork executable
```
Right now I have 2 targets, regular "make", and a "make clean"
