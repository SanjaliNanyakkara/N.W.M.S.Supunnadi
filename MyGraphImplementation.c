#include<stdio.h>
#include<stdlib.h>

//to create a node which is connected to the given node (duplicate node)
struct AdListNode{
	int val;
	int weight;
	struct AdListNode *next;
};typedef struct AdListNode LNode;

 
//in order to keep track of nodes that connected to the given node
//maintain a pointer variable to keep track of adjacency nodes

struct AdList{
	int data;
	LNode *head;
};typedef struct AdList adlist;



//graph is presented as a linked list 
//linked list contains duplicate nodes which are connected to the given node 

struct GRAPH{
	int nodesNo;
	adlist *vertices;
};typedef struct GRAPH graph;

//function to create adjacency list node
LNode* createLNode(int value){
	LNode* newnode =(LNode*) malloc(sizeof(LNode));
	newnode->val=value;
	//printf("\ncheck createLNode : %d",newnode->val);
	printf("Enter the weight ");
	scanf("%d",&newnode->weight);
	newnode->next=NULL;
	
	return newnode;
}

//function to return a graph with vertices as we need 
graph * createGraph(void){
	
	int input;
	printf("Enter the num of nodes you need : ");
	scanf("%d",&input);
	
	graph *g=(graph*)malloc(sizeof(graph));
	g->nodesNo=input;
	
	g->vertices=(adlist*)malloc(input * (sizeof(adlist)));
	
	int i;
	
	//this will automatically create vertices as 1,2,3,4,.....,input
	for(i=1;i<=input;i++){
		g->vertices[i-1].data=i;
		g->vertices[i-1].head=NULL;
	}
	
	//this will print verices in the graph
	/*for(i=1;i<=input;i++){
		printf("check graph: %d \n",(g->vertices[i-1].data));
	}*/
	return g;
}

//created a adjacency list to directed graph considering outdegree
void buildEdges(graph *g){
	
	int size=g->nodesNo;
	
	int i;
	int duplicate=0;//this is to hold the number that given by user(adjacent node value)
	
	//to terminate from while loop need to give value -1
	printf("If you're done with giving adjacent nodes type -1 to quit \n'");
	
	for(i=0;i<size;i++){
		
		printf("\nEnter the out edges of %d",g->vertices[i].data);
		
		printf("\nEnter the outedge vertice's value :");
		scanf("%d",&duplicate);
		
		while(duplicate!=-1){
			if(duplicate<=size && duplicate>=1){
				
				LNode* newNode = createLNode(duplicate);
				//printf("\ncheck node creation : %d",newNode->val);
				
				newNode->next = g->vertices[i].head;
    			g->vertices[i].head = newNode;
    			//printf("\nCheck duplicate : %d",g->vertices[i].head->val);
    			
    			printf("Enter the next value :");
				scanf("%d",&duplicate);
			}else{
				
				printf("Invalid input,Entered value is not a vertice in graph \n");
				printf("Try again!! ,(1 ,2 , 3,..., %d)",size);
				duplicate=0;
			}
		}
	}
}

//print adjacency list with weights
void printGraph(graph *g){
	
    int v;
    for (v = 0; v < g->nodesNo; ++v)
    {
        LNode *adPointer=g->vertices[v].head;
        
        printf("\n Adjacency list of vertex %d\n head ",g->vertices[v].data);
        while (adPointer)
        {
            printf("-> %d weight : %d  ", adPointer->val,adPointer->weight);
            adPointer = adPointer->next;
        }
        printf("\n");
    }
}

int main(){
	graph *G=createGraph();
	buildEdges(G);
	printGraph(G);
}
