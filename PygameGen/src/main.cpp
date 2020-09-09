/*
Created by Sean R. Mott || 09/09/2020

Generates a skeleton pygame application.
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ofstream writeStream;

bool isMessage = false;

int main(int argc, char* argv[])
{
	//if no args were passed || 1
	if (argc < 2)
	{
		writeStream.open("PygameApp.py");
		if (!writeStream.is_open())
		{
			printf("File Error, Type: Impossible || Impossible error found, no args passed yet unable to write file. Check Github for updates and fixes.\n");
			cin.get();
			return -1;
		}

		writeStream << "import pygame\nimport time\nimport random\n\n#window settings\nWINDOW_WIDTH = 800\nWINDOW_HEIGHT = 600\nclearColor = (0, 128, 128)\n\n"
"#inits pygame\npygame.init()\nwindow = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))\n\n#game loop\nwindow.fill(clearColor) #clear screen\n\n#game logic\n\npygame.display.flip() #updates screen\ntime.sleep(3)\n\n#clear resources\npygame.quit()";
	}

	//if file path was passed || 2
	else if (argc == 2)
	{
		string path = argv[1];
		const long length = path.length();
		if (path[length - 3] != '.' || path[length - 2] != 'p' || path[length - 1] != 'y')
			path += ".py";

		writeStream.open(path);
		if (!writeStream.is_open())
		{
			printf("File Error, Type: Path || File path was given yet unable to write file. Check Github for updates and fixes.\n Filepath: %s\n", path.c_str());
			cin.get();
			return -1;
		}
		writeStream << "import pygame\nimport time\nimport random\n\n#window settings\nWINDOW_WIDTH = 800\nWINDOW_HEIGHT = 600\nclearColor = (0, 128, 128)\n\n"
			"#inits pygame\npygame.init()\nwindow = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))\n\n#game loop\nwindow.fill(clearColor) #clear screen\n\n#game logic\n\npygame.display.flip() #updates screen\ntime.sleep(3)\n\n#clear resources\npygame.quit()";
	}

	//if anything else was passed || 3 or more
	else
	{
		string path = argv[1];
		const long length = path.length();
		if (path[length - 3] != '.' || path[length - 2] != 'p' || path[length - 1] != 'y')
			path += ".py";
		
		writeStream.open(path);
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
		/*else
		{
			writeStream.write("#ETGG1801-02 Lab42\n\n", 20);
			//printf("No lab name was passed in use less arguments if you don't want it added.\n");
			//isMessage = true;
		}*/

		writeStream << "import pygame\nimport time\nimport random\n\n#window settings\nWINDOW_WIDTH = 800\nWINDOW_HEIGHT = 600\nclearColor = (0, 128, 128)\n\n"
			"#inits pygame\npygame.init()\nwindow = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))\n\n#game loop\nwindow.fill(clearColor) #clear screen\n\n#game logic\n\npygame.display.flip() #updates screen\ntime.sleep(3)\n\n#clear resources\npygame.quit()";
	}

	if(isMessage)
		cin.get();
	return 0;
}