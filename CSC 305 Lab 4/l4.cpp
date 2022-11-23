#include<iostream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;
//Turnaround time is the amount of time it takes to complete a process


/*
•	Burst time(bt): The amount of time a process will need to execute for(when executed multiple times)

•	Execution time(et): The amount of time the process will need to complete all given tasks

•	Arrival time(at): The first point in time the system knows about the process

•	Start time(st): the time at which the process starts executing

•	Completion time(ct):the time at which the process finishes executing, = st + et (non-pre-emptive only)

•	Turnaround time(tat):the total time the process is waiting to finish its execution, = ct - at

•	Avg turnaround time(att): = tat/(number of jobs), or  Average(tat)

•	Priority: A value which represents the precedence of the process, usually numeric. (depending on the specific system can be ascending or descending).
o	Example: the numbers 1 through 4, in descending order, meaning the value 1 has higher precedence than 2 , 2 is higher than 3 , 4 is the lowest. 

The output of each algorithm should include:
•	Starting Time for each job/process
•	Completion time for each job/process,
•	Turnaround time for each job/process,
•	Average Turnaround time.
•	Order of execution of the processes.


*/
struct process{
    int id; // id
    int priority; // priority rank
    int turnTime;//Turnaroundtime
    int startTime; //  what time does it start
    int comTime;// completion time
    int exTi; // time it takes also just execution time
    int arrival; // arrival time 

};

bool comparisonArrival(int arriA, int arriB)
{
    return (arriA > arriB);
}

void getCompletion(vector<process> proVec, int vecPart)
{
    int completion = 0;
    completion = proVec[vecPart].startTime + proVec[vecPart].exTi;

    proVec[vecPart].comTime = completion;

}

void turnAround(vector<process> proVec, int vecPart)
{
    int turnAround = 0;
    turnAround = proVec[vecPart].comTime - proVec[vecPart].arrival;
    proVec[vecPart].turnTime = turnAround;
}

int avgTurnTime(vector<process> proVec,  int vecLen)
{
    int avgTT = 0;
    int ttSum = 0;

    for (int i = 0; i < vecLen; i++)
    {
        ttSum += proVec[i].turnTime;
    }

    avgTT = ttSum/vecLen;
    return avgTT;
}







void fCfS(vector<process> proVec, int vecLen) // finds process that arrives go first so set . Shortest arrival has to go first
{   
    int startTime;
    int proOrder[vecLen]; // this will hold ID's order
    int sortarr[vecLen]; // sorted array eventually
    // needs to get the id in order of the lower arrival number
    //sort(sortarr,sortarr+vecLen); //sorted version of array
    
    

    

   

    



}
void priority(vector<process> proVec,int vecLen) // finds the order of the processess shorts priority goes first
{
    vector<int> proOrder;

    for (int i = 0; i < vecLen; i++)
    {

    }
}
void shortJobn(vector<process> proVec, int vecLen) // finds the order of the processess shortest one first
{
    vector<int> proOrder;

}


int main()
{
    int proNum, proEx,proPri,proArri;

    cout << "Enter Number of Processess ";
    cin >> proNum;

    vector<process> proVec;
    process proTemp;   

    cout << "Enter " << proNum << " process(ess)" << endl<< "execution time" << "\t\tprocess priority" << "\tprocess arrival" <<  endl; //  gets process time in order of arrival

    for (int i = 0; i < proNum; i++) // get the process times
    {
        cin >> proEx >> proPri >> proArri;
        proTemp.id = i + 1;
        proTemp.exTi = proEx;       
        proTemp.priority = proPri;
        proTemp.arrival = proArri;         
        proVec.push_back(proTemp);
        
    }

    fCfS(proVec,proNum);
    

    //cout << proVec[0].id << " " <<proVec[0].exTi << proVec[0].arrival << endl;
    


    
    return 0;
}


/*cout << "Enter " << proNum << " process priority: " << endl; // gets the priority

    for (int i = 0; i < proNum; i++)
    {
        cin >> proPri;
        
        proVec.push_back(proTemp);
    }

    cout << "Enter " << proNum << " process arrival: " << endl; // gets the priority

    for (int i = 0; i < proNum; i++)
    {
        cin >> proArri;
        
        proVec.push_back(proTemp);
    }
    */

    /*for (int i = 0; i < proNum; i++)
    {
        
    } 
    */