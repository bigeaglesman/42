#include <string.h>

//노드 구조체 (원형 이중 연결 리스트)
typedef struct s_node
{
	int data;
	t_node *prev;
	t_node *next;
}t_node;

//이중연결 리스트의 헤드 노드(덱 자체를 가리킨다)
typedef struct s_deque
{
	t_node *front;
	t_node *rear;
}t_deque;

//노드 생성 및 초기화 함수로 prev와 rear은 일단 NULL로 초기화한다
t_node *create_node(int data)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node) return NULL;
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

//덱 생성 함수
t_node *create_deque()
{
	t_deque	*deque;

	deque = (t_deque *)malloc(sizeof(t_deque));
	if(!deque) return NULL;
	deque->front = NULL;
	deque->rear = NULL;
	return deque;
}

//앞쪽에 요소 추가
void insert_front(t_deque *deque, int data){
	t_node	*new_node;
	
	new_node = create_node(data);
	if (!deque->front) //덱이 비어있는 경우
	{
		deque->front = new_node;
		deque->rear = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		new_node->next = deque->front;
		deque->front->prev = new_node;
		deque->front = new_node;
		deque->rear->next = deque->front;
		deque->front->prev = deque->rear;
	}
}

//뒤쪽에 요소 추가
void insert_rear(t_deque *deque, int data){
	t_node	*new_node;
	
	new_node = create_node(data);
	if (!deque->rear) //덱의 뒤가 비어있는 경우
	{
		deque->front = new_node;
		deque->rear = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		new_node->prev = deque->rear;
		deque->rear->next = new_node;
		deque->rear = new_node;
		deque->front->prev = deque->rear;
		deque->rear->next = deque->front;
	}
}

//앞쪽 요소 제거하고 데이터 반환
int delete_front(t_deque *deque)
{
	t_node *temp_node;
	int data;
	
	if (!deque->front)
	{
	printf("Deque is empty\n");
	return (-1);
	}
	temp_node = deque->front;
	data = temp_node->data;
	deque->front = deque->front->next;
	deque->front->prev = deque->rear;
	deque->rear->next = deque->front;
	free (temp_node);
	return (data);
}

//뒤쪽 요소 제거하고 데이터 반환
int delete_rear(t_deque *deque)
{
	t_node *temp_node;
	int data;
	
	if (!deque->rear)
	{
	printf("Deque is empty\n");
	return (-1);
	}
	temp_node = deque->rear;
	data = temp_node->data;
	deque->rear = deque->rear->prev;
	deque->front->prev = deque->rear;
	deque->rear->next = deque->front;
	free (temp_node);
	return (data);
}

//중간에서 요소 삭제
int delete_node(t_node *node, t_deque *deque)
{
	int	data;

	if (!node->prev == node)
	{
		deque->front = NULL;
		deque->rear = NULL;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	free (node);
}

//덱이 비어 있는지 확인
int	is_empty(t_deque *deque)
{
	return (deque->front == NULL);
}

//메모리 해제
void	free_deque(t_deque *deque)
{
	while (!is_empty(deque))
		delete_front(deque);
	free(deque);
}