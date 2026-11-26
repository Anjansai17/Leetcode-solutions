class Solution {
    public int minEatingSpeed(int[] piles, int h) {
     int low = 1;
     int high = 0;

     for (int x : piles){
        high = Math.max(high,x);

     }   
     int ans = high;
     while(low <= high){
        int mid = low + (high - low)/2;

        long hours = 0;
        for (int x:piles){
            hours += (x+(long)mid-1)/mid;
        }
        if(hours <= h){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;

        }

     }
     return ans;
    }
}