//
//  main.cpp
//  Exercise
//
//  Created by 杜少鹤 on 2021/12/1.
//  Copyright © 2021 杜少鹤. All rights reserved.
//

#include <iostream>

// input: incomeBeforTax per year
double calculateTax(float incomeBeforTax) {
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
// 默认3年内完成行权
void yearLimit(int total) {
    int year = 3;
    while (total >= 1000) {
        total = total * (1 - 0.25);
        year ++;
    }
    std::cout << "yearLimit is " << year + 1 << " last year shares is " << total <<std::endl;
}

int main(int argc, const char *argv[]) {
    float salaryPerMonth = 0;
    int shares = 0;
    float exercisePrice = 0;
    float currentSharePrice = 0;
    float exchangeRate = 0;

    std::cout << "input your salary: RMB/month" << std::endl;
    std::cin >> salaryPerMonth;
    std::cout << "input your number of shares: CDR" << std::endl;
    std::cin >> shares;
    std::cout << "input your exercisePrice: USD/CDR" << std::endl;
    std::cin >> exercisePrice;
    std::cout << "input your exchangeRate: RMB/USD" << std::endl;
    std::cin >> exchangeRate;
    std::cout << "input your currentSharePrice: RMB/CDR" << std::endl;
    std::cin >> currentSharePrice;
    exercisePrice = exercisePrice * exchangeRate;
    
    auto details = [=] (int num) {
        double totalSalary = salaryPerMonth * 12;
        std::cout << "your total salary is " << totalSalary << " RMB/year" << std::endl;
        double salaryAfterTax = calculateTax(totalSalary);
        std::cout << "your salary incomeAfterTax is " << salaryAfterTax << " RMB/year, " << "tax = " << 1 - salaryAfterTax/totalSalary << std::endl;
        double totalProfit = (currentSharePrice - exercisePrice) * num;
        std::cout << "your exercise totalProfit is " << totalProfit << " RMB" << std::endl;
        double totalIncome = totalSalary + totalProfit;
        std::cout << "your totalIncome is " << totalIncome << " RMB" << std::endl;
        double incomeAfterTax = calculateTax(totalIncome);
        std::cout << "your incomeAfterTax is " << incomeAfterTax << " RMB, " << "tax = " << 1 - incomeAfterTax/totalIncome << std::endl;
        double shareTaxCost = (totalIncome - incomeAfterTax) - (totalSalary - salaryAfterTax);
        std::cout << "your shareTaxCost is " << shareTaxCost << " RMB, " << "tax = " << shareTaxCost/totalProfit << std::endl;
        double costperCDR = (shareTaxCost / num) + exercisePrice;
        std::cout << "your costperCDR is " << costperCDR << " RMB" << std::endl;
    };
    std::cout << ".................一次行完................." << std::endl;
    details(shares);
    
    int recommendShares = (660000 - salaryPerMonth * 12) / (currentSharePrice - exercisePrice);
    std::cout << "recommendShares is " << recommendShares << std::endl;
    std::cout << ".................控税30%，推荐数量................." << std::endl;
    details(recommendShares);
    std::cout << ".................平均3年行完................." << std::endl;
    yearLimit(shares);
    details(shares/3);
    std::cout << ".................平均4年行完................." << std::endl;
    details(shares/4);
    std::cout << ".................平均6年行完................." << std::endl;
    details(shares/6);
    return 0;
}
