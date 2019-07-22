-- FileWatcher --

Description:

FileWatcher is a C++ wrapper for OS file monitoring systems. Currently
it uses Win32 ReadDirectoryChangesW for monitoring changes in Windows,
and inotify in linux. OSX is supported via kqueue and directory scans.


TODO:

 * Create a pure directory scan based fallback mode.
 * Optimize the kqueue implementation.
 * Thorough UnitTest
 * Add proper Unicode support.


Compiling:

Build scripts for Visual Studio 2005, Visual Studio 2008, and GNU Make
can be found within the build directory, or can be regenerated using
premake 4.0.


SimpleDemo:

To run the demo, create a directory relative to the execution directory
called "test". Start SimpleDemo, then create/change/delete files inside
"test". If "test" does not exist when SimpleDemo starts, it will throw
an exception and exit.


OgreDemo:

Check the OgreDemo directory for an example integration with Ogre.