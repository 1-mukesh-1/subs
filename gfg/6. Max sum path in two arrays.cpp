class Solution{
    public:
    int max_path_sum(int arr1[], int arr2[], int n, int m)
    {
        int summ1=0;
        int summ2=0;
        int summ=0;
        int i=0,j=0;
        while(i<n && j<m){
            if(arr1[i]==arr2[j]){
                summ+=max(summ1,summ2);
                summ+=arr1[i];
                summ1=0;
                summ2=0;
                i+=1;
                j+=1;
                continue;
            }
            if(arr1[i]<arr2[j]){
                summ1+=arr1[i];
                i+=1;
            }
            else{
                summ2+=arr2[j];
                j+=1;
            }
        }
        while(i<n) summ1+=arr1[i++];
        while(j<m) summ2+=arr2[j++];
        summ+=max(summ1,summ2);
        return summ;
    }
};
