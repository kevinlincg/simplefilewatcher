#ifndef _FW_FILEWATCHERWIN32_H_
#define _FW_FILEWATCHERWIN32_H_
#pragma once

#include "FileWatcherImpl.h"

#if FILEWATCHER_PLATFORM == FILEWATCHER_PLATFORM_WIN32

#include <map>

namespace FW
{
	/// Implementation for Win32 based on ReadDirectoryChangesW.
	/// @class FileWatcherWin32
	class FileWatcherWin32 : public FileWatcherImpl
	{
	public:
		/// type for a map from WatchID to WatchStruct pointer
		typedef std::map<WatchID, WatchStruct*> WatchMap;

	public:
		///
		///
		FileWatcherWin32();

		///
		///
		virtual ~FileWatcherWin32();

		/// Add a directory watch
		/// @exception FileNotFoundException Thrown when the requested directory does not exist
		WatchID addWatch(const String& directory, FileWatchListener* watcher, bool recursive);

		/// Remove a directory watch. This is a brute force lazy search O(nlogn).
		void removeWatch(const String& directory);

		/// Remove a directory watch. This is a map lookup O(logn).
		void removeWatch(WatchID watchid);

		/// Updates the watcher. Must be called often.
		void update();

		/// Handles the action
		void handleAction(WatchStruct* watch, const String& filename, unsigned long action);

	private:
		/// Map of WatchID to WatchStruct pointers
		WatchMap mWatches;
		/// The last watchid
		WatchID mLastWatchID;

	};//end FileWatcherWin32

};//namespace FW

#endif//FILEWATCHER_PLATFORM_WIN32

#endif//_FW_FILEWATCHERWIN32_H_
