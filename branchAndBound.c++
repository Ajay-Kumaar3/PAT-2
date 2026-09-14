#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job
{
  string name;
  int profit;
  int deadline;
};

vector<Job> jobs;
vector<bool> slot;

int n;
int bestProfit = 0;
vector<string> bestJobs;
vector<string> currentJobs;

int bound(int index, int profit)
{
  for (int i = index; i < n; i++)
    profit += jobs[i].profit;

  return profit;
}

void branchAndBound(int index, int profit)
{
  // All jobs considered
  if (index == n)
  {
    if (profit > bestProfit)
    {
      bestProfit = profit;
      bestJobs = currentJobs;
    }
    return;
  }

  // Prune if even the best possible result is not better
  if (bound(index, profit) <= bestProfit)
    return;

  // Try including the job
  int d = jobs[index].deadline;

  for (int t = d; t >= 1; t--)
  {
    if (!slot[t])
    {
      slot[t] = true;
      currentJobs.push_back(jobs[index].name);

      branchAndBound(index + 1,
                     profit + jobs[index].profit);

      currentJobs.pop_back();
      slot[t] = false;

      break;
    }
  }

  // Try excluding the job
  branchAndBound(index + 1, profit);
}

int main()
{
  jobs = {
      {"J1", 100, 2},
      {"J2", 80, 1},
      {"J3", 60, 2},
      {"J4", 40, 3}};

  n = jobs.size();

  // Highest profit first
  sort(jobs.begin(), jobs.end(),
       [](Job a, Job b)
       {
         return a.profit > b.profit;
       });

  slot.resize(4, false);

  branchAndBound(0, 0);

  cout << "Maximum Profit = " << bestProfit << endl;

  cout << "Selected Jobs = ";
  for (string job : bestJobs)
    cout << job << " ";

  cout << endl;

  return 0;
}

// Algorithm :
// Sort jobs by decreasing profit.
// Start with no jobs selected.
// For each job, create two branches:
// Include job
// Exclude job
// If included, place it in the latest available slot before its deadline.
// Calculate an optimistic bound.
// If bound ≤ current best profit, prune the branch.
// Continue until all jobs are considered.
// The highest profit is the answer.


// BranchAndBound(index, profit)

//     if index == number of jobs
//         update best profit
//         return

//     bound = calculateBound(index, profit)

//     if bound <= bestProfit
//         return

//     if a free slot exists before deadline

//         put job in slot

//         BranchAndBound(index + 1,
//                        profit + job.profit)

//         remove job from slot

//     // Exclude job
//     BranchAndBound(index + 1, profit)

// O(2ⁿ × n) worst case