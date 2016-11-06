/*
 ============================================================================
 Name           : Loan Calculator
 Author         : John Huang
 Version        : V 1.0
 Creation       : Nov. 6 2016
 Last Update    : Nov. 6 2016
 Copyright      : GNU BY NC
 Description    : Loan Calculator than can calculate monthly loan payment.
 ============================================================================
 */

#include <stdio.h>
#include <math.h>

#define Loan__Payment(amount, discount) amount/discount
#define PAY_PER_YR 12
#undef DEBUG
#define DEBUG 0

float getDiscount(int, float);



int main(){
    float annual_rate, loan_total_pay, monthly_pay, extra_pay, discnt, amount, years;
    
    printf("Please enter Loan Amount, Years and Interest rate. Use space to separate them. \n");
    scanf("%f %f %f", &amount, &years, &annual_rate);
    
    discnt = getDiscount(years, annual_rate);
    monthly_pay = Loan__Payment(amount, discnt);
    loan_total_pay = monthly_pay * PAY_PER_YR * years;
    extra_pay = loan_total_pay - amount;
    
    printf("Monthly payment is: %.2f. \nTotal payback is: %.2f\nExtra pay to the loan is: %.2f\n"
           , monthly_pay, loan_total_pay, extra_pay);
    
    return 0;
}


/*********************************************************/
/* Formula to get the discount:                          */
/* n: number of payments per year                        */
/* i = (annual rate / 100 ) / 12                         */
/* discount = [(1 + i)^n - 1] / [i * (1 + i)^n]          */
/*********************************************************/
float getDiscount(int years, float annual_rate) {
    float dis, rate;
    int num_of_pay;
    
    num_of_pay = (int)(PAY_PER_YR * years);
    rate = (annual_rate/100.0)/PAY_PER_YR;
    
    dis = ((pow((1 + rate), num_of_pay) - 1) /
           (rate * pow(1 + rate, num_of_pay)));
    
    if (DEBUG) printf("monthly rate is :%f\n, discount is: %f\n", rate, dis);
    
    return dis;
}
