import pandas as pd

# Read the file into a DataFrame
df = pd.read_csv("weather_data.txt")
data_new = pd.read_csv("weather_data.txt")

# a. What day(s) had the highest actual precipitation?
highest_precip_days = df[df["actual_precipitation"] == df["actual_precipitation"].max()]["date"]

# Convert the date column to a datetime object
df['date'] = pd.to_datetime(df['date'])

print("#3A: The day(s) with the highest actual precipitation:")
print(highest_precip_days)
print()

# b. What was the average actual max temp for July 2014?
july_2014 = df[(df["date"].dt.year == 2014) & (df["date"].dt.month == 7)]
avg_temp = july_2014["average_max_temp"].mean()

print("#3B: The average actual max temp for July 2014:")
print(avg_temp)
print()

# c. What days was the actual max temp the record max temp?
print("#3C: The day(s) with the actual max temp the same as the record max temp:")
for i in range(len(data_new)):
    data_new['date'] = pd.to_datetime(data_new['date']).dt.date
    if(data_new.iloc[i]["actual_max_temp"] == data_new.iloc[i]["record_max_temp"]):
        print(data_new.iloc[i]["date"])
print()

# d. How much did it rain in October 2014?
october_2014 = df[(df["date"].dt.year == 2014) & (df["date"].dt.month == 10)]
total_rain = october_2014["actual_precipitation"].sum()

print("#3D: Total rainfall in October 2014:")
print(total_rain)
print()

# e. What day(s), if any, was the actual low temperature below 60 degrees and actual max temperature above 90 degrees on the same day?
for i in range(len(df)):
    if(df.iloc[i]["actual_min_temp"] < 60 and df.iloc[i]["actual_max_temp"] > 90):
        print("3E: The day(s) with actual low temp below 60 degrees and actual max temp above 90 degrees:")
        print(df.iloc[i]["date"])
print("3E: None of those days exist.")