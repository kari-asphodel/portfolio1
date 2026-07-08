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
	std::cout << "Today, the crypt learns to survive user choas.\n";
	while (isRunning)
	{
		DisplayMenu();

		int choice = GetValidatedInputInRange(1, 6);

		HandleChoice(choice);
	}
	std::cout << "\nGoodbye. May your task list stay only midly cursed.\n";
}

void App::DisplayMenu() const
{
	std::cout << "\n==== CRYPT KEEPER ====\n";
	std::cout << "1. Add Task\n";
	std::cout << "2. View Active Tasks\n";
	std::cout << "3. Complete Task\n";
	std::cout << "4. View Completed Tasks\n";
	std::cout << "5. View Progress Summary\n";
	std::cout << "6. Quit\n";
	std::cout << "Choose an option between 1 and 6: ";
}
int App::GetValidatedInputInRange(int min, int max)
{
	std::string input;
	int number;

	while (true)
	{
		std::getline(std::cin, input);

		try
		{
			number = std::stoi(input);
			if (number >= min && number <= max)
			{
				return number;
			}
			std::cout << "Invalid option. Please enter a number between " << min << " and " << max << ": ";
		}
		catch (...)
		{
			std::cout << "Invalid option. Please enter a number between " << min << " and " << max << ": ";
		}
	}
}


void App::HandleChoice(int choice)
{
	std::string title = "";
	int taskNumber;

	switch (choice)
	{
	case 1:
		std::cout << "\nEnter the task title: ";
		std::getline(std::cin, title);
		manager.AddTask(title);
		break;
	case 2:
		manager.ViewActiveTasks();
		break;
	case 3:
		if (manager.GetActiveTaskCount() == 0)
		{
			std::cout << "\nThere are no active tasks to complete.\n";
			return;
		}
		manager.ViewActiveTasks();
		std::cout << "\nEnter the task number to complete: ";
		taskNumber = GetValidatedInputInRange(1, manager.GetActiveTaskCount());
		manager.CompleteTask(taskNumber - 1);

		break;
	case 4:
		manager.ViewCompletedTasks();
		break;
	case 5:
		manager.DisplaySummary();
		break;
	case 6:
		isRunning = false;
		break;
	default:
		std::cout << "\nThat option does not exist in this crypt.\n";
		break;
	}
}