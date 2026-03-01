annual_salary = float(input("Ehleh jiliin tsalingaa oruulna uu: "))
semi_annual_raise = .07
r = .04
total_cost = 1000000
time_required = 36
down_payment = total_cost*0.25
def total_saved(interest):
    current_savings = 0
    monthly_salary = annual_salary /12
    for i in range(1, 37):
        current_savings += current_savings * r/12
        current_savings += monthly_salary * interest

        if i%6 == 0:
            monthly_salary += monthly_salary * semi_annual_raise 
    return current_savings

if total_saved(1.0) < down_payment:
    print("Gurvan jiliin dotor uridchilgaa tulbur tsugluulah bolomjgui")
else:
    low = 0
    high = 10000
    steps = 0
    min = 0
    while low <= high:
        steps += 1
        mid = (low+high) // 2 # // ni buhel utga butsaana
        interest = mid / 10000
        savings = total_saved(interest)
        if savings  >= down_payment:
            min = interest
            high = mid - 1
        else:
            low = mid + 1
    print("Tsalingaasaa hadgalah tohiromjtoi huvi: ", min)
    print("Hoyortin hailtiin alham: ", steps)
    