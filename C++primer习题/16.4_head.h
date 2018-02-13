
template <typename I, typename T>
I my_find(const I &begin, const I &end,const T &value)
{
	I beg = begin;
	for (beg; beg != end; ++beg)
	{
		if (*beg == value)
			return beg;
	}
	return end;

}