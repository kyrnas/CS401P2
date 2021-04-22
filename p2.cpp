#include <iostream>
#include "Graph.h"
#include <queue>

using namespace std;

// the elemtents that will be stored in the priority queue
struct pqElem {
  int cost; // the cost to get to the curVert
  int time; // the time cost to get to the curVert
  int curVert; // the index of the vertex this node represents
};

// the elements of array P[] described by the algorithm
struct pElem{
  int cost;
  int time;
};

// this is a functional class that is necessary for comparing the elements in the priority queue
class prioritize{
public:
   bool operator()(const pqElem& p1, const pqElem& p2) const{
      if(p1.cost == p2.cost) // if the money cost is the same, compare the time cost
         return p1.time > p2.time; // return the correct time cost
      else // if the money cost is not the same
         return p1.cost > p2.cost; // return the correct money cost
   }
}; // this is required for priority queue in C++ to run porperly. All it does is tell the priority queue how to compare its elements


int main(int argc, char *argv[]){
  graph g;
  
  if(argc != 5) {
    std::cout << "usage: ./p2 <filename> <source vertex> <destination vertex> <budget>\n";
    return 1;
  }
  else {
    if(!g.read_file(argv[1]))
      std::cout << "could not open file '" << argv[1] << "'\n";
  }
  int sourceV = stoi(argv[2]);
  int destV = stoi(argv[3]);
  int budget = stoi(argv[4]);
  std::cout << "\nADJACENCY-LIST REPRESENTATION:\n\n";
  g.display();
  cout << "\n";
  cout << "The source vertex is : " << sourceV << endl;
  cout << "The destination vertex is : " << destV << endl;
  cout << "The budget is : " << budget << endl;

  // the priority queue for the algorigthm. you can use regular pq methods on it (push, pop, top, empty, etc)
  priority_queue<pqElem, vector<pqElem>, prioritize> unvisitedQueue; // we might need to move it to a different method
  pElem P[g.num_nodes()];
  return 0;
}

