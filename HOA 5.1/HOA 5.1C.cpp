#include <iostream>
using namespace std;

class Job{
private:
	int id;
	string name;
	int pages;
public:
	Job(int newid, const string newname, int newpages)
		: id(newid), name(newname), pages(newpages), next(NULL) {}
		
	int getId() const { return id; }
    string getName() const { return name; }
    int getPages() const { return pages; }

    void printJob() const {
        cout << "ID: " << id << ", User: " << name << ", Pages: " << pages << endl;
    }

    Job *next;
};

class Printer{
private:
	void simulatePrinting(int pages) {
        cout << "Printing " << pages << " pages..." << endl;
    }

    Job *head;
    Job *tail;
public:
	Printer() : head(NULL), tail(NULL) {}

    ~Printer() {
        while (head) {
            Job* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addJob(const Job& job) {
        Job* newJob = new Job(job);
        if (!head) {
            head = newJob;
            tail = newJob;
        } else {
            tail->next = newJob;
            tail = newJob;
        }
        cout << "Added ";
        newJob->printJob();
    }

    void processJobs() {
        while (head) {
            Job* job = head;
            head = head->next;
            cout << "Processing ";
            job->printJob();
            simulatePrinting(job->getPages());
            delete job;
        }
        tail = NULL;
    }
};

int main(){
	Printer printer;

    printer.addJob(Job(1, "Steph", 5));
    printer.addJob(Job(2, "James", 3));
    printer.addJob(Job(3, "Victor", 10));
    printer.addJob(Job(4, "Bilal", 2));

    printer.processJobs();

	return 0;
}
