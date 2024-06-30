#ifndef UTILS_H
#define UTILS_H

#include <boost/math/distributions.hpp>
// #include <boost/math/distributions/normal.hpp>

double invNormalCDF(double p);
double getStrikeFromDelta(const double S, const double T, const double r, const double sigma, const double delta,
                          const char contractRight);
double normalCDF(double x);

class standardGaussian {
   private:
    boost::math::normal_distribution<double> dist;

   public:
    standardGaussian() : dist(0.0, 1.0) {};

    double quantile(const double &p) {
        return boost::math::quantile(dist, p);
    };

    double cdf(const double &x) {
        return boost::math::cdf(dist, x);
    };

    double pdf(const double &x) {
        return boost::math::pdf(dist, x);
    };
};

#endif  // UTILS_H