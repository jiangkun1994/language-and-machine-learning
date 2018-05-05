#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

typedef struct Node{
    char *word;
    int wNum;
    struct Node *next;
} wordNode;

char *wordJob(wordNode **head, char *word, int len);
void printList(wordNode *head);
void wordCount(wordNode **head, char *a, int len);
void release(wordNode *head);
void chopN(char *str, size_t n);

wordNode *SortedMerge(wordNode *a, wordNode *b);
void FrontBackSplit(wordNode *source, wordNode **frontRef, wordNode **backRef);
void MergeSort(wordNode **headRef);

int main(int argc,char *argv[]){
    wordNode *head = NULL;
    char *temp = NULL;
    int len = 0;
    while(scanf("%ms", &temp) != EOF){ // %ms：输出的字符串占m列，如字符串本身长度大于m，则突破获m的限制,将字符串全部输出。若串长小于m，则左补空格。
        while(temp[len++] != '\0');
        temp = wordJob(&head, temp, len);
        len = 0;
        free(temp);
    }
    MergeSort(&head);
    printList(head);
    release(head);
    
    return 0;
}


char *wordJob(wordNode **head, char *word, int len){
    int i = 0;
    int j = 0;
    char c;

    while((c = word[i++]) != '\0'){
        if(isalnum(c)){
            word[j++] = c;
        }
        else{
            word[j] = '\0';
            wordCount(head, word, len);
            chopN(word, j+1);
            j = 0;
        }
        
    }
    word[j] = '\0';
    wordCount(head, word, len);
    return word;
}

void chopN(char *str, size_t n)
{
    assert(n != 0 && str != 0);
    size_t len = strlen(str);
    if (n > len)
        return;  // Or: n = len;
    memmove(str, str+n, len - n + 1);
}

void printList(wordNode *head){
    wordNode *current = head;
    while(current != NULL) {
        printf("%s: %d\n", current->word, current->wNum);
        current = current->next;
    }
}

void wordCount(wordNode **head, char *a, int len) {
    if(a[0] == '\0') return;
    wordNode *newNode = malloc(sizeof(wordNode));
    wordNode *last = *head;
    newNode->word = malloc(sizeof(newNode->word) * len);
    strcpy(newNode->word, a);
    newNode->next = NULL;
    newNode->wNum = 0;
    
    if(*head == NULL){
        newNode->wNum++;
        *head = newNode;
        return;
    }

    while(last->next != NULL){
        if(strcmp(last->word, newNode->word) == 0) {
            last->wNum++;
            release(newNode);
            return;
        }
        
        last = last->next;
        
    }
    
    if(strcmp(last->word, newNode->word) == 0) {
        last->wNum++;
        release(newNode);
        
    }
    else {
        last->next = newNode;
        last->next->wNum++;
        
    }
    return;
}


void release(wordNode *head){
    if(head == NULL) return;
    wordNode *temp = head;

    while(temp != NULL){
        head = temp->next;
        free(temp->word);
        free(temp);
        temp = head;
    }
}

//merge sort from https://www.geeksforgeeks.org/merge-sort-for-linked-list/
void MergeSort(wordNode **headRef){
    wordNode *head = *headRef;
    wordNode *a;
    wordNode *b;
    
    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }
    
    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b); 
    
    /* Recursively sort the sublists */
    MergeSort(&a);
    MergeSort(&b);
    
    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b);
}

wordNode *SortedMerge(wordNode *a, wordNode *b){
    wordNode *result = NULL;
    
    /* Base cases */
    if (a == NULL)
        return(b);
    else if (b==NULL)
        return(a);
    
    /* Pick either a or b, and recur */
    if (strcmp(a->word, b->word) < 0)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return(result);
}

void FrontBackSplit(wordNode *source, wordNode **frontRef, wordNode **backRef){
    wordNode *fast;
    wordNode *slow;
    slow = source;
    fast = source->next;
 
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL){
        fast = fast->next;
        if (fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
