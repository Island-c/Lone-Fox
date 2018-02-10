#include "my_head.h"
#include "my_head.h"

double Bulk_quote::net_price(std::size_t n) const
{
	if (n <= quantity)
		return n*price*discount;
	else
	{
		return quantity*price*discount + (n - quantity)*price;
	}
}
