#include <stdio.h>
#include <stdint.h>

/*The idea of the solution is to get the maximum profit that can be made from buying at time X and selling at time Y (Y > X).
The time complexity of the solution is O(N), and the space complexity is constant.

The basic concept is this. We will start assuming that we buy the first day, and then the buying day will just change if the price that
day is cheaper than the previous buying day, but this is not the only condition. The other condition is that there is a selling day in the future
that gives more profit than the maximum profit already found. For this purpose we keep track of the maximum profit so far and the minimum price day
so far. Like this we can be sure that we buy at the right time and that we might change the sellingday also when the maximum profit is found
*/

/*32 bits are needed to fit the desired range of values*/
uint32_t solution(uint32_t A[], uint32_t size)
{
    if(size < 2){
	/*no profit to be made*/
	return 0;
    }
    /*First speculation but at day 0 sell at day 1*/
    uint32_t buyday  = 0;
    uint32_t sellday = 1;
     
    /*Init auxiliar variables*/
    /*keep track of the day with the minim price for the stock*/
    uint32_t buydayCandidate = 0;
    /*the profit can be negative, thus needint a signed 32 bit integer (enough for the range as well)*/
    int32_t MaxProfit = (int32_t) (A[sellday] - A[buyday]);
    uint32_t day;
     
    for (day = 1; day < size; day++) {
        if (A[day] < A[buyday]) {
            buydayCandidate = day;
	}
        
        int32_t Profit = (int32_t) (A[day] - A[buydayCandidate]);
         
        if (Profit > MaxProfit) {

            buyday = buydayCandidate;
            sellday = day;
            MaxProfit = (int32_t) (A[sellday] - A[buyday]);
        }
    }

    if(MaxProfit > 0){
        printf("The maximum profit is %i, by buying on day %i and selling on day %i \n",MaxProfit,buyday,sellday);
    }else {
        printf("No profit posible \n");
    }

    return (MaxProfit > 0) ? (uint32_t)MaxProfit : 0;
}
 
int main(void)
{
    uint32_t A[] = {23171, 21011, 21123, 21366, 21013, 21367};
     
    uint32_t benefit = solution(A, 6);
    printf("benefit %i \n",benefit);
 
    return 0;
}
