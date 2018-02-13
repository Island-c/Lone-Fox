
template <typename I, typename T>
I my_find( I begin,  I end,const T &value)
{
	while (begin != end && *begin != value)
		++begin;
	return begin;
}

template <typename T, size_t N>
void print( const T(&a)[N])
{
	auto iter = begin(a);
	for (iter; iter != end(a); ++iter)
		cout << *iter << " ";
	cout << endl;
}

template<typename T,size_t N>
const T* my_begin(const T (&a)[N])
{
	//return a;
	return &a[0];
}

template <typename T,size_t N>
const T* my_end(const T(&a)[N])
{
	return a + N-1;
	//return &a[0]+N-1; //这里参考书答案有误。正确写法应该再-1。
}

template<typename T, size_t N>
constexpr size_t my_size(const T(&a)[N])
{
	return N;
}