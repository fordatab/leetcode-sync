class Solution {
public:
int countOperations(int num1, int num2) {
        int operation  = 0;                          //to store answer
        while(num1 && num2) {
            if (num1 >= num2)
				num1-=num2;         // As given in question we will decreasw the num1
            else{
                num2-=num1;         // As given in question we will decreasw the num2
            }
            operation++;                       //Increase operation
        }
        return operation;
    }
};