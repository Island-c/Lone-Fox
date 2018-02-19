#include "_DebugDelete.h"
template<typename T,typename D=DebugDelete> class Unique;
template<typename T> void swap(Unique<T> &p1, Unique<T>&p2);

template<typename T,typename D=DebugDelete> class Unique
{
public://���캯���Ϳ�����������Ԫ
	friend void swap(Unique<T> &p1, Unique<T>&p2);
	Unique() :data(nullptr) {}
	explicit Unique(T *p) :data(p) {}
	Unique(const Unique&) = delete;
	Unique& operator=(const Unique&) = delete;
	Unique(Unique &&p) :data(p.data) noexcept { p.data = nullptr; }
	Unique& operator=(Unique && p);
	~Unique() { delete data; }
public:
	T& operator *() const { return *data; }
	T* operator -> () const { return &this->operator*(); }

private:
	T *data;
	D deleter = DebugDelete();
};

template<typename T> void swap(Unique<T>&p1, Unique<T> &p2)
{
	using std::swap;
	swap(p1.data, p2.data);
}

template<typename T, typename D = DebugDelete>
Unique<T,D> &Unique<T,D>::operator=(Unique && p)
{
	if (this->data != p.data)
	{
		deleter(data); //ɾ����
		::swap(*this, p);//?

	}
	return *this;

}
