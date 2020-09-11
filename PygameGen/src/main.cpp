/*
Created by Sean R. Mott || 09/09/2020

Generates a skeleton pygame application.
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool isMessage = false;

const char* imports[] = { "pygame", "random", "time" };
#define IMPORT_COUNT 3

//writes the main protion of the file that is the same no matter what.
void WriteMainBody(ofstream& writeStream);

int main(int argc, char* argv[])
{
	//if no args were passed || 1
	if (argc < 2)
	{
		ofstream writeStream("PygameApp.py");
		if (!writeStream.is_open())
		{
			printf("File Error, Type: Impossible || Impossible error found, no args passed yet unable to write file. Check Github for updates and fixes.\n");
			cin.get();
			return -1;
		}

		WriteMainBody(writeStream);
	}

	//if file path was passed || 2
	else if (argc == 2)
	{
		string path = argv[1];
		const long length = path.length();
		if (path[length - 3] != '.' || path[length - 2] != 'p' || path[length - 1] != 'y')
			path += ".py";

		ofstream writeStream(path);
		if (!writeStream.is_open())
		{
			printf("File Error, Type: Path || File path was given yet unable to write file. Check Github for updates and fixes.\n Filepath: %s\n", path.c_str());
			cin.get();
			return -1;
		}

		WriteMainBody(writeStream);
	}

	//if anything else was passed || 3 or more
	else
	{
		string path = argv[1];
		const long length = path.length();
		if (path[length - 3] != '.' || path[length - 2] != 'p' || path[length - 1] != 'y')
			path += ".py";
		
		ofstream writeStream(path);
		if (!writeStream.is_open())
		{
			printf("File Error, Type: Path || File path was given yet unable to write file. Check Github for updates and fixes.\n Filepath: %s\n", path.c_str());
			cin.get();
			return -1;
		}

		//adds student name
		if (argc > 2)
			writeStream << "#" + (string)argv[2] + "\n";

		//adds lab
		if (argc >= 3)
			writeStream << "#ETGG1801-02 " + (argv[3] == nullptr ? "Lab42" : (string)argv[3]) + "\n\n";

		WriteMainBody(writeStream);
	}

	if(isMessage)
		cin.get();
	return 0;
}

void WriteMainBody(ofstream& writeStream)
{
	//add imports
	for (unsigned char i = 0; i < IMPORT_COUNT; i++)
		writeStream << "import " + (string)imports[i] + '\n';

	writeStream << "\n#window settings\nWINDOW_WIDTH = 800\nWINDOW_HEIGHT = 600\nclearColor = (0, 128, 128)\n\n"
		"#Inits Pygame\npygame.init()\n\n#Load Assets\n\nwindow = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT)) #Creates Window\n\n#---GAME LOOP---#\nwindow.fill(clearColor) #Clear Screen\n\n#---GAME LOGIC---#\n\npygame.display.flip() #Updates Screen\ntime.sleep(3)\n\n#---CLEAN UP RESOURCES---#\npygame.quit()";
}