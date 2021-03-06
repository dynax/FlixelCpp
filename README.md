C++ game framework based on Flixel library (by [Adam Atomic](http://flixel.org/index.html)). Framework is still not finished and may contain many bugs. Keep in mind that it's not 1:1 port of Flixel. My library has some differences in API and rendering system. The biggest advantage of my framework is that the backend part is tottaly separated from the Flixel API. We could write our own window managment/input/rendering/sounding classes by simply overriding FlxBackendBase class. Default built-in PC backend is SFML system. This makes my framework portable through all popular devices with no API changes.

**What is currently ported?**
- State managment based on FlxState class
- Creating new types of entities based on overriding FlxBasic and FlxObject classes.
- Grouping entities by FlxGroup class.
- Displaying sprites and animations by FlxSprite class
- Text rendering via FlxText
- Basic collisions
- Playing sounds and music (may contain bugs)
- Tilemaps
- Saves
- Particles system (a little bit different than original)
- Buttons
- Basic HTTP request using FlxHttpRequest class.
- Built-in tweener (cpptweener by Wesley Ferreira Marques)
- Shaders (low performance on mobile platforms)
- Unicode support
- On-screen virtual keyboard (for mobile devices)
- Pathfinding (astar by Justin Heyes-Jones)
- Easy to integrate scripting engine (AngelScript)

**What isn't ported yet**
- Camera managment and special effects (currently only screen flash effect is done) 

**What isn't ported and probably will never be**
- Replays
- Physics
- QuadTrees


**Porting notes**

Android:
- FlxSave class requires WRITE_EXTERNAL_STORAGE permission
- FlxHttpRequest class requires INTERNET and ACCESS_NETWORK_STATE permissions
- Mobile graphic cards are really slow so be careful using FlxEmitter.

iPhone:
- Framework is untested under iPhone. SDL_Mobile_Backend probably works with Apple-specific devices but I can't check it.
Also XCode project file is not provided with framework.


**Compilation macros**
+ FLX_NO_PATHFINDING - compile framework without AStar pathfinding module.
+ FLX_NO_SCRIPT - compile framework without AngelScript scripting engine.


**Tested compilers**
- MinGW GCC 4.6
- Microsoft Visual Studio 2010
- GNU GCC ARM 4.6 (Android NDK toolchain)

(NOTE: FlixelCpp requires basic C++0x support. MSVC 2005/2008, MinGW < 4.6 and NDK < r8 aren't supported).

**Documentation**
- Partial documentation is available [HERE](http://dynax.boo.pl/flixelcpp/)
