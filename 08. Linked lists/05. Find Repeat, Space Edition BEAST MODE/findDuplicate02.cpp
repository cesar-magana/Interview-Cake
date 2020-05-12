unsigned int findDuplicate(const vector<unsigned int>& intVector)
{
    const unsigned int n = static_cast<unsigned int>(intVector.size() - 1);

    // STEP 1: GET INSIDE A CYCLE
    // start at position n+1 and walk n steps to
    // find a position guaranteed to be in a cycle
    unsigned int positionInCycle = n + 1;
    for (unsigned int i = 0; i < n; ++i) {

        // we subtract 1 from the current position to step ahead:
        // the 2nd *position* in an array is *index* 1
        positionInCycle = intVector[positionInCycle - 1];
    }

    // STEP 2: FIND THE LENGTH OF THE CYCLE
    // find the length of the cycle by remembering a position in the cycle
    // and counting the steps it takes to get back to that position
    unsigned int rememberedPositionInCycle = positionInCycle;
    unsigned int currentPositionInCycle = intVector[positionInCycle - 1];  // 1 step ahead
    unsigned int cycleStepCount = 1;

    while (currentPositionInCycle != rememberedPositionInCycle) {
        currentPositionInCycle = intVector[currentPositionInCycle - 1];
        ++cycleStepCount;
    }

    // STEP 3: FIND THE FIRST NODE OF THE CYCLE
    // start two pointers
    //   (1) at position n+1
    //   (2) ahead of position n+1 as many steps as the cycle's length
    unsigned int pointerStart = n + 1;
    unsigned int pointerAhead = n + 1;
    for (size_t i = 0; i < cycleStepCount; ++i) {
        pointerAhead = intVector[pointerAhead - 1];
    }

    // advance until the pointers are in the same position
    // which is the first node in the cycle
    while (pointerStart != pointerAhead) {
        pointerStart = intVector[pointerStart - 1];
        pointerAhead = intVector[pointerAhead - 1];
    }

    // since there are multiple values pointing to the first node
    // in the cycle, its position is a duplicate in our array
    return pointerStart;
}