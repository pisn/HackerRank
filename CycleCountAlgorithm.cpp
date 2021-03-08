//Originally tried to use this solution fo a problem. Algorithm of cycle detection works, although not for intended problem.
//Saved this code just in case.
//Detects all cycles in a graph
#include<bits/stdc++.h>

using namespace std;

const int N = 100000;

vector<int> adjList[N];
int color[N];
int previous[N];
int cycles[N];
int cycleId = 0;
int cycleMaxSize=0;

//dfs to look for all cycles in graph
void dfs(int originNode, int previousNode){

    if(color[originNode] == 2) //search was already executed from this node
        return;

    if(color[originNode] == 1){ //Node is already colored 1 before coloring him.  A cycle has been closed. Let's obtain its total length;
        cycleId++;

        int nodeCursor = previousNode;
        int cycleSize = 1;
        bool invalid = false;        
        cycles[nodeCursor] = cycleId;

        while(nodeCursor != originNode){
            nodeCursor = previous[nodeCursor];
            cycles[nodeCursor] = cycleId;
            cycleSize++;
        }        
        

        if(!invalid && cycleSize > cycleMaxSize){
            cycleMaxSize = cycleSize;
        }

        return;
    }

    previous[originNode] = previousNode;
    color[originNode] = 1; //Starting search from this node. Coloring it as 1 just in case search returns to this note.

    for(int neighbor : adjList[originNode]){
        dfs(neighbor, originNode);
    }

    color[originNode] = 2;//search already finished for this node

}

int main(){

    int n,k,i,j,current;    

    scanf("%d%d",&n,&k);

    int* s = new int[n];
    int* p = new int[n];    

    for(i=0; i<n; i++){
        scanf("%d", &s[i]);
    }

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if((s[i] + s[j]) % k != 0){ //Add Node to list
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    for(i=0;i<n;i++)
        dfs(i,-99);

    printf("%d", cycleMaxSize);

    free(p);
    free(s);
}