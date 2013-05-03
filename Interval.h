#ifndef _INTERVAL_H_
#define _INTERVAL_H_

#include <random>
#include <utility>

namespace teh {

namespace ps {

template <typename T>
struct Interval {
	typedef std::pair<T, T> param_type;
	/* An Interval is essentially a pair with extra capabilities */
	const T min, max;
	Interval(const T &a, const T &b) : min(a), max(b) { }
	explicit Interval(const param_type &p) : min(p.first), max(p.second) { }
	/* Provide information about the pool and results */
	/*
	double entropy() const {
		return device.entropy();
	}
	*/
	//virtual void reseed(double) = 0; // TODO template instead?
	virtual T nextRandom() = 0;
	/* Remove default construction */
	Interval() = delete;
	Interval(const Interval<T> &) = default;
	Interval(Interval<T> &&) = default;
	Interval<T> &operator=(const Interval<T> &) = default;
	Interval<T> &operator=(Interval<T> &&) = default;
protected:
	//std::random_device device;
};

struct RealInterval : public Interval<double> {
	RealInterval(double a, double b) :
		Interval(a, b), distribution(a, b) { }
	explicit RealInterval(const param_type &p) :
		RealInterval(p.first, p.second) { }
	/* Remove default construction */
	RealInterval() = delete;
	RealInterval(const RealInterval &) = default;
	RealInterval(RealInterval &&) = default;
	RealInterval &operator=(const RealInterval &) = default;
	RealInterval &operator=(RealInterval &&) = default;
	/* Some important functionality */
	void reseed(double seed) {
		generator.seed(seed);
	}
	double nextRandom() {
		return distribution(generator);
	}
private:
	//static std::random_device device;
	//typedef std::mersenne_twister_engine<double> RNG;
	typedef std::mt19937 RNG; RNG generator;
	//static std::default_random_engine generator(device);
	// TODO initialize the RNG with random device?
	std::uniform_real_distribution<> distribution;
};

} // namespace ps

} // namespace teh

#endif // _INTERVAL_H_
