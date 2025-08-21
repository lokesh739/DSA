class Solution {
    public int countArrangement(int n) {
        boolean[] used=new boolean[n+1];
        return countarrangement(1,used,n);
    }
    private int countarrangement(int pos,boolean[] used,int n){
        if(pos>n){
            return 1;
        }
        int count=0;
        for(int i=1;i<=n;i++){
            if(!used[i] && (i%pos==0 || pos%i==0)){
                used[i]=true;
                count+=countarrangement(pos+1,used,n);
                used[i]=false;
            }
        }
        return count;
    }
}