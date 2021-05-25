/*��ϴ� �ڷᱸ�� 11���� ���� �׷��� */

#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 10																	// �ִ� ������ 10��
#define FALSE 0																			// �湮 �������� 0
#define TURE 1																			// �湮 ������ 1

typedef struct graphnode {																// �׷��� ����ü
	int Vertex;																			// ������ ����
	struct graphnode* link;																// ���Ḯ��Ʈ ���� ��带 ����Ű�� ��

} graphNode;

typedef struct graphType {
	int n;																				// ������ ����
	graphNode* adjList[MAX_VERTEX];														// �� ������ �������� �����ϴ� �迭
	int visited[MAX_VERTEX];															// ������ ���� �湮ǥ�ø� ���� �迭
}graphType;

/* ������ ����ϱ� ���� ����ü*/
typedef struct stackNode {
	int data;
	struct stackNode* link;
}stackNode;

/* ���� �켱 Ž���� ���� ���� ���� */

int top = -1;
graphNode* pop();
void push(graphNode* aNode);

/* �ʺ� �켱 Ž���� ���� ���� ���� */
int queue[MAX_VERTEX];																	// �ִ� ������ ������ŭ ����
int front = -1;
int rear = -1;
int deQueue();
void enQueue(int v);


graphType* initializeGraph(graphType* Graph);		 											// �׷��� ����
void freeGraph(graphType* Graph);                    									//�׷��� �����Ҵ� ����
void insertVertex(graphType* Graph, int vertex);                     										//��������
void insertEdge(graphType* Graph, int front, int rear);    								//�� ������ ����
void DepthFirstSearch(graphType* Graph, int v);                          				//���� �켱 Ž��
void BreathFirstSearch(graphType* Graph, int v);                          				//�ʺ� �켱 Ž��
void PrintGraph(graphType* Graph);                         								//�׷����� ��������Ʈ�� ���



int main()
{
	char command;																		//����ڷκ��� �޴� ���� �Է¹޴´�.
	int key;																			// 
	int front;																			//
	int rear;																			//
	int edg;																			//
	graphType* head = NULL;
	do {
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

		switch (command) {
		case 'z': case 'Z':
			initializeGraph(head);
			break;
		case 'v': case 'V':
			printf("input your Vertex( 0 ~ 9 ) : ");
			scanf("%d", &key);
			insertVertex(head, key);
			break;
		case 'e': case 'E':
			printf("front : ");
			scanf("%d", &front);
			printf("rear : ");
			scanf("%d", &rear);
			insertEdge(head, front, rear);

			break;
		case 'd': case 'D':
			printf("input Your Vertex = ");
			scanf("%d", &key);
			DepthFirstSearch(head, key);
			break;

		case 't': case 'T':
			printf("input Your vertex = ");
			scanf("%d", &key);
			BreathFirstSearch(head, key);
			break;

		case 'p': case 'P':
			PrintGraph(head);
			break;
		case 'q': case 'Q':
			freeGraph(head);
			break;

		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}
graphType* initializeGraph(graphType* Graph)
{
	int i;														// �ݺ����� ���� ����
	if (Graph != NULL)
		freeGraph(Graph);										// ���� �׷����� �����Ѵٸ� �����ϰ� �´�.
    Graph = (graphType*)malloc(sizeof(graphType));
	Graph->n = 0;												// �׷����� ������ 0
	for (i = 0; i < MAX_VERTEX; i++)
	{
		
		Graph->adjList[i] = NULL;								// NULL�� �ʱ�ȭ
		Graph->visited[i] = FALSE;								// �湮�� ���߱� ������ 0���� �ʱ�ȭ  // �湮�ϸ� 1
	}
	return Graph;
}

void insertVertex(graphType* Graph, int vertex)
{
	if (vertex < 0 || vertex > 9) {		//0~9���� �ƴϸ� �������� ���
		printf("������ 0~9 ���� �Դϴ�.\n");
		return;
	}

	if ((Graph->n) + 1 > MAX_VERTEX)
	{
		printf("\n �׷��� ������ ������ �ʰ��Ͽ����ϴ�.!\n");
		return;
	}
	graphNode* Node = (graphNode*)malloc(sizeof(graphNode));
	Node->link = NULL;
	Graph->adjList[vertex]->link = Node;
	Graph->adjList[vertex]->Vertex = -9999;
	Graph->n++;
}
void DepthFirstSearch(graphType* Graph, int v)					// ���� �켱 Ž�� ���� 
{
	if (v < 0 || v>9) {		//0~9���� �ƴϸ� �������� ���
		printf("������ ���� 0~9 ������ ���Դϴ�.\n");
		return;
	}
	graphNode* w;
	Graph->visited[v] = TURE;							// ���� v�� �湮�����Ƿ� �ش� �迭���� TURE�� ���� 
	printf("\t[ %d ]", v);
	for (w = Graph->adjList[v]; w; w = w->link)           //v�� ������ ����Ʈ�� �� ���󰡸鼭
	{
		if (!Graph->visited[w->Vertex])                   //�� �����׸���Ʈ�� ������ �������� ������
		{
			DepthFirstSearch(Graph, w->Vertex);                       //DFS ��ȯ ȣ��
		}
	}


}

void BreathFirstSearch(graphType* Graph, int v)								// �ʺ� �켱 Ž�� ���� 
{
	if (v < 0 || v > 9) {													//0~9���� �ƴϸ� �������� ���
		printf("������ 0~9���� �Է����ּ���.\n");
		return;
	}
	graphNode* w;
	front = rear = -1;  													// ť �ʱ�ȭ
	Graph->visited[v] = TURE;												// �湮�� �߱� ������ Ture�� ����
	enQueue(v);
	while (1)
	{
		v = deQueue();														//ť�� ������ ��ȯ
		if (v = -9999)														// front�� rear�� ������
		{
			break;
		}
		for (w = Graph->adjList[v]; w; w = w->link)
		{
			if (!Graph->visited[w->Vertex])
			{
				printf("�� [ %d ]", w->Vertex);
				enQueue(w->Vertex);
				Graph->visited[w->Vertex] = TURE;
			}
		}

	}
}

void PrintGraph(graphType* Graph)
{
	int i;
	graphNode* p;
	for (i = 0; i < Graph->n; i++)
	{
		printf("\n\t\t���� [%d] �� ���� ����Ʈ : ", i);
		while (p)
		{
			printf(" �� [ %d ]", p->Vertex);
			p = p->link;
		}
		printf("\n");
	}
}

void freeGraph(graphType* Graph)
{
	if (Graph)
	{
		free(Graph);
		printf("\n\n�޸� ������ ���������� ���� �Ǿ����ϴ�.\n\n");
	}
	else
	{
		printf("�޸𸮸� ������ �޸𸮰� �����ϴ�.\n\n");
	}
	return;
}

void insertEdge(graphType* Graph, int front, int rear)
{
	graphNode* node;														//�� ������ ���� ����Ʈ�� Ž���ϴ� ���
	graphNode* pre = NULL; 													//���� ����Ʈ�� ����� ���
	if (front >= Graph->n || rear >= Graph->n)								//���� (front) �� (rear)�� ������ �������� �� ū ������ �巯���� ���� �߻�
	{
		printf("\n �׷����� ���� �����Դϴ�.\n");
		return;
	}
	if (front < 0 || rear < 0)												//������ �������� ���� ���� ���
	{
		printf("���� ���� �����\n");
		return;

	}
	node = (graphNode*)malloc(sizeof(graphNode));							// ��带 �����Ҵ�
	node->Vertex = rear;													// ������ rear�� �ʱ�ȭ
	node->link = NULL;														// ��ũ�� �η� �ʱ�ȭ
	if (Graph->adjList[front] == NULL)		// ������ ������ ������ (�� ���̰ų� �ǵ�)
	{
		Graph->adjList[front] = node; 	// ��� ����
	}
	else {								// �׿��� ���
		while (node)					// ��尡 �ΰ��� �ƴҶ� ����
		{
			if (node->Vertex == rear)
			{
				printf("\n�̹� �ִ� �����Դϴ�.\n");
				return;
			}
			if (node->Vertex > rear)
			{
				break;
			}
			node = node->link;
			pre = node;
		}
		if (node == Graph->adjList[front])	 // �߰� ����
		{
			node->link = Graph->adjList[front];
			Graph->adjList[front] = node;
		}
		else
		{
			node->link = node;
			pre->link = node;
		}

	}

}

/* ���� ť front�� ���Ҹ� �����ϴ� �Լ�*/
int deQueue()
{

	if (rear == front || front == MAX_VERTEX - 1) 		// rear �� front�� ������ ť�� ����ٴ� ��������
	{
		return -9999;		// �ΰ��� ��ȯ
	}
	return queue[++front];

}

/* ���� ť�� rear�� ���Ҹ� �����ϴ� �Լ�*/
void enQueue(int v)
{
	if (rear >= MAX_VERTEX - 1) //  ���� �迭�� ũ�Ⱑ �Ѿ�� ������ �߻�
	{
		printf("ť�� �� á���ϴ�\n");
		return;
	}
	else						//  �迭�� ũ�Ⱑ ���� �ʾҴٸ� �����͸� �����Ѵ�.
		queue[++rear] = v;
}

