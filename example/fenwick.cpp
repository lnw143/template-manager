/**
 * @name FenwickTree
 * @prefix fenw
*/

template<int N,class T>
struct Fenwick {
	T s[N + 2],t[N + 2];
	void _add(int x,T k) {
		for(int i=x; i<=N; i+=i&-i) s[i]+=k,t[i]+=x*k;
	}
	T _sum(int x) {
		T r=0;
		for(int i=x; i; i&=i-1) r+=s[i];
		r*=x+1;
		for(int i=x; i; i&=i-1) r-=t[i];
		return r;
	}
	void add(int l,int r,T k) { _add(l,k),_add(r+1,-k); }
	void add(int x,T k) { _add(x,k),_add(x+1,-k); }
	T sum(int l,int r) { return _sum(r)-_sum(l-1); }
	T sum(int x) { return _sum(x)-_sum(x-1); }
	void clean(int n) {
		memset(s+1,0,sizeof(T)*n);
		memset(t+1,0,sizeof(T)*n);
	}
	Fenwick() {
		memset(s,0,sizeof(s));
		memset(t,0,sizeof(t));
	}
};
