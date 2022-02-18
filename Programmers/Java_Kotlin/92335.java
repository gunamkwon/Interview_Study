class Solution {
    public int solution(int n, int k) {
        int answer = 0;
        String number = new String();
        while(n>=1){
            number = Integer.toString(n % k) + number;
            n/=k;
        }

        System.out.println(number);
        String[] nums = number.split("0");
        for(int i=0;i<nums.length;i++){
            if(!nums[i].equals("")){
                System.out.println(nums[i]);
                if(isPrime(Long.parseLong(nums[i])))
                    answer++;
            }

        }
        return answer;
    }

    boolean isPrime(long num)
    {
        if(num==1) return false;
        if(num==2) return true;

        int limit = (int) Math.sqrt(num);
        for(int i=2;i<=limit;i++) {
            if(num%i==0) return false;
        }
        return true;
    }
}