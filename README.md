# TrieDictionary
Dictionary Using Trie in C++

Purpose
To implement a dictionary, that contains words and their relevant meanings, and allows the user to search the dictionary and get a suitable output in optimal run-time.

Implementation

it is implemented using a 'trie', commonly known as a 'digital tree' or a 'prefix tree'.
Unlike a binary tree which simply has two child nodes, each node has a maximum of 26 child nodes which accounts for all the letters in english alphabet, in lower case (0-25 index representing a-z).
Each child node which represents the end of a word has a string value assigned, which provides the meaning of the entire word in the trie.
This approach applies itself well to a dictionary case scenario as traversing through the trie results in traversing the word letter by letter.
Using this traversal technique allows us to operate in O(n) time frame where n represents the length of the word to be searched. This leads to linear performance given the length of the word to search for. This performance will be incredibly valuable for dictionaries having a large number of  words in it, as the amount of words within the dictionary will have no effect on the runtime that it can be traversed in.
It has an auto-guessing feature which predicts the word in the dictionary related to the entered prefix.
