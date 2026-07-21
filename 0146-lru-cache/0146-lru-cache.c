#define HASH_SIZE 10007

typedef struct Node {
    int key;
    int value;
    struct Node *prev;
    struct Node *next;
    struct Node *hnext;
} Node;

typedef struct {
    int capacity;
    int size;
    Node *head;
    Node *tail;
    Node *hash[HASH_SIZE];
} LRUCache;

int hashFunc(int key)
{
    return key % HASH_SIZE;
}

Node* findNode(LRUCache* obj, int key)
{
    Node *cur = obj->hash[hashFunc(key)];

    while(cur)
    {
        if(cur->key == key)
            return cur;

        cur = cur->hnext;
    }

    return NULL;
}

void insertHash(LRUCache* obj, Node *node)
{
    int h = hashFunc(node->key);

    node->hnext = obj->hash[h];
    obj->hash[h] = node;
}

void removeHash(LRUCache* obj, int key)
{
    int h = hashFunc(key);

    Node *cur = obj->hash[h];
    Node *prev = NULL;

    while(cur)
    {
        if(cur->key == key)
        {
            if(prev)
                prev->hnext = cur->hnext;
            else
                obj->hash[h] = cur->hnext;

            return;
        }

        prev = cur;
        cur = cur->hnext;
    }
}

void removeNode(LRUCache* obj, Node *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void addFront(LRUCache* obj, Node *node)
{
    node->next = obj->head->next;
    node->prev = obj->head;

    obj->head->next->prev = node;
    obj->head->next = node;
}

LRUCache* lRUCacheCreate(int capacity)
{
    LRUCache *obj = (LRUCache*)malloc(sizeof(LRUCache));

    obj->capacity = capacity;
    obj->size = 0;

    for(int i = 0; i < HASH_SIZE; i++)
        obj->hash[i] = NULL;

    obj->head = (Node*)malloc(sizeof(Node));
    obj->tail = (Node*)malloc(sizeof(Node));

    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;

    obj->head->prev = NULL;
    obj->tail->next = NULL;

    return obj;
}

int lRUCacheGet(LRUCache* obj, int key)
{
    Node *node = findNode(obj, key);

    if(node == NULL)
        return -1;

    removeNode(obj, node);
    addFront(obj, node);

    return node->value;
}

void lRUCachePut(LRUCache* obj, int key, int value)
{
    Node *node = findNode(obj, key);

    if(node)
    {
        node->value = value;
        removeNode(obj, node);
        addFront(obj, node);
        return;
    }

    if(obj->size == obj->capacity)
    {
        Node *lru = obj->tail->prev;

        removeNode(obj, lru);
        removeHash(obj, lru->key);

        free(lru);

        obj->size--;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->key = key;
    newNode->value = value;

    addFront(obj, newNode);
    insertHash(obj, newNode);

    obj->size++;
}

void lRUCacheFree(LRUCache* obj)
{
    Node *cur = obj->head;

    while(cur)
    {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }

    free(obj);
}