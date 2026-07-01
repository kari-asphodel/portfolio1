#include "App.h"
#include <iostream>
#include <string>

App::App()
{
	isRunning = true;
}

void App::Run()
{
	std::cout << "Welcome to the Crypt Keeper Productivity Program.\n";
	std::cout << "Let us organize the choas before it organizes us.\n";
	while (isRunning)
	{
		DisplayMenu();
		std::string input;
		std::getline(std::cin, input);
		int choice = std::stoi(input);

		HandleChoice(choice);
	}
}

void App::DisplayMenu() const
{
	std::cout << "\n==== CRYPT KEEPER ====\n";
	std::cout << "1. Add Task\n";
	std::cout << "2. View Tasks\n";
	std::cout << "3. Quit\n";
	std::cout << "Choose an option between 1 and 3: ";
}

void App::HandleChoice(int choice)
{
	std::string title = "";

	switch (choice)
	{
	case 1:
		std::cout << "\nEnter the task title: ";
		std::getline(std::cin, title);
		manager.AddTask(title);
		break;
	case 2:
		manager.ViewTasks();
		break;
	case 3:
		isRunning = false;
		break;
	default:
		std::cout << "\nThat option does not exist in this crypt.\n";
		break;
	}
}