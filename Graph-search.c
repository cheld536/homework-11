/*충북대 자료구조 11주차 과제 그래프 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 10																	// 최대 정점은 10개
#define FALSE 0																			// 방문 안했으면 0
#define TURE 1																			// 방문 했으면 1

typedef struct graphnode {																// 그래프 구조체
	int Vertex;																			// 정점의 개수
	struct graphnode* link;																// 연결리스트 다음 노드를 가르키는 값

} graphNode;

typedef struct graphType {
	int n;																				// 정점의 갯수
	graphNode* adjList[MAX_VERTEX];														// 각 정점의 인접항을 연결하는 배열
	int visited[MAX_VERTEX];															// 정점에 대한 방문표시를 위한 배열
}graphType;

/* 스택을 사용하기 위한 구조체*/
typedef struct stackNode {
	int data;
	struct stackNode* link;
}stackNode;

/* 깊이 우선 탐색에 사용될 스텍 구현 */

int top = -1;
graphNode* pop();
void push(graphNode* aNode);

/* 너비 우선 탐색에 사용될 스택 구현 */
int queue[MAX_VERTEX];																	// 최대 정점의 갯수만큼 구현
int front = -1;
int rear = -1;
int deQueue();
void enQueue(int v);


graphType* initializeGraph(graphType* Graph);		 											// 그래프 생성
void freeGraph(graphType* Graph);                    									//그래프 동적할당 해제
void insertVertex(graphType* Graph, int vertex);                     										//정점삽입
void insertEdge(graphType* Graph, int front, int rear);    								//두 정점의 연결
void DepthFirstSearch(graphType* Graph, int v);                          				//깊이 우선 탐색
void BreathFirstSearch(graphType* Graph, int v);                          				//너비 우선 탐색
void PrintGraph(graphType* Graph);                         								//그래프의 인접리스트를 출력



int main()
{
	char command;																		//사용자로부터 메뉴 값을 입력받는다.
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
		printf("------------[ 김 윤 희 ]------------[ 2018038014 ]---------------\n");
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
	int i;														// 반복문을 돌릴 변수
	if (Graph != NULL)
		freeGraph(Graph);										// 만약 그래프가 존재한다면 삭제하고 온다.
    Graph = (graphType*)malloc(sizeof(graphType));
	Graph->n = 0;												// 그래프의 정점은 0
	for (i = 0; i < MAX_VERTEX; i++)
	{
		
		Graph->adjList[i] = NULL;								// NULL로 초기화
		Graph->visited[i] = FALSE;								// 방문을 안했기 떄문에 0으로 초기화  // 방문하면 1
	}
	return Graph;
}

void insertVertex(graphType* Graph, int vertex)
{
	if (vertex < 0 || vertex > 9) {		//0~9값이 아니면 오류문구 출력
		printf("정점은 0~9 사이 입니다.\n");
		return;
	}

	if ((Graph->n) + 1 > MAX_VERTEX)
	{
		printf("\n 그래프 정점의 개수를 초과하였습니다.!\n");
		return;
	}
	graphNode* Node = (graphNode*)malloc(sizeof(graphNode));
	Node->link = NULL;
	Graph->adjList[vertex]->link = Node;
	Graph->adjList[vertex]->Vertex = -9999;
	Graph->n++;
}
void DepthFirstSearch(graphType* Graph, int v)					// 깊이 우선 탐색 구현 
{
	if (v < 0 || v>9) {		//0~9값이 아니면 오류문구 출력
		printf("정점의 값은 0~9 사이의 값입니다.\n");
		return;
	}
	graphNode* w;
	Graph->visited[v] = TURE;							// 정점 v를 방문했으므로 해당 배열값을 TURE로 설정 
	printf("\t[ %d ]", v);
	for (w = Graph->adjList[v]; w; w = w->link)           //v에 인접한 리스트를 쭉 따라가면서
	{
		if (!Graph->visited[w->Vertex])                   //그 인접항리스트의 정점을 지나가지 않으면
		{
			DepthFirstSearch(Graph, w->Vertex);                       //DFS 순환 호출
		}
	}


}

void BreathFirstSearch(graphType* Graph, int v)								// 너비 우선 탐색 구현 
{
	if (v < 0 || v > 9) {													//0~9값이 아니면 오류문구 출력
		printf("정점은 0~9까지 입력해주세요.\n");
		return;
	}
	graphNode* w;
	front = rear = -1;  													// 큐 초기화
	Graph->visited[v] = TURE;												// 방문을 했기 때문에 Ture로 변경
	enQueue(v);
	while (1)
	{
		v = deQueue();														//큐에 정점을 반환
		if (v = -9999)														// front와 rear이 같으면
		{
			break;
		}
		for (w = Graph->adjList[v]; w; w = w->link)
		{
			if (!Graph->visited[w->Vertex])
			{
				printf("→ [ %d ]", w->Vertex);
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
		printf("\n\t\t정점 [%d] 의 인접 리스트 : ", i);
		while (p)
		{
			printf(" → [ %d ]", p->Vertex);
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
		printf("\n\n메모리 해제가 성공적으로 실행 되었습니다.\n\n");
	}
	else
	{
		printf("메모리를 생성된 메모리가 없습니다.\n\n");
	}
	return;
}

void insertEdge(graphType* Graph, int front, int rear)
{
	graphNode* node;														//각 정점의 인접 리스트를 탐색하는 노드
	graphNode* pre = NULL; 													//이전 리스트를 기억할 노드
	if (front >= Graph->n || rear >= Graph->n)								//간선 (front) 와 (rear)이 정점의 갯수보다 더 큰 간선이 드러오면 오류 발생
	{
		printf("\n 그래프에 없는 정점입니다.\n");
		return;
	}
	if (front < 0 || rear < 0)												//음수가 들어왔을때 오류 문구 출력
	{
		printf("음수 넣지 말라고\n");
		return;

	}
	node = (graphNode*)malloc(sizeof(graphNode));							// 노드를 동적할당
	node->Vertex = rear;													// 정점을 rear로 초기화
	node->link = NULL;														// 링크를 널로 초기화
	if (Graph->adjList[front] == NULL)		// 인접한 정점이 없을때 (맨 앞이거나 맨뒤)
	{
		Graph->adjList[front] = node; 	// 노드 삽입
	}
	else {								// 그외의 경우
		while (node)					// 노드가 널값이 아닐때 까지
		{
			if (node->Vertex == rear)
			{
				printf("\n이미 있는 간선입니다.\n");
				return;
			}
			if (node->Vertex > rear)
			{
				break;
			}
			node = node->link;
			pre = node;
		}
		if (node == Graph->adjList[front])	 // 중간 값입
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

/* 원형 큐 front에 원소를 삭제하는 함수*/
int deQueue()
{

	if (rear == front || front == MAX_VERTEX - 1) 		// rear 과 front가 같으면 큐가 비었다는 뜻임으로
	{
		return -9999;		// 널값을 반환
	}
	return queue[++front];

}

/* 원형 큐의 rear에 원소를 삽입하는 함수*/
void enQueue(int v)
{
	if (rear >= MAX_VERTEX - 1) //  만약 배열의 크기가 넘어가면 오류가 발생
	{
		printf("큐가 꽉 찼습니다\n");
		return;
	}
	else						//  배열의 크기가 넘지 않았다면 데이터를 저장한다.
		queue[++rear] = v;
}

