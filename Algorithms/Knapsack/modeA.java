/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithmsexercise2;



import java.util.Map;


/**
 *
 * @author MANOS
 */
public class modeA {
    /*this algorithm have been taken from the internet and especially from this site https://github.com/mission-peace/interview/blob/master/src/com/interview/dynamic/CoinChangingMinimumCoin.java
    i have also add lines with my code in order to adjust it and work in order to implement mode A*/ 

     /**
     * Top down dynamic programing. Using map to store intermediate results.
     * Returns Integer.MAX_VALUE if total cannot be formed with given coins
     * @param total
     * @param coins
     * @param map
     * @return 
     */
    
   
    public int minimumCoinTopDown(int total, int coins[], Map<Integer, Integer> map) {

        //if total is 0 then there is nothing to do. return 0.
        if ( total == 0 ) {
            return 0;
        }

        //if map contains the result means we calculated it before. Lets return that value.
        if ( map.containsKey(total) ) {
            return map.get(total);
        }

        //iterate through all coins and see which one gives best result.
        int min = Integer.MAX_VALUE;
        for ( int c=0; c < coins.length; c++ ) {
            //if value of coin is greater than total we are looking for just continue.
            if( coins[c] > total ) {
                continue;
            }
            //recurse with total - coins[i] as new total
            int val = minimumCoinTopDown(total - coins[c], coins, map);

            //if val we get from picking coins[i] as first coin for current total is less
            // than value found so far make it minimum.
            if( val < min ) {
                min = val;
            }
        }

        //if min is MAX_VAL dont change it. Just result it as is. Otherwise add 1 to it.
        min =  (min == Integer.MAX_VALUE ? min : min + 1);

        //memoize the minimum for current total.
        map.put(total, min);
        return min;
    }

    /**
     * Bottom up way of solving this problem.
     * Keep input sorted. Otherwise temp[j-arr[i]) + 1 can become Integer.Max_value + 1 which
     * can be very low negative number
     * Returns Integer.MAX_VALUE - 1 if solution is not possible.
     * @param total
     * @param coins
     * @return 
     */
    public int minimumCoinBottomUp(int total, int coins[]){
        int T[] = new int[total + 1];
        int R[] = new int[total + 1];
        T[0] = 0;
        for(int k=1; k <= total; k++){
            T[k] = Integer.MAX_VALUE-1;
            R[k] = -1;
        }
        for(int j=0; j < coins.length; j++){
            for(int p=1; p <= total; p++){
                if(p >= coins[j]){
                    if (T[p - coins[j]] + 1 < T[p]) {
                        T[p] = 1 + T[p - coins[j]];
                        R[p] = j;
                    }
                }
            }
        }
        printCoinCombination(R, coins);
        return T[total];
    }
    int i = 1;
    private void printCoinCombination(int R[], int coins[]) {
        int one=0;//initialize the number of vms client needs
        int two=0;
        int seven=0;
        int eleven=0;
        if (R[R.length - 1] == -1) {
            System.out.print("No solution is possible");
            return;
        }
        int start = R.length - 1;
        while ( start != 0 ) {//until the end of the vms or clients
            int j = R[start];
            if(coins[j]==1){//check if client need a 1 vms set  and bottom follows the same procedure
                one++;
            }
            if(coins[j]==2){//the same fro 2,7,11
                two++;
            }
            if(coins[j]==7){
                seven++;
            }
            if(coins[j]==11){
                eleven++;
            }
            start = start - coins[j];
        }//print
        System.out.print("Client "+i+": "+one+" 1-core, "+two+" 2-core, "+seven+" 7-core and  "+eleven+" 11-core VMs ");
        i++;
        System.out.print("\n");
    }
}
