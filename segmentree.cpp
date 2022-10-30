template<typename T>
class segment_tree
{	
	public:
	vector<T>seg;
	
	void init(int n)
	{
		seg.resize(4*n);
	}
	
	T combine(T a, T b)//combine as desired
	{
		return max(a,b);
	}
	void build(int low,int high,int in,vi &a)
	{
		if(low>high)
		return;
		
		if(low==high)
		{	
			seg[in]=a[low];
			return;
		}
		
		int mid = ( low + high ) / 2;
		build(low, mid, 2*in, a);
		build(mid+1, high, 2*in+1, a);
		
		seg[in] = combine(seg[2*in], seg[2*in+1]);
		return;
	}
	
	void update(int low,int high,int in,int pos,int val)
	{
		if(high<pos||low>pos)
		return;
		
		if(low==high)
		{		
			seg[in]=val;
			return;
		}
		
		int mid = (low + high) / 2;
		update(low, mid, 2*in, pos, val);
		update(mid+1, high, 2*in+1, pos, val);
		
		seg[in] = combine(seg[2*in], seg[2*in+1]);
		return;
	}
	
	T query(int low,int high,int in,int l,int r)
	{
		if(high<l||low>r)
		return 0;//return irrelevant for combination//need not be 0 ofcourse
		
		if(low>=l && high<=r)
		return seg[in];
		
		int mid = (low + high) / 2;
		T left_ans  = query(low, mid, 2*in, l, r);
		T right_ans = query(mid+1, high, 2*in+1, l, r);
		
		return combine(left_ans,right_ans); ;	
	}
};
