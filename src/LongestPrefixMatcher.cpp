
#include "LongestPrefixMatcher.h"


void LongestPrefixMatcher::add(int ip, int prefix_length, int port_number) {
    Trie *node = &ipTrie;

    for (int i = 31, j = 0; j < prefix_length; i--, j++) {
        Trie *next = node->subTrie[ip >> i & 1];

        if (next == nullptr) {
            next = new Trie;
            node->subTrie[ip >> i & 1] = next;
        }

        node = next;
    }
    node->port = port_number;
}

int LongestPrefixMatcher::lookup(int ip) {
    Trie *node = &ipTrie;
    int port = -1;

    for (int i = 31; node != nullptr; i--) {
        if (node->port >= 0) port = node->port;
        node = node->subTrie[ip >> i & 1];
    }
    return port;
}