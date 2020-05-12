bool containsCycle(const LinkedListNode* firstNode)
{
    // check if the linked list contains a cycle
    unordered_set<LinkedListNode*> visited;
    const LinkedListNode* current = firstNode;
    
    while ( current ) {
        if ( visited.find( current ) != visited.end() ) {
            return true;
        }
        else {
            visited.insert( visited );
            visited = visited->next_;
        }
    }

    return false;
}