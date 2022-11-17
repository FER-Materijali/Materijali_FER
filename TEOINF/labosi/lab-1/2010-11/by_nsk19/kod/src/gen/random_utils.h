/*
 * random_utils.h
 *
 *  Created on: Apr 22, 2010
 *      Author: Leo Osvald
 */

#ifndef RANDOM_UTILS_H_
#define RANDOM_UTILS_H_

#include <cstdlib>
#include <ctime>

#include <utility>
#include <vector>

class RandomUtils {
protected:
	template<typename T>
	static inline T random(unsigned* seed) {
		int bits = 12;
		T r = 0;
		 //-1 is intentional coz of unsigned and signed
		for(int i = sizeof(r)*8-1; i > 0; i -= bits) {
			if(i < bits)
				bits = i;
			r = (r<<bits) | (rand_r(seed) & ((1<<bits)-1));
		}
		return r;
	}

public:

	template<class T>
	class DiscreteRandomVariable {
	private:
		std::vector<int> sum_;
		std::vector<T> outcomes_;
		T not_found_val_;
		mutable unsigned* seed_;
		mutable unsigned seed_val_;
		static const short MAX_ABSOLUTE_PROBABILITY = 0x7fff;
	public:
		DiscreteRandomVariable(T not_found_val) : not_found_val_(not_found_val) {
			init();
		}

		DiscreteRandomVariable() : not_found_val_(-1) {
			init();
		}

		/**
		 * Vraca ishod koji je ostvaren.
		 */
		T get() const {
			if(sum_.empty())
				return not_found_val_;
			int totalSum = sum_.at(sum_.size()-1);
			if(totalSum <= 0)
				return not_found_val_;
			int target = random<int>(seed_) % totalSum;
			int lo = 0, hi = sum_.size()-1;
			while(lo < hi) {
				int mid = lo + (hi-lo-1)/2;
				if(target < sum_.at(mid))
					hi = mid;
				else
					lo = mid+1;
			}
			return outcomes_.at(lo);
		}

		void add(T outcome, double probability) {
			int s = absoluteProbability(probability)
						+ (!sum_.empty() ? sum_.at(sum_.size()-1) : 0);
			outcomes_.push_back(outcome);
			sum_.push_back(s);
		}

		void set_seed(unsigned seed) {
			seed_val_ = seed;
			seed_ = &seed_val_;
		}

	private:

		short absoluteProbability(double probability) const {
			if(probability < 0) return 0;
			if(probability >= 1) return MAX_ABSOLUTE_PROBABILITY;
			return (short) (probability * MAX_ABSOLUTE_PROBABILITY);
		}

		void init() {
			seed_val_ = (unsigned)time(NULL);
			seed_ = &seed_val_;
		}
	};

};

#endif /* RANDOM_UTILS_H_ */
