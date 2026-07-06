int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
{
    int totalTank = 0;
    int currentTank = 0;
    int start = 0;

    for(int i = 0; i < gasSize; i++)
    {
        int diff = gas[i] - cost[i];

        totalTank += diff;
        currentTank += diff;

        if(currentTank < 0)
        {
            start = i + 1;
            currentTank = 0;
        }
    }

    if(totalTank >= 0)
        return start;

    return -1;
}