# total_cost - bairnii une
# portion_down_payment \= 0.25 - uridchilgaa tulburt shaardlagatai hemjee
# current_savings = 0; - odoogiin hemjee (0-s ehelne)
# annual_salary - jiliin tsalin
# portion_saved - sar bur tsalingasa uridchilgaand uguh

annual_salary = float(input("Jiliin tsalingaa oruulna uu: "))
portion_saved = float(input("Tsalingaasaa hadgalah huvi (aravtiin butarhaigar): "))
total_cost = float(input("Muruudliin baishinginha uniig oruulna uu: "))
r = 0.04
portion_down_payment = total_cost * 0.25
monthly_salary = annual_salary / 12
monthly_saved = monthly_salary * portion_saved
time_required = 0
current_savings = 0
while(current_savings < portion_down_payment):
    time_required += 1
    income_with_interest = current_savings * r/12
    current_savings += monthly_saved + income_with_interest

print(f"Hurimtluulah shaardlagatai sar: ", time_required)