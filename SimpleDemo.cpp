#include <FileWatcher/FileWatcher.h>
#include <iostream>

/// Processes a file action
class UpdateListener : public FW::FileWatchListener
{
public:
	UpdateListener() {}
	void handleFileAction(FW::WatchID watchid, const FW::String& dir, const FW::String& filename,
		FW::Action action)
	{
		std::cout << "DIR (" << dir + ") FILE (" + filename + ") has event " << action << std::endl;
	}
};


int main(int argc, char **argv)
{
	try 
	{
		// create the file watcher object
		FW::FileWatcher fileWatcher;

		// add a watch to the system
		FW::WatchID watchID = fileWatcher.addWatch("./test", new UpdateListener(), true);
		
		std::cout << "Press ^C to exit demo" << std::endl;

		// loop until a key is pressed
		while(1)
		{
			fileWatcher.update();
		}
	} 
	catch( std::exception& e ) 
	{
		fprintf(stderr, "An exception has occurred: %s\n", e.what());
	}

	return 0;
}
