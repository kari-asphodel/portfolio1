#include "TaskManager.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>


void TaskManager::AddTask(std::string title, std::string priority, std::string category)
{
	activeTasks.push_back(Task(title, priority, category));
	std::cout << "\nTask added to the crypt.\n";
}
void TaskManager::DisplayTaskList(const std::vector<Task>& taskList, std::string heading) const
{
	std::cout << "\n==== "<< heading << "====\n";
	if (taskList.empty())
	{
		std::cout << "No tasks found. The crypt is quiet...suspiciously quiet.\n";
		return;
	}
	for (int i = 0; i < taskList.size(); i++)
	{
		std::cout << i + 1 << ". "
			<< taskList[i].GetTitle()
			<< " | Priority: " << taskList[i].GetPriority()
			<< " | Category: " << taskList[i].GetCategory()
			<< "\n";
	}
}
void TaskManager::ViewActiveTasks() const
{
	DisplayTaskList(activeTasks, "ACTIVE TASKS");
}

void TaskManager::ViewCompletedTasks() const
{
	DisplayTaskList(completedTasks, "COMPLETED TASKS");
}
void TaskManager::ViewTasksByPriorty(std::string priority) const
{
	std::vector<Task> filteredTasks;
	for (int i = 0; i < activeTasks.size(); i++)
	{
		if (activeTasks[i].GetPriority() == priority)
		{
			filteredTasks.push_back(activeTasks[i]);
		}
	}
	DisplayTaskList(filteredTasks, priority + " PRIORITY TASKS");
}

void TaskManager::CompleteTask(int index)
{
	if (index >= 0 && index < activeTasks.size())
	{
		activeTasks[index].CompleteTask();
		completedTasks.push_back(activeTasks[index]);
		activeTasks.erase(activeTasks.begin() + index);
		std::cout << "\nTask completed and moved to the completed crypt.\n";
	}
	else
	{
		std::cout << "\nInvalid task number. That task does not exist in this realm.\n";
	}
}

void TaskManager::SortActiveTasksByPriority()
{
	std::sort(activeTasks.begin(), activeTasks.end(), [](const Task& first, const Task& second)
		{
			return first.GetPriorityScore() > second.GetPriorityScore();
		});
	std::cout << "\nActive Tasks sorted by priority. The loudest demons rise first.\n";
}

void TaskManager::DisplaySummary()const
{
	std::cout << "\n==== CRYPT SUMMARY====\n";
	std::cout << "Active Tasks: " << activeTasks.size() << "\n";
	std::cout << "Completed Tasks: " << completedTasks.size() << "\n";
	std::cout << "Total Tasks Created: " <<
		activeTasks.size() + completedTasks.size() << "\n";
}

int TaskManager::GetActiveTaskCount() const
{
	return activeTasks.size();
}

void TaskManager::SaveToTextFile(std::string fileName) const
{
	std::ofstream file(fileName);
	if (!file.is_open())
	{
		std::cout << "\nUnable to open text file for saving.\n";
		return;
	}
	for (int i = 0; i < activeTasks.size(); i++)
	{
		file << activeTasks[i].ToTextLine() << "\n";
	}
	for (int i = 0; i < completedTasks.size(); i++)
	{
		file << completedTasks[i].ToTextLine() << "\n";
	}
	file.close();
	std::cout << "\nTasks saved to the text file successfully.\n";
}

void TaskManager::LoadFromTextFile(std::string fileName)
{
	std::ifstream file(fileName);
	if (!file.is_open())
	{
		std::cout << "\nNo text save file found.\n";
		return;
	}
	activeTasks.clear();
	completedTasks.clear();

	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream stream(line);

		std::string title;
		std::string priority;
		std::string category;
		std::string completedText;

		std::getline(stream, title, '|');
		std::getline(stream, priority, '|');
		std::getline(stream, category, '|');
		std::getline(stream, completedText, '|');

		bool isCompleted = completedText == "1";

		Task loadedTask(title, priority, category, isCompleted);

		if (isCompleted)
		{
			completedTasks.push_back(loadedTask);
		}
		else
		{
			activeTasks.push_back(loadedTask);
		}
	}
	file.close();
	std::cout << "\nTasks loaded from text file successfully.\n";
}

void TaskManager::WriteStringBinary(std::ofstream& file, const std::string& text) const
{
	int length = static_cast<int>(text.size());

	file.write(reinterpret_cast<char*>(&length), sizeof(length));
	file.write(text.c_str(), length);
}

void TaskManager::ReadStringBinary(std::ifstream& file) const
{
	int length = 0;

	file.read(reinterpret_cast<char*>(&length), sizeof(length));

	std::string text(length, ' ');
	file.read(&text[0], length);

	return text;
}

void TaskManager::SaveToBinaryFile(std::string fileName) const
{
	std::ofstream file(fileName, std::ios::binary);
	if (!file.is_open())
	{
		std::cout << "\nUnable to open binary file for saving.\n";
		return;
	}
	int activeCount = static_cast<int>(activeTasks.size());
	int completedCount = static_cast<int>(completedTasks.size());

	file.write(reinterpret_cast<char*>(&activeCount), sizeof(activecount));
	for (int i = 0; i < activeTasks.size(); i++)
	{
		WriteStringBinary(file, activeTasks[i].GetTitle());
		WriteStringBinary(file, activeTasks[i].GetPriority());
		WriteStringBinary(file, activeTasks[i].GetCategory());
	}

	file.write(reinterpret_cast<char*>(&completedCount), sizeof(completedCount));
	for (int i = 0; i < completedTasks.size(); i++)
	{
		WriteStringBinary(file, completedTasks[i].GetTitle());
		WriteStringBinary(file, completedTasks[i].GetPriority());
		WriteStringBinary(file, completedTasks[i].GetCategory());
	}
	file.close();
	std::cout < "\nTasks saved to the binary file successfully.\n";
}

void TaskManager::LoadFromBinaryFile(std::string fileName)
{
	std::ifstream file(fileName, std::ios::binary);
	if (!file.is_open())
	{
		std::cout << "\nNo binary save file found.\n";
		return;
	}
	activeTasks.clear();
	completedTasks.clear();

	int activeCount = 0;
	int completedCount = 0;

	file.read(reinterpret_cast<char*>(&activeCount), sizeof(activeCount));

	for (int i = 0; i < activeCount; i++)
	{
		std::string title = ReadStringBinary(file);
		std::string priority = ReadStringBinary(file);
		std::string category = ReadStringBinary(file);
		activeTasks.push_back(Task(title, priority, category, false));
	}

	file.read(reinterpret_cast<char*>(&completedCount), sizeof(completedCount));

	for (int i = 0; i < completedCount; i++)
	{
		std::string title = ReadStringBinary(file);
		std::string priority = ReadStringBinary(file);
		std::string category = ReadStringBinary(file);
		completedTasks.push_back(Task(title, priority, category, true));
	}
	file.close();
	std::cout << "\nTasks loaded from binary file successfully.\n";
}