//
//  main.cpp
//  Exercise
//
//  Created by 杜少鹤 on 2021/12/1.
//  Copyright © 2021 杜少鹤. All rights reserved.
//

#include <iostream>

double calculateTax(double incomeBeforTax);

int main(int argc, const char *argv[]) {
    float salaryPerMonth = 0;
    float shares = 0;
    float exercisePrice = 0;
    float currentSharePrice = 0;
    std::cout << "input your salary: RMB/month" << std::endl;
    std::cin >> salaryPerMonth;
    std::cout << "input your number of shares: CDR" << std::endl;
    std::cin >> shares;
    std::cout << "input your exercisePrice: RMB/CDR" << std::endl;
    std::cin >> exercisePrice;
    std::cout << "input your currentSharePrice: RMB/CDR" << std::endl;
    std::cin >> currentSharePrice;
    double totalSalary = salaryPerMonth * 12;
    std::cout << "your total salary is " << totalSalary << " RMB/year" << std::endl;
    double salaryAfterTax = calculateTax(totalSalary);
    std::cout << "your salary incomeAfterTax is " << salaryAfterTax << " RMB/year" << std::endl;
    double totalProfit = (currentSharePrice - exercisePrice) * shares;
    std::cout << "your exercise totalProfit is " << totalProfit << " RMB" << std::endl;
    double totalIncome = totalSalary + totalProfit;
    std::cout << "your totalIncome is " << totalIncome << " RMB" << std::endl;
    double incomeAfterTax = calculateTax(totalIncome);
    std::cout << "your incomeAfterTax is " << incomeAfterTax << " RMB" << std::endl;
    double profitCost = (totalIncome - incomeAfterTax) - (totalSalary - salaryAfterTax);
    std::cout << "your profitCost is " << profitCost << " RMB" << std::endl;
    std::cout << "your profitCost per CDR is " << profitCost/shares << " RMB" << std::endl;
    return 0;
}

// input: incomeBeforTax per year
double calculateTax(double incomeBeforTax) {
    double tax1 = 36000 * 0.03;
    double tax2 = (144000 - 36000) * 0.1;
    double tax3 = (300000 - 144000) * 0.2;
    double tax4 = (420000 - 300000) * 0.25;
    double tax5 = (660000 - 420000) * 0.3;
    double tax6 = (960000 - 660000) * 0.35;
    if (0 <= incomeBeforTax && incomeBeforTax <= 36000) {
        return incomeBeforTax- incomeBeforTax * 0.03;
    } else if (36000 < incomeBeforTax && incomeBeforTax <= 144000) {
        return incomeBeforTax - tax1 - (incomeBeforTax - 36000) * 0.1;
    } else if (144000 < incomeBeforTax && incomeBeforTax <= 300000) {
        return incomeBeforTax - tax1 - tax2 - (incomeBeforTax - 144000) * 0.2;
    } else if (300000 < incomeBeforTax && incomeBeforTax <= 420000) {
        return incomeBeforTax - tax1 - tax2 - tax3 - (incomeBeforTax - 300000) * 0.25;
    } else if (420000 < incomeBeforTax && incomeBeforTax <= 660000) {
        return incomeBeforTax - tax1 - tax2 - tax3 - tax4 - (incomeBeforTax - 420000) * 0.3;
    } else if (660000 < incomeBeforTax && incomeBeforTax <= 960000) {
        return incomeBeforTax - tax1 - tax2 - tax3 - tax4 - tax5 - (incomeBeforTax - 660000) * 0.35;
    } else if (incomeBeforTax > 960000) {
        return incomeBeforTax - tax1 - tax2 - tax3 - tax4 - tax5 - tax6 - (incomeBeforTax - 960000) * 0.45;
    }
    return 0;
}
