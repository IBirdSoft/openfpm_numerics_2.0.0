/*
 * vector_dist_operators_unit_tests.hpp
 *
 *  Created on: Jun 11, 2016
 *      Author: i-bird
 */

#ifndef OPENFPM_NUMERICS_SRC_OPERATORS_VECTOR_VECTOR_DIST_OPERATORS_UNIT_TESTS_HPP_
#define OPENFPM_NUMERICS_SRC_OPERATORS_VECTOR_VECTOR_DIST_OPERATORS_UNIT_TESTS_HPP_

#include "Operators/Vector/vector_dist_operators.hpp"

constexpr int A = 0;
constexpr int B = 1;
constexpr int C = 2;

constexpr int VA = 3;
constexpr int VB = 4;
constexpr int VC = 5;

constexpr int TA = 6;

//////////////////// Here we define all the function to checl the operators

template <unsigned int prp, typename vector> bool check_values(vector & v,float a)
{
	bool ret = true;
	auto it = v.getDomainIterator();

	while (it.isNext())
	{
		ret &= v.template getProp<prp>(it.get()) == a;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}

template <typename vector> bool check_values_complex_expr(vector & vd)
{
	bool ret = true;
	auto it = vd.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		float base1 = vd.template getProp<B>(key) + 2.0 + vd.template getProp<B>(key) - 2.0*vd.template getProp<C>(key) / 5.0;
		float base2 = vd.template getProp<A>(key);

		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}

template <typename rtype, typename vector, unsigned int A, unsigned int B, unsigned int C> bool check_values_sum(vector & vd, double d)
{
	bool ret = true;
	auto it = vd.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		rtype base1 = vd.template getProp<B>(key) + d;
		rtype base2 = vd.template getProp<A>(key);

		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}

template <typename rtype, typename vector, unsigned int A, unsigned int B, unsigned int C> bool check_values_sum(vector & vd1, vector & vd2)
{
	bool ret = true;
	auto it = vd1.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		rtype base1 = vd1.template getProp<B>(key) + vd2.template getProp<C>(key);
		rtype base2 = vd1.template getProp<A>(key);

		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}

template <typename rtype, typename vector, unsigned int A, unsigned int B, unsigned int C> bool check_values_sum_3(vector & vd1)
{
	bool ret = true;
	auto it = vd1.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		rtype base1 = vd1.template getProp<B>(key) + vd1.template getProp<C>(key) + vd1.template getProp<B>(key);
		rtype base2 = vd1.template getProp<A>(key);

		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}

template <typename rtype, typename vector, unsigned int A, unsigned int B, unsigned int C> bool check_values_sum_4(vector & vd1)
{
	bool ret = true;
	auto it = vd1.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		rtype base1 = (vd1.template getProp<B>(key) + vd1.template getProp<C>(key)) + (vd1.template getProp<B>(key) + vd1.template getProp<C>(key));
		rtype base2 = vd1.template getProp<A>(key);


		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}

template <typename rtype, typename vector, unsigned int A, unsigned int B, unsigned int C> bool check_values_sub(vector & vd, double d)
{
	bool ret = true;
	auto it = vd.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		rtype base1 = vd.template getProp<B>(key) - d;
		rtype base2 = vd.template getProp<A>(key);

		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}

template <typename rtype, typename vector, unsigned int A, unsigned int B, unsigned int C> bool check_values_sub(double d, vector & vd)
{
	bool ret = true;
	auto it = vd.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		rtype base1 = d - vd.template getProp<B>(key);
		rtype base2 = vd.template getProp<A>(key);

		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}

template <typename rtype, typename vector, unsigned int A, unsigned int B, unsigned int C> bool check_values_sub(vector & vd1, vector & vd2)
{
	bool ret = true;
	auto it = vd1.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		rtype base1 = vd1.template getProp<C>(key) - vd2.template getProp<B>(key);
		rtype base2 = vd1.template getProp<A>(key);

		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}

template <typename rtype, typename vector, unsigned int A, unsigned int B, unsigned int C> bool check_values_sub_31(vector & vd1)
{
	bool ret = true;
	auto it = vd1.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		rtype base1 = vd1.template getProp<B>(key) - (vd1.template getProp<C>(key) + vd1.template getProp<B>(key));
		rtype base2 = vd1.template getProp<A>(key);

		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}


template <typename rtype, typename vector, unsigned int A, unsigned int B, unsigned int C> bool check_values_sub_32(vector & vd1)
{
	bool ret = true;
	auto it = vd1.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		rtype base1 = (vd1.template getProp<C>(key) + vd1.template getProp<B>(key)) - vd1.template getProp<B>(key);
		rtype base2 = vd1.template getProp<A>(key);

		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}

template <typename rtype, typename vector, unsigned int A, unsigned int B, unsigned int C> bool check_values_sub_4(vector & vd1)
{
	bool ret = true;
	auto it = vd1.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		rtype base1 = (vd1.template getProp<C>(key) + vd1.template getProp<B>(key)) - (vd1.template getProp<C>(key) + vd1.template getProp<B>(key));
		rtype base2 = vd1.template getProp<A>(key);

		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}


template <typename rtype, typename vector, unsigned int A, unsigned int B, unsigned int C> bool check_values_mul(vector & vd, double d)
{
	bool ret = true;
	auto it = vd.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		rtype base1 = vd.template getProp<B>(key) * d;
		rtype base2 = vd.template getProp<A>(key);

		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}


template <typename rtype, typename vector, unsigned int A, unsigned int B, unsigned int C> bool check_values_mul(vector & vd1, vector & vd2)
{
	bool ret = true;
	auto it = vd1.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		rtype base1 = vd1.template getProp<C>(key) * vd2.template getProp<B>(key);
		rtype base2 = vd1.template getProp<A>(key);

		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}

template <typename rtype, typename vector, unsigned int A, unsigned int B, unsigned int C> bool check_values_mul_3(vector & vd1)
{
	bool ret = true;
	auto it = vd1.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		rtype base1 = vd1.template getProp<B>(key) * (vd1.template getProp<B>(key) + vd1.template getProp<C>(key));
		rtype base2 = vd1.template getProp<A>(key);

		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}


template <typename rtype, typename vector, unsigned int A, unsigned int B, unsigned int C> bool check_values_mul_4(vector & vd1)
{
	bool ret = true;
	auto it = vd1.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		rtype base1 = (vd1.template getProp<B>(key) + vd1.template getProp<C>(key)) * (vd1.template getProp<B>(key) + vd1.template getProp<C>(key));
		rtype base2 = vd1.template getProp<A>(key);

		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}



template <typename rtype, typename vector, unsigned int A, unsigned int B, unsigned int C> bool check_values_div(vector & vd, double d)
{
	bool ret = true;
	auto it = vd.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		rtype base1 = vd.template getProp<B>(key) / d;
		rtype base2 = vd.template getProp<A>(key);

		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}

template <typename rtype, typename vector, unsigned int A, unsigned int B, unsigned int C> bool check_values_div(double d, vector & vd)
{
	bool ret = true;
	auto it = vd.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		rtype base1 = d / vd.template getProp<B>(key);
		rtype base2 = vd.template getProp<A>(key);

		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}

template <typename rtype, typename vector, unsigned int A, unsigned int B, unsigned int C> bool check_values_div(vector & vd1, vector & vd2)
{
	bool ret = true;
	auto it = vd1.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		rtype base1 = vd1.template getProp<C>(key) / vd2.template getProp<B>(key);
		rtype base2 = vd1.template getProp<A>(key);

		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}

template <typename rtype, typename vector, unsigned int A, unsigned int B, unsigned int C> bool check_values_div_31(vector & vd1)
{
	bool ret = true;
	auto it = vd1.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		rtype base1 = vd1.template getProp<B>(key) / (vd1.template getProp<B>(key) + vd1.template getProp<C>(key));
		rtype base2 = vd1.template getProp<A>(key);

		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}

template <typename rtype, typename vector, unsigned int A, unsigned int B, unsigned int C> bool check_values_div_32(vector & vd1)
{
	bool ret = true;
	auto it = vd1.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		rtype base1 = (vd1.template getProp<C>(key) + vd1.template getProp<B>(key)) / vd1.template getProp<B>(key);
		rtype base2 = vd1.template getProp<A>(key);

		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}


template <typename rtype, typename vector, unsigned int A, unsigned int B, unsigned int C> bool check_values_div_4(vector & vd1)
{
	bool ret = true;
	auto it = vd1.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		rtype base1 = (vd1.template getProp<B>(key) + vd1.template getProp<C>(key)) / (vd1.template getProp<B>(key) + vd1.template getProp<C>(key));
		rtype base2 = vd1.template getProp<A>(key);

		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}

template <typename vector> bool check_values_scal_norm_dist(vector & vd)
{
	bool ret = true;
	auto it = vd.getDomainIterator();

	while (it.isNext())
	{
		auto key = it.get();

		float base1 = vd.template getProp<VB>(key) * vd.template getProp<VC>(key) + norm(vd.template getProp<VC>(key) + vd.template getProp<VB>(key)) + distance(vd.template getProp<VC>(key),vd.template getProp<VB>(key));
		float base2 = vd.template getProp<A>(key);

		ret &=  base1 == base2;

		++it;
	}

	BOOST_REQUIRE_EQUAL(ret,true);

	return ret;
}

template <typename vector> void fill_values(vector & v)
{
	auto it = v.getDomainIterator();

	while (it.isNext())
	{
		auto p = it.get();

		v.getPos(p)[0] = (float)rand() / RAND_MAX;
		v.getPos(p)[1] = (float)rand() / RAND_MAX;
		v.getPos(p)[2] = (float)rand() / RAND_MAX;

		v.template getProp<A>(p) = fabs(sin(p.getKey()+1));
		v.template getProp<B>(p) = fabs(sin(2.0*p.getKey()+3));
		v.template getProp<C>(p) = fabs(sin(3.0*p.getKey()+18));

		for (size_t k = 0 ; k < 3 ; k++)
		{
			v.template getProp<VA>(p)[k] = fabs(sin(p.getKey()+1+k));
			v.template getProp<VB>(p)[k] = fabs(sin(2.0*p.getKey()+1+3));
			v.template getProp<VC>(p)[k] = fabs(sin(3.0*p.getKey()+1+k));
		}

		++it;
	}
}

typedef vector_dist<3,float,aggregate<float,float,float,VectorS<3,float>,VectorS<3,float>,VectorS<3,float>>> vector_type;

//! Exponential kernel
struct exp_kernel
{
	float var;

	exp_kernel(float var)
	:var(var)
	{}

	inline float value(const Point<3,float> & p, const Point<3,float> & q,float pA,float pB)
	{
		float dist = norm(p-q);

		return (pA + pB) * exp(dist * dist / var);
	}

	inline Point<3,float> value(const Point<3,float> & p, const Point<3,float> & q,const Point<3,float> & pA, const Point<3,float> & pB)
	{
		float dist = norm(p-q);

		return (pA + pB) * exp(dist * dist / var);
	}

	inline Point<3,float> value(vector_type & vd1, vector_type & vd2, size_t p, size_t q, float pA, float pB)
	{
		float dist = norm(p-q);

		return (pA + pB) * exp(dist * dist / var);
	}
};

////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE( vector_dist_test )


BOOST_AUTO_TEST_CASE( vector_dist_operators_test )
{
	if (create_vcluster().getProcessingUnits() > 3)
		return;

	Box<3,float> box({0.0,0.0,0.0},{1.0,1.0,1.0});

	// Boundary conditions
	size_t bc[3]={PERIODIC,PERIODIC,PERIODIC};

	// ghost
	Ghost<3,float> ghost(0.05);

	// vector type
	typedef vector_dist<3,float,aggregate<float,float,float,VectorS<3,float>,VectorS<3,float>,VectorS<3,float>>> vtype;

	vector_dist<3,float,aggregate<float,float,float,VectorS<3,float>,VectorS<3,float>,VectorS<3,float>>> vd(100,box,bc,ghost);

	auto vA = getV<A>(vd);
	auto vB = getV<B>(vd);
	auto vC = getV<C>(vd);

	auto vVA = getV<VA>(vd);
	auto vVB = getV<VB>(vd);
	auto vVC = getV<VC>(vd);

	vA = 1.0;
	vB = 2.0f;
	vC = 3.0;

	check_values<A>(vd,1.0);
	check_values<B>(vd,2.0);
	check_values<C>(vd,3.0);

	fill_values(vd);

	vA = vB + 2.0 + vB - 2.0*vC / 5.0;
	check_values_complex_expr(vd);

	// Various combination of 2 operator

	vA = vB + 2.0;
	check_values_sum<float,vtype,A,B,C>(vd,2.0);
	vA = 2.0 + vB;
	check_values_sum<float,vtype,A,B,C>(vd,2.0);
	vA = vC + vB;
	check_values_sum<float,vtype,A,B,C>(vd,vd);

	vA = vB - 2.0;
	check_values_sub<float,vtype,A,B,C>(vd,2.0);
	vA = 2.0 - vB;
	check_values_sub<float,vtype,A,B,C>(2.0,vd);
	vA = vC - vB;
	check_values_sub<float,vtype,A,B,C>(vd,vd);

	vA = vB * 2.0;
	check_values_mul<float,vtype,A,B,C>(vd,2.0);
	vA = 2.0 * vB;
	check_values_mul<float,vtype,A,B,C>(vd,2.0);
	vA = vC * vB;
	check_values_mul<float,vtype,A,B,C>(vd,vd);

	vA = vB / 2.0;
	check_values_div<float,vtype,A,B,C>(vd,2.0);
	vA = 2.0 / vB;
	check_values_div<float,vtype,A,B,C>(2.0,vd);
	vA = vC / vB;
	check_values_div<float,vtype,A,B,C>(vd,vd);

	// Variuos combination 3 operator

	vA = vB + (vC + vB);
	check_values_sum_3<float,vtype,A,B,C>(vd);
	vA = (vC + vB) + vB;
	check_values_sum_3<float,vtype,A,B,C>(vd);
	vA = (vC + vB) + (vC + vB);
	check_values_sum_4<float,vtype,A,B,C>(vd);

	vA = vB - (vC + vB);
	check_values_sub_31<float,vtype,A,B,C>(vd);
	vA = (vC + vB) - vB;
	check_values_sub_32<float,vtype,A,B,C>(vd);
	vA = (vC + vB) - (vC + vB);
	check_values_sub_4<float,vtype,A,B,C>(vd);

	vA = vB * (vC + vB);
	check_values_mul_3<float,vtype,A,B,C>(vd);
	vA = (vC + vB) * vB;
	check_values_mul_3<float,vtype,A,B,C>(vd);
	vA = (vC + vB) * (vC + vB);
	check_values_mul_4<float,vtype,A,B,C>(vd);

	vA = vB / (vC + vB);
	check_values_div_31<float,vtype,A,B,C>(vd);
	vA = (vC + vB) / vB;
	check_values_div_32<float,vtype,A,B,C>(vd);
	vA = (vC + vB) / (vC + vB);
	check_values_div_4<float,vtype,A,B,C>(vd);

	// We try with vectors

	// Various combination of 2 operator

	vVA = vVB + 2.0f;
	check_values_sum<VectorS<3,float>,vtype,VA,VB,VC>(vd,2.0f);
	vVA = 2.0f + vVB;
	check_values_sum<VectorS<3,float>,vtype,VA,VB,VC>(vd,2.0f);
	vVA = vVC + vVB;
	check_values_sum<VectorS<3,float>,vtype,VA,VB,VC>(vd,vd);

	vVA = vVB - 2.0f;
	check_values_sub<VectorS<3,float>,vtype,VA,VB,VC>(vd,2.0f);
	vVA = 2.0f - vVB;
	check_values_sub<VectorS<3,float>,vtype,VA,VB,VC>(2.0f,vd);
	vVA = vVC - vVB;
	check_values_sub<VectorS<3,float>,vtype,VA,VB,VC>(vd,vd);

	vVA = vVB * 2.0f;
	check_values_mul<VectorS<3,float>,vtype,VA,VB,VC>(vd,2.0f);
	vVA = 2.0f * vVB;
	check_values_mul<VectorS<3,float>,vtype,VA,VB,VC>(vd,2.0f);
	vVA = vVC * vVB;
	check_values_mul<VectorS<3,float>,vtype,VA,VB,VC>(vd,vd);

	vVA = vVB / 2.0f;
	check_values_div<VectorS<3,float>,vtype,VA,VB,VC>(vd,2.0f);
	vVA = 2.0f / vVB;
	check_values_div<VectorS<3,float>,vtype,VA,VB,VC>(2.0f,vd);
	vVA = vVC / vVB;
	check_values_div<VectorS<3,float>,vtype,VA,VB,VC>(vd,vd);

	// Variuos combination 3 operator

	vVA = vVB + (vVC + vVB);
	check_values_sum_3<VectorS<3,float>,vtype,VA,VB,VC>(vd);
	vVA = (vVC + vVB) + vVB;
	check_values_sum_3<VectorS<3,float>,vtype,VA,VB,VC>(vd);
	vVA = (vVC + vVB) + (vVC + vVB);
	check_values_sum_4<VectorS<3,float>,vtype,VA,VB,VC>(vd);

	vVA = vVB - (vVC + vVB);
	check_values_sub_31<VectorS<3,float>,vtype,VA,VB,VC>(vd);
	vVA = (vVC + vVB) - vVB;
	check_values_sub_32<VectorS<3,float>,vtype,VA,VB,VC>(vd);
	vVA = (vVC + vVB) - (vVC + vVB);
	check_values_sub_4<VectorS<3,float>,vtype,VA,VB,VC>(vd);

	vVA = vVB * (vVC + vVB);
	check_values_mul_3<VectorS<3,float>,vtype,VA,VB,VC>(vd);
	vVA = (vVC + vVB) * vVB;
	check_values_mul_3<VectorS<3,float>,vtype,VA,VB,VC>(vd);
	vVA = (vVC + vVB) * (vVC + vVB);
	check_values_mul_4<VectorS<3,float>,vtype,VA,VB,VC>(vd);
	vA = vVB * (vVC + vVB);
	check_values_mul_3<float,vtype,A,VB,VC>(vd);
	vA = (vVC + vVB) * vVB;
	check_values_mul_3<float,vtype,A,VB,VC>(vd);
	vA = (vVC + vVB) * (vVC + vVB);
	check_values_mul_4<float,vtype,A,VB,VC>(vd);

	vVA = vVB / (vVC + vVB);
	check_values_div_31<VectorS<3,float>,vtype,VA,VB,VC>(vd);
	vVA = (vVC + vVB) / vVB;
	check_values_div_32<VectorS<3,float>,vtype,VA,VB,VC>(vd);
	vVA = (vVC + vVB) / (vVC + vVB);
	check_values_div_4<VectorS<3,float>,vtype,VA,VB,VC>(vd);

	// normalization function

	vA = vVB * vVC + norm(vVC + vVB) + distance(vVC,vVB);
	check_values_scal_norm_dist(vd);
}

#include "vector_dist_operators_apply_kernel_unit_tests.hpp"

BOOST_AUTO_TEST_SUITE_END()


#endif /* OPENFPM_NUMERICS_SRC_OPERATORS_VECTOR_VECTOR_DIST_OPERATORS_UNIT_TESTS_HPP_ */
