bool containsCycle(const LinkedListNode* h)
{
    // check if the linked list contains a cycle
    unordered_set<LinkedListNode*> s; 
    while (h != NULL) { 
        if (s.find(h) != s.end()) 
            return true; 
        s.insert(h); 
        h = h->next; 
    } 
    return false; 
}