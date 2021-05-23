/*��ϴ� �ڷᱸ�� 11���� ���� �׷��� */

#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 10						// �ִ� ������ 10��

typedef struct graphnode {					// �׷��� ����ü
	int Vertex;								// ������ ����
	struct graphnode *link;					// ���Ḯ��Ʈ ���� ��带 ����Ű�� ��

} graphNode;

typedef struct graphType {
	int n;									// ������ ����
	graphNode* adjList[MAX_VERTEX];			// �� ������ ���� ����Ʈ
}graphType ;

/* ���� �켱 Ž���� ���� ���� ���� */
#define MAX_STACK_SIZE		20
graphNode* stack[MAX_STACK_SIZE];
int top = -1;
graphNode* pop();
void push(graphNode* aNode);

/* �ʺ� �켱 Ž���� ���� ���� ���� */
#define MAX_QUEUE_SIZE		10
int queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

int deQueue();
void enQueue(int aNode);


graphType * initializeGraph(graphType* Graph);		 				// �׷��� ����
void freeGraph(graphType* Graph);                    				//�׷��� �����Ҵ� ����
void insertVertex(graphType*Graph);                     					//��������
void insertEdge(graphType* Graph, int front, int rear);    					//�� ������ ����
void DepthFirstSearch(graphType *Graph, int v);                          				//���� �켱 Ž��
void BreathFirstSearch(graphType *Graph, int v);                          				//�ʺ� �켱 Ž��
void PrintGraph(graphType *Graph);                         					//�׷����� ��������Ʈ�� ���



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
		printf("------------[ �� �� �� ]------------[ 2018038014 ]---------------\n");
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