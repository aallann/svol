#ifndef MODELS_H
#define MODELS_H

#include <core/options.h>
#include <core/utils.h>

class BlackScholes {
   public:
    BlackScholes(double r, double sigma, double q) : r(r), sigma(sigma), q(q) {};
    ~BlackScholes() = default;

    double strikeFromDelta(const EuropeanOption &option, const double S) {};

    double impVol(const EuropeanOption &option, const double S) {};

   private:
    double r, sigma, q;
};

class Heston {
   public:
    Heston(double kappa, double vbar, double sigma, double rho, double v0) {};
    ~Heston() = default;

    double price(const EuropeanOption &option, const double S) {};

   private:
    double kappa, vbar, sigma, rho, v0;
};

#endif  // MODELS_H