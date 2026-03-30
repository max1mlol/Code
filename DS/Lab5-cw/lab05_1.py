import pandas as pd

data = pd.read_csv('student_data.csv')

print("=== Head ===")
print(data.head())

print("\n=== Statistics ===")
mean_val = data['Оноо'].mean()
median_val = data['Оноо'].median()
std_val = data['Оноо'].std()
min_val = data['Оноо'].min()
max_val = data['Оноо'].max()
print("Mean:", mean_val)
print("Median:", median_val)
print("Std:", std_val)
print("Min:", min_val)
print("Max:", max_val)

def get_letter(Оноо):
    if Оноо >= 90:
        return 'A'
    elif Оноо >= 80:
        return 'B'
    elif Оноо >= 70:
        return 'C'
    elif Оноо >= 60:
        return 'D'
    else:
        return 'F'
data['Dun'] = data['Оноо'].apply(get_letter)

data['above_average'] = data['Оноо'] > mean_val

data['Dun_normalized'] = (
    (data['Оноо'] - min_val) / (max_val - min_val)
)