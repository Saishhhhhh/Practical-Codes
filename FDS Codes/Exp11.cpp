/*
Aim: To illustrate the concept of queue.

Problem Statement: Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. 
If the operating system does not use priorities, then the jobs are processed in the order they enter the system. 
Write C++ program for simulating job queue. Write functions to add job and delete job from queue.
*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Job {
    int id;
    string description;

    Job(int id, const string& desc) : id(id), description(desc) {}
};

class JobQueue {
private:
    queue<Job> q;

public:
    void addJob(int id, const string& description) {
        Job newJob(id, description);
        q.push(newJob);
        cout << "Job added: [ID: " << id << ", Description: " << description << "]\n";
    }

    void deleteJob() {
        if (q.empty()) {
            cout << "No jobs to delete. The queue is empty.\n";
        } else {
            Job job = q.front();
            cout << "Job deleted: [ID: " << job.id << ", Description: " << job.description << "]\n";
            q.pop();
        }
    }

    void displayJobs() const {
        if (q.empty()) {
            cout << "The queue is empty.\n";
            return;
        }

        queue<Job> temp = q;
        cout << "Jobs in the queue:\n";
        while (!temp.empty()) {
            Job job = temp.front();
            cout << "[ID: " << job.id << ", Description: " << job.description << "]\n";
            temp.pop();
        }
    }
};

int main() {
    JobQueue jobQueue;
    int choice, id;
    string description;

    do {
        cout << "\n1. Add Job\n2. Delete Job\n3. Display Jobs\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Job ID: ";
                cin >> id;
                cin.ignore();  // Ignore trailing newline
                cout << "Enter Job Description: ";
                getline(cin, description);
                jobQueue.addJob(id, description);
                break;

            case 2:
                jobQueue.deleteJob();
                break;

            case 3:
                jobQueue.displayJobs();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

/*
    INPUT   

Enter an expression: (a + b) * {c + [d * e]}


*/
