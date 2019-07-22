#include <FileWatcher/FileWatcher.h>
#include <FileWatcher/FileWatcherImpl.h>

#if FILEWATCHER_PLATFORM == FILEWATCHER_PLATFORM_WIN32
#	include <FileWatcher/FileWatcherWin32.h>
#	define FILEWATCHER_IMPL FileWatcherWin32
#elif FILEWATCHER_PLATFORM == FILEWATCHER_PLATFORM_KQUEUE
#	include <FileWatcher/FileWatcherOSX.h>
#	define FILEWATCHER_IMPL FileWatcherOSX
#elif FILEWATCHER_PLATFORM == FILEWATCHER_PLATFORM_LINUX
#	include <FileWatcher/FileWatcherLinux.h>
#	define FILEWATCHER_IMPL FileWatcherLinux
#endif

namespace FW
{

	//--------
	FileWatcher::FileWatcher()
	{
		mImpl = new FILEWATCHER_IMPL();
	}

	//--------
	FileWatcher::~FileWatcher()
	{
		delete mImpl;
		mImpl = 0;
	}

	//--------
	WatchID FileWatcher::addWatch(const String& directory, FileWatchListener* watcher)
	{
		return mImpl->addWatch(directory, watcher, false);
	}

	//--------
	WatchID FileWatcher::addWatch(const String& directory, FileWatchListener* watcher, bool recursive)
	{
		return mImpl->addWatch(directory, watcher, recursive);
	}

	//--------
	void FileWatcher::removeWatch(const String& directory)
	{
		mImpl->removeWatch(directory);
	}

	//--------
	void FileWatcher::removeWatch(WatchID watchid)
	{
		mImpl->removeWatch(watchid);
	}

	//--------
	void FileWatcher::update()
	{
		mImpl->update();
	}

};//namespace FW
