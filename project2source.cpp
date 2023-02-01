//
// Created by Jfr on 13/12/2022.
//

#include "project2.h"
ofstream writeFile;
fstream numbers;

CPStudentPlan::CPStudentPlan() :
    treeSize(0), prioTrack(0), arr(100), numberTracker(0), numArr(0), tree(100) {}

bool CPStudentPlan::isEmpty() const {
    return arr.size() == 0;
}

bool CPStudentPlan::treeIsEmpty() const {
    return tree.size() == 0;
}

void CPStudentPlan::insertElem(const int &id, string &ln, string &fn, string &add, string &bd) {
    auto *newElem = new ElemNode;
    int index = id % max;

    newElem->idNum = id;
    newElem->lastName = ln;
    newElem->firstName = fn;
    newElem->addr = add;
    newElem->bDate = bd;
    newElem->priority = ++prioTrack;

    arr[index] = *newElem;
}

ElemNode CPStudentPlan::buildTree(int id) {

    ElemNode tempElem;

    if (!isEmpty()) {
        int in = id % max;
        tempElem = arr[in];
    } else {
        cout << "No applicant yet!" << endl;
        return tempElem;
    }

    if(treeSize != 0) {
        tree[0] = tempElem;
        int hole = ++treeSize;

        for( ; tempElem.priority < tree[hole / 2].priority; hole /= 2 ) {
            tree[hole] = tree[hole / 2];
        }
        tree[hole] = tempElem;

        return tempElem;
    } else {
        tree[1] = tempElem;
        treeSize++;
        return tempElem;
    }
}

ElemNode CPStudentPlan::removePrio() {
    if(treeSize != 0) {
        ElemNode elemToRemove, tempElem;
        int hole = 1;
        elemToRemove = tree[1];
        tree[1] = tree[treeSize--];

        /// percolate down
        int child;
        tempElem = tree[hole];
        for(; hole * 2 <= treeSize; hole = child) {
            child = hole * 2;
            if(child != treeSize && tree[child + 1].priority < tree[child].priority)
                child++;
            if(tree[child].priority < tempElem.priority)
                tree[hole] = tree[child];
            else
                break;
        }
        tree[hole] = tempElem;

        return elemToRemove;
    } else {
        cout << "nothing to be removed!" << endl;
        exit(0);
    }

}

void CPStudentPlan::apply(const int & id, string & ln, string & fn, string & add, string & bd) {
    insertElem(id, ln, fn, add, bd);
    writeFile.open(OUTPUT_DATA, ios::app);
    if(writeFile.is_open()) {
        writeFile <<"applicant " + to_string(id) + ": " + fn + " " + ln << endl;
        writeFile.close();
    }
}

void CPStudentPlan::lineup(int &id) {
    int prioNumber = buildTree(id).priority;
    writeFile.open(OUTPUT_DATA, ios::app);
    if(writeFile.is_open()) {
        writeFile << "lineup " + to_string(id) + ": " + to_string(prioNumber) << endl;
        writeFile.close();
    }
}

void CPStudentPlan::serve() {
    if (numberTracker == 0) {
        string lines;
        numbers.open(NUMBER_FILE, ios::in | ios::out);
        if (numbers.is_open()) {
            while (getline(numbers, lines)) {
                numArr.push_back(lines);
            }
            numbers.close();
        }
    }

    ElemNode removed;
    string assignNum = numArr[numberTracker++];
    removed = removePrio();

    writeFile.open(OUTPUT_DATA, ios::app);
    if(writeFile.is_open()) {
        writeFile << "Assign mobile # " + assignNum + "," + " to applicant " + to_string(removed.idNum) + ":" + removed.firstName + " " + removed.lastName + " of " + removed.addr + ", born " + removed.bDate + "." << endl;
    }
    writeFile.close();
}


