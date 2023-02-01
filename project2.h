//
// Created by Jfr on 11/12/2022.
//

#ifndef PROJECT2_PROJECT2_H
#define PROJECT2_PROJECT2_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
//  Location of the file input that "CPinput1.txt and CPinput2.txt"
#define TEXT_INPUT "C:\\Users\\Asus\\OneDrive - fwh5t\\MSci Documents\\A.Y 2022 - 2023\\First Semester\\ICT201 (Data Structures)\\Project2\\input_output_file\\CPinput1.txt"
//  Location of the output file on where to write the output 'output_file.txt'
#define OUTPUT_DATA "C:\\Users\\Asus\\OneDrive - fwh5t\\MSci Documents\\A.Y 2022 - 2023\\First Semester\\ICT201 (Data Structures)\\Project2\\input_output_file\\output_file.txt"
//  Location of the numbers to be assigned to students
#define NUMBER_FILE "C:\\Users\\Asus\\OneDrive - fwh5t\\MSci Documents\\A.Y 2022 - 2023\\First Semester\\ICT201 (Data Structures)\\Project2\\input_output_file\\CellPhoneNumbers.txt"
#define max 100
using namespace std;


/**
 *      Element class for every application
 **/

class ElemNode {
public:
    int idNum = 0, priority = 0;
    string lastName, firstName, addr, bDate;
    ElemNode() = default;
    ElemNode(const int & prio, const int & id, string & ln, string & fn, string & ad, string & bd) :
                priority(prio) ,idNum(id), lastName(ln),
                firstName(fn), addr(ad), bDate(bd) {}
};

/**
 *    Cellphone Student Plan class
 */

class CPStudentPlan {
    public:
        CPStudentPlan();
        void insertElem(const int & id, string & ln, string & fn, string & add, string & bd);
        ElemNode removePrio();
        bool isEmpty() const;
        ElemNode buildTree(int id);
        bool treeIsEmpty() const;
        void apply(const int & id, string & ln, string & fn, string & add, string & bd);
        void lineup(int &id);
        void serve();

    private:
        vector<ElemNode> arr;           // for storing the application online.
        vector<ElemNode> tree;          //  for storing the order of binary search tree heap-order.
        vector<string> numArr;          //  vector storage for numbers.
        int prioTrack;                  //  tracking number for priority.
        int treeSize;                   //  tracking the size or node of the tree.
        int numberTracker;              //  tracker for numbers being assigned to the student.

};

#endif //PROJECT2_PROJECT2_H
