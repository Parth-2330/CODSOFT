#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Task {
private:
    string name; 
    string description; 
    string dueDate; 
    bool completed; 

public:
    // Constructor to initialize a task
    Task(const string& name, const string& description,
         const string& dueDate)
        : name(name)
        , description(description)
        , dueDate(dueDate)
        , completed(false)
    {}
    string getName() const {return name;}

    // Getter for task description
    string getDescription() const { return description; }

    // Getter for task due date
    string getDueDate() const { return dueDate; }

    // Getter for task completion status
    bool isCompleted() const { return completed; }

    // Setter for task name
    void setName(const string& name) { this->name = name; }

    // Setter for task description
    void setDescription(const string& description)
    {
        this->description = description;
    }

    // Setter for task due date
    void setDueDate(const string& dueDate)
    {
        this->dueDate = dueDate;
    }

    // Mark the task as completed
    void markCompleted() { completed = true; }

    // Display task details
    void displayTask() const
    {
        cout << name << " ("
             << (completed ? "Completed" : "Pending")
             << ") - Due: " << dueDate << endl
             << "   Description: " << description << endl;
    }
};


class ToDolist
{
private:
    vector<Task> tasks;
public:
    void displayMenu();
    void addTask();
    void deleteTask();
    void displayTasks();
    void markTaskCompleted();

    
};



int main(){

     
     int choice;
     ToDolist todo;
        do {
            todo.displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                todo.addTask();
                break;
            case 2:
                todo.displayTasks();
                break;
            case 3:
                todo.deleteTask();
                break;
            case 4:
                todo.markTaskCompleted();
                break;
            case 5:
                cout <<"Exiting program... "<< endl;
                exit(0);
                break;
            default:
                cout << "Invalid choice. Please try again!"
                     << endl;
            }
        } while (choice != 6);
    }


void ToDolist::displayMenu(){

        cout<<endl;
        cout<<"---------- To-Do List Menu -----------"<<endl;
        cout <<"1. Add Task"<<endl;
        cout <<"2. Display Task"<<endl;
        cout <<"3. Delete/Remove Tasks"<<endl;
        cout <<"4. Mark Task as Completed"<<endl;
        cout <<"5. Exit"<<endl;
        cout << "-----------------------------------------"<<endl;
        cout<<endl;
}

void ToDolist::addTask(){
    string name, description, dueDate;
        cout << "Enter task name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter task description: ";
        getline(cin, description);
        cout << "Enter task due date (DD-MM-YYYY): ";
        getline(cin, dueDate);

        tasks.emplace_back(name, description, dueDate);
        cout << "Task added successfully!" << endl;
}


void ToDolist::deleteTask(){
     if (tasks.empty()) {
            cout << "No tasks to delete!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getName()
                 << endl;
        }
        cout << "Enter the task number to delete: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task deleted successfully!" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
    
}

void ToDolist::displayTasks(){
    if (tasks.empty()) {
            cout << "No tasks to display!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            tasks[i].displayTask();
        }
    
}

void ToDolist::markTaskCompleted(){
    if (tasks.empty()) {
            cout << "No tasks to mark as completed!"
                 << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getName()
                 << endl;
        }
        cout << "Enter the task number to mark as "
                "completed: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].markCompleted();
            cout << "Task marked as completed!" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
    
}
