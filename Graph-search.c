/*충북대 자료구조 11주차 과제 그래프 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 10						// 최대 정점은 10개

typedef struct graphnode {					// 그래프 구조체
	int Vertex;								// 정점의 개수
	struct graphnode *link;					// 연결리스트 다음 노드를 가르키는 값

} graphNode;

typedef struct graphType {
	int n;									// 정점의 갯수
	graphNode* adjList[MAX_VERTEX];			// 각 정점의 인접 리스트
}graphType ;

/* 깊이 우선 탐색에 사용될 스텍 구현 */
#define MAX_STACK_SIZE		20
graphNode* stack[MAX_STACK_SIZE];
int top = -1;
graphNode* pop();
void push(graphNode* aNode);

/* 너비 우선 탐색에 사용될 스택 구현 */
#define MAX_QUEUE_SIZE		10
int queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

int deQueue();
void enQueue(int aNode);


graphType * initializeGraph(graphType* Graph);		 				// 그래프 생성
void freeGraph(graphType* Graph);                    				//그래프 동적할당 해제
void insertVertex(graphType*Graph);                     					//정점삽입
void insertEdge(graphType* Graph, int front, int rear);    					//두 정점의 연결
void DepthFirstSearch(graphType *Graph, int v);                          				//깊이 우선 탐색
void BreathFirstSearch(graphType *Graph, int v);                          				//너비 우선 탐색
void PrintGraph(graphType *Graph);                         					//그래프의 인접리스트를 출력



int main()
{
	char command;
	int key;
	
	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                          Graph Searches                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize Graph     = z                                       \n");
		printf(" Insert Vertex        = v      Insert Edge                  = e \n");
		printf(" Depth First Search   = d      Brearth Frist Search         = t \n");
		printf(" Print Graph          = p      Quit                         = q \n");
		printf("----------------------------------------------------------------\n");
		printf("------------[ 김 윤 희 ]------------[ 2018038014 ]---------------\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeGraph(graphType* Graph);
			break;
		case 'v': case 'V':
			freeBST(head);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(head, key);
			break;

		case 'r': case 'R':
			recursiveInorder(head->left);
			break;
		case 't': case 'T':
			iterativeInorder(head->left);
			break;

		case 'l': case 'L':
			levelOrder(head->left);
			break;

		case 'p': case 'P':
			printStack();
			break;

		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

void DepthFirstSearch(graphType *Graph, int v)
{

}