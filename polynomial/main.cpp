#include "bits/stdc++.h"
#include "Polynomial.h"

int main() {
    Polynomial polynomial1, polynomial2;
    polynomial1.initLink();
    polynomial2.initLink();
    std::cout << polynomial1 + polynomial2;
    return 0;
}