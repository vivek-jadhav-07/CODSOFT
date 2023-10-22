#include <iostream>
#include <vector>

struct Task {
    std::string description;
    bool completed;
};

void addTask(std::vector<Task> &tasks, const std::string &description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
    std::cout << "Task added successfully." << std::endl;
}

void viewTasks(const std::vector<Task> &tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks in the list." << std::endl;
        return;
    }

    std::cout << "Tasks:" << std::endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". ";
        std::cout << (tasks[i].completed ? "[Completed] " : "[Pending] ");
        std::cout << tasks[i].description << std::endl;
    }
}

void markTaskAsCompleted(std::vector<Task> &tasks, size_t index) {
    if (index < tasks.size()) {
        tasks[index].completed = true;
        std::cout << "Task marked as completed." << std::endl;
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

void removeTask(std::vector<Task> &tasks, size_t index) {
    if (index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        std::cout << "Task removed successfully." << std::endl;
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;
    int choice;

    while (true) {
        std::cout << "\nTO-DO LIST MANAGER" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Exit" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 5) {
            break;
        }

        switch (choice) {
            case 1: {
                std::string description;
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                addTask(tasks, description);
                break;
            }
            case 2: {
                viewTasks(tasks);
                break;
            }
            case 3: {
                size_t index;
                std::cout << "Enter the task number to mark as completed: ";
                std::cin >> index;
                markTaskAsCompleted(tasks, index - 1);
                break;
            }
            case 4: {
                size_t index;
                std::cout << "Enter the task number to remove: ";
                std::cin >> index;
                removeTask(tasks, index - 1);
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
