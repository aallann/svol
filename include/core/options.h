#ifndef OPTIONS_H
#define OPTIONS_H

#include <memory>
#include <vector>

class Option {
   public:
    double K;      // contract strike
    double T;      // contract time to maturity
    double omega;  // {put, call}{-1, 1} flags

    Option(double K, double T, double omega) : K(K), T(T), omega(omega) {};
    virtual ~Option() = default;
};

class EuropeanOption : public Option {
   public:
    EuropeanOption(double K, double T, double omega) : Option(K, T, omega) {};
    ~EuropeanOption() override = default;

    void setID(int id) {
        this->id = id;
    };

    void setStrikes(const std::vector<double> &_strikes) {
        *strikes = _strikes;
    };

    void setMaturities(const std::vector<double> &_maturities) {
        *maturities = _maturities;
    };

    void setPrice(double price) {
        this->price = price;
    };

    unsigned getID() {
        return id;
    };

    double getPrice() {
        return price;
    };

   private:
    static const std::unique_ptr<std::vector<double>> strikes;
    static const std::unique_ptr<std::vector<double>> maturities;
    unsigned id;
    double price;
};

// TODO implement class level (static member) control of contract states

#endif  // OPTIONS_H