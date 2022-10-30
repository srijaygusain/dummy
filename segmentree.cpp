template<typename T>
class segment_tree
{	
	public:
	vector<T>seg;
	int N;
	segment_tree(int n)
	{
		N=n;
		seg.resize(4*n);
	}
	
	T combine(T a, T b)//combine as desired
	{
		return a+b;
	}
	void build(vi &a,int low=0,int high=N-1,int in=1)
	{
		if(low>high)
		return;
		
		if(low==high)
		{	
			seg[in]=a[low];
			return;
		}
		
		int mid = ( low + high ) / 2;
		build(a,low, mid, 2*in);
		build(a,mid+1, high, 2*in+1);
		
		seg[in] = combine(seg[2*in], seg[2*in+1]);
		return;
	}
	
	void update(int pos,int val,int low=0,int high=N-1,int in=1)
	{
		if(high<pos||low>pos)
		return;
		
		if(low==high)
		{		
			seg[in]=val;
			return;
		}
		
		int mid = (low + high) / 2;
		update(pos, val, low, mid, 2*in);
		update(pos, val, mid+1, high, 2*in+1);
		
		seg[in] = combine(seg[2*in], seg[2*in+1]);
		return;
	}
	
	T query(int l,int r,int low=0,int high=N-1,int in=1)
	{
		if(high<l||low>r)
		return 0;//return irrelevant for combination//need not be 0 ofcourse
		
		if(low>=l && high<=r)
		return seg[in];
		
		int mid = (low + high) / 2;
		T left_ans  = query(l, r, low, mid, 2*in);
		T right_ans = query(l, r, mid+1, high, 2*in+1);
		
		return combine(left_ans,right_ans); ;	
	}
};