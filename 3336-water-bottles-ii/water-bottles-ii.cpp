class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
      int totalDrunk = 0;
        int emptyBottles = 0;
        int currentExchange = numExchange;
        
        while (numBottles > 0) {
            totalDrunk++;
            numBottles--;
            emptyBottles++;
            while (emptyBottles >= currentExchange) {
                emptyBottles -= currentExchange;
                numBottles++;
                currentExchange++;
            }
        }
        
        return totalDrunk;
    }
};