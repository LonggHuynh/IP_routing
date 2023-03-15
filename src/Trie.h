#ifndef TRIE_H
#define TRIE_H

struct Trie {
    int port = -1;
    Trie *subTrie[2] = {nullptr, nullptr};
};

#endif
