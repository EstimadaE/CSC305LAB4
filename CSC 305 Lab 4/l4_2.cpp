// C++ program for implementation of FCFS
// scheduling
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

/*
•	Burst time(bt): The amount of time a process will need to execute for(when executed multiple times)

•	Execution time(et): The amount of time the process will need to complete all given tasks

•	Arrival time(at): The first point in time the system knows about the process

•	Start time(st): the time at which the process starts executing, st + ex

•	Completion time(ct):the time at which the process finishes executing, = st + et (non-pre-emptive only)

•	Turnaround time(tat):the total time the process is waiting to finish its execution, //= ct - at = tat

•	Avg turnaround time(att): = tat/(number of jobs), or  Average(tat)

•	Priority: A value which represents the precedence of the process, usually numeric. (depending on the specific system can be ascending or descending).
o	Example: the numbers 1 through 4, in descending order, meaning the value 1 has higher precedence than 2 , 2 is higher than 3 , 4 is the lowest. 

The output of each algorithm should include:
•	Starting Time for each job/process V
•	Completion time for each job/process, V
•	Turnaround time for each job/process, ???
•	Average Turnaround time. V
•	Order of execution of the processes. V


1.First Come – First Serve  : non-preemptive
2.Priority : -pre-emptive
3.Shortest Job Next – non-preemptive


*/


struct process
{
	int pid; // process ID
	int exT; // CPU Burst time required
	int priority; // Priority of this process
    int arrival;
};

// Function to sort the process acc. to priority
bool comparison(process a, process b) //priority
{
	return (b.priority > a.priority);
}

bool comparisonFCFS(process a, process b) // arrival
{
	return (b.pid > a.pid);
}
bool comparisonSFS(process a, process b)//
{
	return (b.exT > a.exT);
}

// Function to find the waiting time for all
// processes
void findWaitingTime(vector<process> proc, int n,	int wt[])
{
	// waiting time for first process is 0
	wt[0] = 0;

	// calculating waiting time
	for (int i = 1; i < n ; i++ )
		wt[i] = proc[i-1].exT + wt[i-1] ;
}

void findStartingTIme(vector<process> proc, int n, int st[]) // start time
{
    
    int temp = proc[0].arrival;
    st[0]=proc[0].arrival; // the start of the first process is the first arrival time
    for (int i = 1; i < n; i++)
    {
       temp += proc[i-1].exT; // first arrival time plus exec time
	   st[i]=temp;
    }
}


// Function to calculate turn around time
void findTurnAroundTime( vector<process> proc, int n,	int comp[], int tat[]) //= ct - at = tat
{
	// calculating turnaround time by adding
	// exT[i] + wt[i]
	for (int i = 0; i < n ; i++)
	{
		//tat[i] = proc[i].exT + wt[i];
		tat[i] = comp[i] - proc[i].arrival;
		

	}
		
}
void compTime(vector<process> proc, int n, int comp[],int st[])  // st + et (non-pre-emptive only)

{
    for (int i = 0;i < n; i++)
	{
		comp[i] = st[i] + proc[i].exT;	
	}
}

//Function to calculate average time
void findavgTime(vector<process> proc, int n) // non preemptive
{
	int wt[n], tat[n], st[n],comp[n],total_wt = 0, total_tat = 0;

	//Function to find waiting time of all processes
	findWaitingTime(proc, n, wt);
    findStartingTIme(proc, n, st);
	compTime(proc, n, comp, st);

	//Function to find turn around time for all processes
	findTurnAroundTime(proc, n, comp, tat);
    



	//Display processes along with all details
	cout << "\nProcesses "<< " Execution time "	<< " Start Time " << " Completion Time" << " Turnaround time\n";

	// Calculate total waiting time and total turn
	// around time
	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << proc[i].pid << "\t\t"
			<< proc[i].exT << "\t\t " << st[i]
			<< "\t\t " << comp[i] << "\t" << tat[i] <<endl;
	}

	//cout << "\nAverage waiting time = "	<< (float)total_wt / (float)n;
	cout << "\nAverage turn around time = " << (float)total_tat / (float)n << endl;
}

void priorityScheduling(vector<process> proc, int n)
{
	// Sort processes by priority
	sort(proc.begin(), proc.end(), comparison);

	cout<< "Order in which processes gets executed \n";
	for (int i = 0 ; i < n; i++)
		cout << proc[i].pid <<" " ;

	findavgTime(proc, n);
}

void SJF(vector<process> proc, int n)
{
	sort(proc.begin(), proc.end(), comparisonSFS);

	cout<< "Order in which processes gets executed \n";
	for (int i = 0 ; i < n; i++)
		cout << proc[i].pid <<" " ;

	findavgTime(proc, n);	

}

void FCFS(vector<process> proc, int n )
{
	sort(proc.begin(), proc.end(), comparisonFCFS);

	cout<< "Order in which processes gets executed \n";
	for (int i = 0 ; i < n; i++)
		cout << proc[i].pid <<" " ;

	findavgTime(proc, n);	

}

// Driver code
int main()
{
     int proNum, proEx,proPri,proArri;

    cout << "Enter Number of Processess ";
    cin >> proNum;

    vector<process> proVec;
    process proTemp;   

    cout << "Enter " << proNum << " process(ess)" << endl<< "process arrival" << "\t\tprocess priority" << "\texecution time" <<  endl; //  gets process time in order of arrival

    for (int i = 0; i < proNum; i++) // get the process times
    {
        cin >> proArri >> proPri >> proEx;
        proTemp.exT=proEx;
        proTemp.priority = proPri;
        proTemp.arrival = proArri;
        proTemp.pid = i +1;             
        proVec.push_back(proTemp);
        
    }
	cout <<" First Come First Serve" << endl;
	FCFS(proVec,proNum);
	cout << endl << endl;

	cout << " Priority Scheduling" << endl;
	
    priorityScheduling(proVec,proNum);
	cout << endl << endl;

	cout << " Shortest Job First" << endl;
	SJF(proVec,proNum);
	
	return 0;
}
