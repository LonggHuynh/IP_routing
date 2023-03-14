

#include <stdint.h>
#include <stdio.h>
#include "Trie.h"

class LongestPrefixMatcher {
    Trie ipTrie;

public:
    void add(int ip, int prefix_length, int port_number);

    int lookup(int ip);
};


