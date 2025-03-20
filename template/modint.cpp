/**
 * @name ModInterger
 * @prefix modint
*/

template<int P> struct ModInt {
	static_assert(0<P&&P<(1u<<31));
private:
	typedef unsigned int u32;
	typedef unsigned long long u64;
	u32 x;
	typedef ModInt MI;
public:
	MI operator+(const MI &y) const { return x+y.x>=P?x+y.x-P:x+y.x; }
	MI operator-(const MI &y) const { return x<y.x?x+P-y.x:x-y.x; }
	MI operator*(const MI &y) const { return u64(x)*y.x; }
	MI& operator+=(const MI &y) { if((x+=y.x)>=P) x-=P; return *this; }
	MI& operator-=(const MI &y) { if(x<y.x) x+=P-y.x; else x-=y.x; return *this; }
	MI& operator*=(const MI &y) { x=u64(x)*y.x%P; return *this; }
	int val() const { return x; }
	u32& get() { return x; }
	ModInt(): x(0) {}
	ModInt(u32 y):x(y) {}
	ModInt(u64 y):x(y%P) {}
	ModInt(int y): x(y%P+P) { if(x>=P) x-=P; }
	ModInt(long long y): x(y%P+P) { if(x>=P) x-=P; }
};
template<int P> ModInt<P> pow(ModInt<P> a,long long n) {
	ModInt<P> x=1u;
	for(; n; n>>=1,a=a*a) if(n&1) x=x*a;
	return x;
}

using mint = ModInt<${1|998244353,1e9 + 7|}>;
