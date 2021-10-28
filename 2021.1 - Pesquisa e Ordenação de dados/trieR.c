// C implementation of Trie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') // Converts key current character into index; use only 'a' through 'z' and lower case


// structure of a trie node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;     // true if the node represents end of a word
};

typedef struct TrieNode Node; // new data type "Node"

// Returns new trie node (initialized to NULLs)
Node *createNode(){
    Node *temp = NULL;
    temp = (Node *) malloc(sizeof(Node));
    if (temp) {
        temp->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            temp->children[i] = NULL;
    }
    return temp;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(Node *root, char *word) {
    int index;
    Node *current = root;
    for (int position = 0; position < strlen(word); position++) { // each character of the new key
        index = CHAR_TO_INDEX(word[position]);
        if (!current->children[index]) // null
            current->children[index] = createNode(); // character not exists; creates new node

        current = current->children[index]; // go to next level
    }
    // mark last node of the key as leaf
    current->isEndOfWord = true;
}

// Returns true if key is present in trie; else false
bool search(Node *root, char *word){
    int index;
    Node *current = root;
    for (int position = 0; position < strlen(word); position++){
        index = CHAR_TO_INDEX(word[position]);
        if (!current->children[index]) // null
            return false;
        current = current->children[index]; // go to next level
    }
    return (current != NULL && current->isEndOfWord);
}

bool haveChildren(Node* current){
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (current->children[i])
			return true;	// child found
	return false;
}

// Recursive function to delete a string in Trie
bool delete(Node **current, char* str){
	// return if Trie is empty
	if (*current == NULL)
		return false;

	// if we have not reached the end of the string
	if (*str){
		// recur for the node corresponding to next character in
		// the string and if it returns 1, delete current node (if it is non-leaf)
		if (*current != NULL && (*current)->children[CHAR_TO_INDEX(*str)] != NULL &&
			delete(&((*current)->children[CHAR_TO_INDEX(*str)]), str + 1) &&
			(*current)->isEndOfWord == 0){
			if (!haveChildren(*current)){
				free(*current);
				(*current) = NULL;
				return true;
			}
			else {
				return false;
			}
		}
	}

	// if we have reached the end of the string
	if (*str == '\0' && (*current)->isEndOfWord){
		// if current node is a leaf node and don't have any children
		if (!haveChildren(*current)){
			free(*current); // delete current node
			(*current) = NULL;
			return true; // delete non-leaf parent nodes
		}

		// if current node is a leaf node and have children
		else {
			// mark current node as non-leaf node (DON'T DELETE IT)
			(*current)->isEndOfWord = 0;
			return false;	   // don't delete its parent nodes
		}
	}
	return false;
}

void traverse(Node* root){
    char buffer[100];
    traverseUtil(root, buffer, 0);
}


void traverseUtil(Node* root, char buffer[], int depth) {
    // If node is end of word, so a null character is added and string is displayed
    if (root->isEndOfWord){
        buffer[depth] = '\0';
        printf("%s\n", buffer);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        // if NON NULL child is found, add parent key to buffer and
        // call the function recursively for child node
        if (root->children[i])  {  // not null
            buffer[depth] = i + 'a'; // index to char
            traverseUtil(root->children[i], buffer, depth + 1);
        }
    }
}


int main(){
    // Input keys (use only 'a' through 'z' and lower case; words at most 100 characters)
    char keys[][100] = {"ata", "galo", "gel", "sola", "ator", "solo", "ato", "ala"};

    char output[][20] = {"Not present in trie", "Present in trie"};

    Node *root = createNode();

    // Construct trie
    for (int i = 0; i < ARRAY_SIZE(keys); i++)
        insert(root, keys[i]);

    printf("\nWords in trie:\n");
    traverse(root);

    // Search for different keys
    printf("\n\nSearch:\n");
    printf("%s --- %s\n", "ata", output[search(root, "ata")] );
    printf("%s --- %s\n", "sol", output[search(root, "sol")] );
    printf("%s --- %s\n", "sola", output[search(root, "sola")] );
    printf("%s --- %s\n", "alas", output[search(root, "alas")] );

    // insert new keys 
    insert(root, "casa");
    insert(root, "casaco");
    insert(root, "sol");
    insert(root, "geleia");

    // delete some keys
    delete(&root, "ator");
    delete(&root, "galo");
    delete(&root, "sola");

    // Displaying content of Trie
    printf("\nNew trie:\n");
    traverse(root);

    return 0;
}