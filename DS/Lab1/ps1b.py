
annual_salary = float(input("Jiliin tsalingaa oruulna uu: "))
portion_saved = float(input("Tsalingaasaa hadgalah huvi (aravtiin butarhaigar): "))
total_cost = float(input("Muruudliin baishinginha uniig oruulna uu: "))
semi_annual_raise = float(input("Hagas jiliin tsalingiin usultuu(aravtiin butarhaigar): "))
r = 0.04
portion_down_payment = total_cost * 0.25
monthly_salary = annual_salary / 12
monthly_saved = monthly_salary * portion_saved
time_required = 0
current_savings = 0
while(current_savings < portion_down_payment):
    income_with_interest = current_savings * r/12
    current_savings += monthly_saved + income_with_interest
    time_required += 1
    if(time_required % 6 == 0):
        monthly_saved += semi_annual_raise * monthly_saved
print(f"Hurimtluulah shaardlagatai sar: ", time_required)