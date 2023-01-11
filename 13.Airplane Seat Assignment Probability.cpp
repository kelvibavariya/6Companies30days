/*13.Airplane Seat Assignment Probability
n passengers board an airplane with exactly n seats. The first passenger has
lost the ticket and picks a seat randomly. But after that, the rest of the
passengers will:
Take their own seat if it is still available, and
Pick other seats randomly when they find their seat occupied
Return the probability that the nth person gets his own seat.*/

/*f(n) = (1/n) + (1/n) * [f(n-1) + f(n-2) + f(n-3) + … + f(2)]
f(1) =1  (n==1)
f(n) = 1/2  (n>=2)
*/
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1)return 1;
        else return 0.5;
    }
};
