#        TRIE DICTIONARY 

1. Problem Description:

	Trie dictionary as the name suggests is a dictionary with a collection of words and its meanings stored in the trie data structure. The use cases of this project would be meaning search and prefix search. The first use case is simply returning the stored meaning of the word that the user enters while the second one is the autocomplete feature such that if the user enters a prefix to a word my program should be able to suggest words which begin with the prefix entered. 	
Examples:
	Input: word = “map”
	Output: a diagrammatic representation of an area
  Input: word = “language”
  Output: the method of human communication 
2. Proposed Solution:

	We use a Trie to efficiently store strings from a prebuilt dictionary file and search them. We add another field to Trie node, a string which will hold the meaning of a word. While searching for the meaning of the required word, we search for the word in Trie and if the word is present (i.e end = 1) then we return its meaning otherwise we search the trie with the input prefix and return the nearest related words in the dictionary.
	Trie is an efficient information retrieval data structure. Using Trie, search complexities can be brought to optimal limit (key length). Using Trie, we can search the key in O(M) time.This performance will be incredibly valuable for dictionaries having a large number of  words in it, as the amount of words within the dictionary will have no effect on the runtime that it can be traversed in.

3. Alternate Solutions:

    • Using Binary Search Tree :If we store keys in binary search tree, a well balanced BST will need time proportional to M * log N to search the key, where M is maximum string length and N is number of keys in tree. Using Trie, we can search the key in O(M) time.
 
    • Using HashTable : A hashtable usually has a better runtime in case of insertions and lookups, but when it comes to prefix related queries, tries are preffered as we do not need to compute any hash function, no collision handling is required. We can easily print all words in alphabetical order using tries, which is not easily possible with hashing. The only disadvantage of using trie is that they need a lot of memory for storing the strings. For each node we have too many node pointers(equal to number of characters of the alphabet).

    • Using Ternary Search Trees: A ternary Search Tree has a better search time, ie looking up a word of length L takes time O(L log k), where k is the number of alphabets while Trie takes O(L) time.
	But for cases where each node in the trie has most of its child nodes used, the Trie is 	substantially more space efficient and time efficient than th ternary search tree. If each node 	stores comparatively few child nodes, the ternary search tree is much more space efficient.
