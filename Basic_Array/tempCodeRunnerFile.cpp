long long sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    long long total=n*(n+1)/2;
    long long missing= total-sum;