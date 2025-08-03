#include <iostream>
#include <vector>
#include "../include/task.hpp"

using namespace std;

int main() {
    vector<Task> tasks;
    loadTasks(tasks, "tasks.txt");

    int choice;

    do {
        cout << "\n============================\n";
        cout << "      TASK MANAGER MENU\n";
        cout << "============================\n";
        cout << "1. Add Task\n";
        cout << "2. List Tasks\n";
        cout << "3. Edit Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Mark Task as Done\n";
        cout << "6. View Overdue Tasks\n";
        cout << "7. Save and Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: listTasks(tasks); break;
            case 3: editTask(tasks); break;
            case 4: deleteTask(tasks); break;
            case 5: markTaskDone(tasks); break;
            case 6: viewOverdueTasks(tasks); break;
            case 7:
                saveTasks(tasks, "tasks.txt");
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid option.\n";
        }

    } while(choice != 7);

    system("pause");
    return 0;
}


