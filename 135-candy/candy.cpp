class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum=0;
        int i=1;
        int n=ratings.size();
        sum=1;
        while(i<n){
            if(i>=1 && ratings[i]==ratings[i-1]){
                sum+=1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1]){
                sum+=down;
                i++;
                down++;
            }
            if(down>peak)
            sum+=(down-peak);
        }
        return sum;
    }
};