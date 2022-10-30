int powmod(long long x,int n,const int mod)
{	
    x%=mod;
    if(x==0)
    return 0;
    long long res=1;
    while(n)
    {
      if(n&1)
      res=res*x%mod;
      n/=2;
      x=x*x%mod;
    }
    if(res<0)
    res+=mod;
    return res;
}
